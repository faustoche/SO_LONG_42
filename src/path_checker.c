/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:58:59 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/12 14:09:35 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(t_data *data, t_point p)
{
	static int	*visited = NULL;

	if (!visited)
		init_visited_path(&visited, data->map_width, data->map_height);
	if (!within_boundaries(data, p) || data->map[p.y][p.x] == '1'
		|| visited[p.y * data->map_width + p.x])
		return ;
	visited[p.y * data->map_width + p.x] = 1;
	update_access(data, p);
	flood_fill_check(data, p);
}

void	init_visited_path(int **visited, int width, int height)
{
	int	i;

	*visited = malloc(sizeof(int) * (height * width));
	if (!*visited)
	{
		ft_printf("Error\n");
		return ;
	}
	i = 0;
	while (i < height * width)
	{
		(*visited)[i] = 0;
		i++;
	}
}

int	within_boundaries(t_data *data, t_point p)
{
	return (p.x >= 0 && p.y >= 0 && p.x < data->map_width
		&& p.y < data->map_height);
}

void	update_access(t_data *data, t_point p)
{
	if (data->map[p.y][p.x] == EXIT)
		data->exit_access = 1;
	else if (data->map[p.y][p.x] == COLLECT)
		data->collect_access++;
	else if (data->map[p.y][p.x] != START)
		data->map[p.y][p.x] = 'V';
}

void	flood_fill_check(t_data *data, t_point p)
{
	check_path(data, (t_point){p.x, p.y - 1});
	check_path(data, (t_point){p.x, p.y + 1});
	check_path(data, (t_point){p.x - 1, p.y});
	check_path(data, (t_point){p.x + 1, p.y});
}
