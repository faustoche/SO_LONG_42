/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:57:06 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/12 15:32:19 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Open the file and allocate the map. */

int	open_and_allocate_map(t_data *data)
{
	int	fd;

	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nCan't open the map.");
		return (1);
	}
	data->map = (char **)malloc(data->map_height * sizeof(char *));
	if (!data->map)
	{
		handle_close(data);
		close(fd);
		return (1);
	}
	return (fd);
}

int	allocate_and_copy_line(t_data *data, char *line, t_map *grid)
{
	int	x;

	data->map[grid->y] = (char *)malloc((data->map_width + 1) * sizeof(char));
	if (!data->map[grid->y])
	{
		handle_close(data);
		free(data->map[grid->y]);
		return (1);
	}
	if (map_size(data) < 0)
	{
		ft_printf("Error\nMap is out of screen limits\n");
		exit(EXIT_FAILURE);
	}
	x = 0;
	while (x < data->map_width)
	{
		data->map[grid->y][x] = line[x];
		x++;
	}
	data->map[grid->y][data->map_width] = '\0';
	return (0);
}

/* Fill the tiles according to the map. */

void	till_filling(t_data *data, int fd)
{
	char	*line;
	t_map	pos;

	pos.y = 0;
	line = get_next_line(fd);
	while (line)
	{
		pos.x = 0;
		while (line[pos.x])
		{
			data->map[pos.y][pos.x] = line[pos.x];
			pos.x++;
		}
		free(line);
		pos.y++;
		line = get_next_line(fd);
	}
	close(fd);
}

int	map_size(t_data *data)
{
	if (data->map_width >= 20 || data->map_height >= 11)
		return (-1);
	return (0);
}