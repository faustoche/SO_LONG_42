/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemies_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:03:33 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/12 15:16:08 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collision(t_data *data)
{
	if (data->player_x == data->enemy_x && data->player_y == data->enemy_y)
		return (1);
	return (0);
}

void	init_enemy(t_data *data)
{
	int	height;
	int	width;

	data->img_enemy = mlx_xpm_file_to_image(data->mlx_ptr,
			"Textures/ENEMY/enemy1.xpm", &width, &height);
	if (!data->img_enemy)
		handle_close(data);
}

void	hit_by_enemy(t_data *data)
{
	ft_printf("Oh no, you got hit by a meteor...");
	handle_close(data);
}
