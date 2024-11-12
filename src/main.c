/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:57:04 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/12 15:23:28 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arguments(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error\nOnly one argument needed\n");
		exit(EXIT_FAILURE);
	}
	if (check_extension(av[1]) != 0)
		exit(EXIT_FAILURE);
}

void	init_map_path(t_map *map, char *path)
{
	map->path = ft_strdup(path);
	if (!map->path)
	{
		ft_printf("Error\nFailed of memory allocation\n");
		exit(EXIT_FAILURE);
	}
}

void	parse_map(t_map *map)
{
	if (map_parsing(map) != 0)
	{
		free(map->path);
		exit(EXIT_FAILURE);
	}
}

void	init_data_map(t_data *data, t_map *map)
{
	data->map_path = map->path;
	data->map_width = map->width;
	data->map_height = map->height;
	if (grid_init(data) != 0)
	{
		free(map->path);
		exit(EXIT_FAILURE);
	}
}

void	find_player_position(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == START)
			{
				data->player_x = x;
				data->player_y = y;
				return;
			}
			x++;
		}
		y++;
	}
}

void	verify_paths(t_data *data)
{
	int	items_total;

	items_total = check_items(data);
	data->exit_access = 0;
	data->collect_access = 0;
	check_path(data, (t_point){data->player_x, data->player_y});
	if (data->exit_access == 0 || data->collect_access < items_total)
	{
		ft_printf("Error\nCannot access to exit or items.\n");
		handle_close(data);
		exit(EXIT_FAILURE);
	}
}

void	init_window_and_run(t_data *data)
{
	if (open_window(data) != 0)
	{
		free(data->map_path);
		handle_close(data);
		exit(EXIT_FAILURE);
	}
	init_images(data);
	init_enemy(data);
	put_image(data);
	mlx_key_hook(data->win_ptr, handle_input, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, close_win, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, handle_close, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	check_arguments(ac, av);
	init_map_path(&map, av[1]);
	parse_map(&map);
	init_data_map(&data, &map);
	find_player_position(&data);
	verify_paths(&data);
	init_window_and_run(&data);
	cleanup(&data);
	return (EXIT_SUCCESS);
}
