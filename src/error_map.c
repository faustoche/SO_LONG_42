/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:40:10 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/12 10:53:41 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check if there is any error concerning the map. */

void	map_error(t_data *data, int fd)
{
	int	i;

	i = 0;
	if (data && data->map)
	{
		while (i < data->map_height)
		{
			free(data->map[i]);
			data->map[i] = NULL;
			i++;
		}
		free(data->map);
		data->map = NULL;
	}
	if (fd >= 0)
		close(fd);
	exit (EXIT_FAILURE);
}

/* Close the file in case of problem. */

int	close_file(int fd)
{
	if (fd >= 0)
		close(fd);
	return (0);
}
