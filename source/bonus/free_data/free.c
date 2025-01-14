/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:04:44 by zstenger          #+#    #+#             */
/*   Updated: 2023/05/19 14:42:54 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	free_mlx_data(t_data *data, t_mlx_data *mlx_data)
{
	free(mlx_data->no);
	free(mlx_data->so);
	free(mlx_data->we);
	free(mlx_data->ea);
	mlx_delete_texture(mlx_data->t_no);
	mlx_delete_texture(mlx_data->t_so);
	mlx_delete_texture(mlx_data->t_we);
	mlx_delete_texture(mlx_data->t_ea);
	mlx_delete_texture(mlx_data->door);
	mlx_delete_texture(data->minimap->fc.tex);
	mlx_delete_texture(data->minimap->fc.tex2);
	mlx_delete_texture(data->minimap->sprite.textures[0]);
	mlx_delete_texture(data->minimap->sprite.textures[1]);
	mlx_delete_texture(data->minimap->sprite.textures[2]);
	mlx_delete_texture(data->minimap->sprite.textures[3]);
	mlx_delete_texture(data->minimap->sprite.textures[4]);
	mlx_delete_texture(data->minimap->sprite.textures[5]);
	mlx_delete_texture(data->minimap->sprite.textures[6]);
	mlx_delete_texture(data->minimap->sprite.textures[7]);
	free_char_array(mlx_data->raw_map);
	free_char_array(mlx_data->map_copy);
	free(mlx_data);
}

void	free_map(t_data *data, t_map *map)
{
	free_char_array(map->matrix);
	mlx_delete_image(data->mlx, data->minimap->img_map);
	mlx_delete_image(data->mlx, data->minimap->img_tmp);
	free(map->tex);
	free(map);
}

void	free_data(t_data *data)
{
	system("pkill afplay &");
	free_mlx_data(data, data->mlx_data);
	free_map(data, data->minimap);
	mlx_terminate(data->mlx);
}
