/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:10:10 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/12 15:15:15 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allocation_error(t_data *data)
{
	ft_printf("Error\nMemory allocation");
	if (data->map)
	{
		free(data->map);
		data->map = NULL;
	}
	handle_close(data);
	exit (EXIT_FAILURE);
}

void	cleanup(t_data *data)
{
	if (data->img_collect)
		mlx_destroy_image(data->mlx_ptr, data->img_collect);
	if (data->img_floor)
		mlx_destroy_image(data->mlx_ptr, data->img_floor);
	if (data->img_wall)
		mlx_destroy_image(data->mlx_ptr, data->img_wall);
	if (data->img_exit)
		mlx_destroy_image(data->mlx_ptr, data->img_exit);
	if (data->img_player_back)
		mlx_destroy_image(data->mlx_ptr, data->img_player_back);
	if (data->img_player_face)
		mlx_destroy_image(data->mlx_ptr, data->img_player_face);
	if (data->img_player_left)
		mlx_destroy_image(data->mlx_ptr, data->img_player_left);
	if (data->img_player_right)
		mlx_destroy_image(data->mlx_ptr, data->img_player_right);
	if (data->img_enemy)
		mlx_destroy_image(data->mlx_ptr, data->img_enemy);
	mlx_destroy_display(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->map);
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
	exit(EXIT_SUCCESS);
}


void	print_error(void)
{
	ft_printf("Error\n");
	exit (EXIT_FAILURE);
}

