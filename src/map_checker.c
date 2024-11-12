/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:00:58 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/12 08:39:58 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Open the map file. */

int	open_map_file(t_map *map)
{
	int	fd;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nMap doesn't exist.\n");
		return (-1);
	}
	return (fd);
}

/* Free the lines */

int	free_lines(int fd, char *line)
{
	ft_printf("Error\n");
	free(line);
	close(fd);
	return (-1);
}

/* Check for the first line. */

int	read_and_validate_first_line(int fd, t_map *map)
{
	char	*line;
	size_t	i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (handle_empty_file(fd));
	map->width = (int)ft_strlen(line);
	if (map->width > 0 && line[map->width - 1] == '\n')
		map->width--;
	while (i < map->width)
	{
		if (line[i] != '1')
		{
			ft_printf("Error\n");
			free(line);
			close(fd);
			return (-1);
		}
		i++;
	}
	map->height = 1;
	free(line);
	return (0);
}

int	handle_empty_file(int fd)
{
	close(fd);
	ft_printf("Error\nFile is empty.\n");
	return (-1);
}

/* Check the other lines. */

int	check_other_lines(int fd, t_map *map)
{
	char	*line;
	size_t	line_length;
	size_t	i;

	i = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_length = ft_strlen(line);
		if (line_length > 0 && line[line_length - 1] == '\n')
			line_length--;
		if (line_length != (size_t)map->width)
			free(line);
		if (line[0] != '1' || line[line_length - 1] != '1')
			free(line);
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
