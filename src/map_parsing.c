/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:40:34 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/12 13:59:42 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check if the map is valid. */

int	is_valide(t_map *map)
{
	if (map->height == 0 || map->width == 0)
	{
		ft_printf("Error\nMap is empty.\n");
		return (-1);
	}
	return (0);
}

/* Parse the map. */

int	map_parsing(t_map *map)
{
	int		fd;

	fd = open_map_file(map);
	if (fd < 0)
		return (-1);
	if (read_and_validate_first_line(fd, map) < 0)
		return (-1);
	if (check_other_lines(fd, map) < 0)
		return (-1);
	if (is_valide(map) < 0)
		return (-1);
	close(fd);
	fd = open_map_file(map);
	if (fd < 0)
		return (-1);
	if (check_map_symbols(fd) < 0)
		return (-1);
	close(fd);
	return (0);
}

int	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
	{
		ft_printf("Error: Invalid file name.\n");
		return (1);
	}
	if (ft_strcmp(filename + len - 4, ".ber") != 0)
	{
		ft_printf("Error: File extension must be .ber\n");
		return (1);
	}
	return (0);
}

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	
	while(s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strdup(const char *s)
{
	char	*src;
	int		len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	src = (char *) malloc(sizeof(char) * (len + 1));
	if (!src)
	{
		return (NULL);
	}
	src[len] = '\0';
	while (len >= 0)
	{
		src[len] = s[len];
		len--;
	}
	return (src);
}