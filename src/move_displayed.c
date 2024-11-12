/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_displayed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:57:03 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/12 15:17:26 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Display end message in shell. */

void	congrats_end(t_data *data)
{
	int	new_y;
	int	new_x;

	new_x = data->player_x;
	new_y = data->player_y;
	if (data->map[new_y + 1][new_x] == EXIT && (check_items(data) == 0))
	{
		ft_printf("CONGRATS ! You did it");
		handle_close(data);
	}
	else if (data->map[new_y - 1][new_x] == EXIT && (check_items(data) == 0))
	{
		ft_printf("CONGRATS ! You did it");
		handle_close(data);
	}
	else if (data->map[new_y][new_x + 1] == EXIT && (check_items(data) == 0))
	{
		ft_printf("CONGRATS ! You did it");
		handle_close(data);
	}
	else if (data->map[new_y][new_x - 1] == EXIT && (check_items(data) == 0))
	{
		ft_printf("CONGRATS ! You did it");
		handle_close(data);
	}
}

/* Check the items, if there are some left, etc. */

int	check_items(t_data *data)
{
	int	i;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y < data->map_height)
	{
		i = 0;
		while (i < data->map_width)
		{
			if (data->map[y][i] == 'C')
				count++;
			i++;
		}
		y++;
	}
	return (count);
}
