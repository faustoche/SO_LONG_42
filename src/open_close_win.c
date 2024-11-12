/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:47:30 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/12 15:17:37 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Open the window. */

int	open_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "so_long");
	if (!data->win_ptr)
	{
		handle_close(data);
	}
	return (0);
}

/* Close and kill the window. */

int	handle_close(t_data *data)
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
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->map);
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
	exit(EXIT_SUCCESS);
	return (0);
}

/* Close the window with escape. */

int	close_win(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		handle_close(data);
	return (0);
}
