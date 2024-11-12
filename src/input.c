/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:27:03 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/12 10:57:54 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Move the character up. */

void	up(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x;
	new_y = data->player_y;
	if (new_y - 1 < 0)
		return ;
	if (data->map[new_y - 1][new_x] == ENEMY)
		hit_by_enemy(data);
	else if ((new_y - 1) >= 0 && data->map[new_y - 1][new_x] != WALL
		&& (new_y - 1) >= 0 && data->map[new_y - 1][new_x] != EXIT)
	{
		data->map[new_y][new_x] = FLOOR;
		data->map[new_y - 1][new_x] = START;
		data->player_y = new_y - 1;
		data->count++;
		data->player_current_image = data->img_player_back;
	}
	else
		congrats_end(data);
}

/* Move the character down. */

void	down(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x;
	new_y = data->player_y;
	if (new_y + 1 < 0)
		return ;
	if (data->map[new_y + 1][new_x] == ENEMY)
		hit_by_enemy(data);
	else if ((new_y + 1) < data->map_height
		&& data->map[new_y + 1][new_x] != WALL && (new_y + 1) < data->map_height
		&& data->map[new_y + 1][new_x] != EXIT)
	{
		data->map[new_y][new_x] = FLOOR;
		data->map[new_y + 1][new_x] = START;
		data->player_y = new_y + 1;
		data->count++;
		data->player_current_image = data->img_player_face;
	}
	else
		congrats_end(data);
}

/* Move the character on the left. */

void	left(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x;
	new_y = data->player_y;
	if (new_x - 1 < 0)
		return ;
	if (data->map[new_y][new_x - 1] == ENEMY)
		hit_by_enemy(data);
	else if ((new_x - 1) >= 0 && data->map[new_y][new_x - 1] != WALL
		&& (new_x - 1) >= 0 && data->map[new_y][new_x - 1] != EXIT)
	{
		data->map[new_y][new_x] = FLOOR;
		data->map[new_y][new_x - 1] = START;
		data->player_x = new_x - 1;
		data->count++;
		data->player_current_image = data->img_player_left;
	}
	else
		congrats_end(data);
}

/* Move the character on the right. */

void	right(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x;
	new_y = data->player_y;
	if (new_x + 1 < 0)
		return ;
	if (data->map[new_y][new_x + 1] == ENEMY)
		hit_by_enemy(data);
	else if ((new_x + 1) < data->map_width
		&& data->map[new_y][new_x + 1] != WALL && (new_x + 1) < data->map_width
		&& data->map[new_y][new_x + 1] != EXIT)
	{
		data->map[new_y][new_x] = FLOOR;
		data->map[new_y][new_x + 1] = START;
		data->player_x = new_x + 1;
		data->count++;
		data->player_current_image = data->img_player_right;
	}
	else
		congrats_end(data);
}

/* Handle keys according to what's pressed. */

int	handle_input(int key, t_data *data)
{
	if (key == XK_W || key == XK_w || key == XK_Up)
		up(data);
	else if (key == XK_A || key == XK_a || key == XK_Left)
		left(data);
	else if (key == XK_S || key == XK_s || key == XK_Down)
		down(data);
	else if (key == XK_D || key == XK_d || key == XK_Right)
		right(data);
	else
		return (0);
	//ft_printf("Number of moves : %d\n", data->count);
	put_image(data);
	return (0);
}
