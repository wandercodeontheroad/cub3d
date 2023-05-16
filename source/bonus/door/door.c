/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:54:19 by zstenger          #+#    #+#             */
/*   Updated: 2023/05/16 08:13:05 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	switch_door(t_map *map, t_mlx_data *mlx_data)
{
	if (is_closed_door_here(map) == true)
	{
		system("afplay ./resource/portal.mp3 &");
		return ;
	}
	else if (is_open_door_here(map) == true)
	{
		system("afplay ./resource/portal.mp3 &");
		mlx_data->door = mlx_load_png("resource/bhole.png");
		if (mlx_data->door == NULL)
			p_err(BAD_DOOR);
	}
}

bool	is_closed_door_here(t_map *m)
{
	if (m->matrix[(int)m->map_y][(int)m->map_x] == 'D')
		return (m->matrix[(int)m->map_y][(int)m->map_x] = 'd', true);
	else if (m->matrix[(int)m->map_y + 1][(int)m->map_x + 1] == 'D')
		return (m->matrix[(int)m->map_y + 1][(int)m->map_x + 1] = 'd', true);
	else if (m->matrix[(int)m->map_y][(int)m->map_x + 1] == 'D')
		return (m->matrix[(int)m->map_y][(int)m->map_x + 1] = 'd', true);
	else if (m->matrix[(int)m->map_y + 1][(int)m->map_x] == 'D')
		return (m->matrix[(int)m->map_y + 1][(int)m->map_x] = 'd', true);
	else if (m->matrix[(int)m->map_y][(int)m->map_x - 1] == 'D')
		return (m->matrix[(int)m->map_y][(int)m->map_x - 1] = 'd', true);
	else if (m->matrix[(int)m->map_y - 1][(int)m->map_x] == 'D')
		return (m->matrix[(int)m->map_y - 1][(int)m->map_x] = 'd', true);
	else if (m->matrix[(int)m->map_y - 1][(int)m->map_x - 1] == 'D')
		return (m->matrix[(int)m->map_y - 1][(int)m->map_x - 1] = 'd', true);
	else if (m->matrix[(int)m->map_y - 1][(int)m->map_x + 1] == 'D')
		return (m->matrix[(int)m->map_y - 1][(int)m->map_x + 1] = 'd', true);
	else if (m->matrix[(int)m->map_y + 1][(int)m->map_x - 1] == 'D')
		return (m->matrix[(int)m->map_y + 1][(int)m->map_x - 1] = 'd', true);
	return (false);
}

bool	is_open_door_here(t_map *m)
{
	if (m->matrix[(int)m->map_y][(int)m->map_x] == 'd')
		return (m->matrix[(int)m->map_y][(int)m->map_x] = 'D', true);
	else if (m->matrix[(int)m->map_y + 1][(int)m->map_x + 1] == 'd')
		return (m->matrix[(int)m->map_y + 1][(int)m->map_x + 1] = 'D', true);
	else if (m->matrix[(int)m->map_y][(int)m->map_x + 1] == 'd')
		return (m->matrix[(int)m->map_y][(int)m->map_x + 1] = 'D', true);
	else if (m->matrix[(int)m->map_y + 1][(int)m->map_x] == 'd')
		return (m->matrix[(int)m->map_y + 1][(int)m->map_x] = 'D', true);
	else if (m->matrix[(int)m->map_y][(int)m->map_x - 1] == 'd')
		return (m->matrix[(int)m->map_y][(int)m->map_x - 1] = 'D', true);
	else if (m->matrix[(int)m->map_y - 1][(int)m->map_x] == 'd')
		return (m->matrix[(int)m->map_y - 1][(int)m->map_x] = 'D', true);
	else if (m->matrix[(int)m->map_y - 1][(int)m->map_x - 1] == 'd')
		return (m->matrix[(int)m->map_y - 1][(int)m->map_x - 1] = 'D', true);
	else if (m->matrix[(int)m->map_y - 1][(int)m->map_x + 1] == 'D')
		return (m->matrix[(int)m->map_y - 1][(int)m->map_x + 1] = 'd', true);
	else if (m->matrix[(int)m->map_y + 1][(int)m->map_x - 1] == 'D')
		return (m->matrix[(int)m->map_y + 1][(int)m->map_x - 1] = 'd', true);
	return (false);
}
