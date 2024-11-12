/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:48:14 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/12 15:38:17 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Initiate the grid. */

void	map_filling(t_map *grid)
{
	grid->x = 0;
	grid->y = 0;
}

/* Allocate the line to fill and free in case of problems. */

void	allocate_line(t_data *data, t_map pos)
{
	data->map[pos.y] = (char *)malloc((data->map_width + 1) * sizeof(char));
	if (!data->map[pos.y])
	{
		free(data->map[pos.y]);
		data->map[pos.y] = NULL;
	}
	handle_close(data);
	exit (EXIT_FAILURE);
}

/* Read the file, and copies every symbol into map tab. */

int	read_line_grid(int fd, t_data *data)
{
	char	*line;
	t_map	grid;

	grid.y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (allocate_and_copy_line(data, line, &grid) != 0)
		{
			free(line);
			close(fd);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
		grid.y++;
	}
	return (0);
}

/* Initiate the map and fill the grid with map info. */

int	grid_init(t_data *data)
{
	int	fd;

	fd = open_and_allocate_map(data);
	if (fd < 0)
	{
		close(fd);
		return (-1);
	}
	if (read_line_grid(fd, data) < 0)
	{
		free(data);
		close_file(fd);
		return (1);
	}
	close_file(fd);
	return (0);
}
