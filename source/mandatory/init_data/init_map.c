/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:14:26 by zstenger          #+#    #+#             */
/*   Updated: 2023/05/08 11:50:33 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void    set_player_position(t_map *minimap)
{
    int y;
    int x;
    y = 0;
    minimap->player.dir.x = -1;
    minimap->player.dir.y = 0;
    minimap->player.plane.x = 0;
    minimap->player.plane.y = 1;
    while (minimap->matrix[y] != NULL)
    {
        x = 0;
        while (minimap->matrix[y][x] != '\n' && minimap->matrix[y][x] != '\0')
        {
            if (minimap->matrix[y][x] == 'N')
            {
                minimap->player.pos.y = y;
                minimap->player.pos.x = x;
				minimap->player.angle = M_PI * 2;
				minimap->player.dir.x = cos(minimap->player.angle);
				minimap->player.dir.y = sin(minimap->player.angle);
                return ;
            }
            x++;
        }
        y++;
    }
}

int	get_longest_line(char **map)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (map[i] != NULL)
	{
		if (result < ft_strlen(map[i]))
			result = ft_strlen(map[i]);
		i++;
	}
	return (result);
}

char	*dup3(int size, char ch)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	while (i != size)
	{
		str[i] = ch;
		i++;
	}
	return (str);
}

char	*init_line(char *old_line, int len)
{
	char	*result;
	char	*line;
	int		i;

	i = 0;
	while (old_line[i] != '\0' && old_line[i] != '\n')
		i++;
	line = ft_strdup2(old_line, 0, i);
	old_line = ft_strdup(line);
	result = dup3((MINIMAP_SIZE / MINIMAP_REC) / 2, 'V');
	result = ft_strjoin(result, old_line);
	result = ft_strjoin(result, dup3(len - (MINIMAP_SIZE / MINIMAP_REC) / 2 - ft_strlen(line), 'V')); // "    line    "
	i = -1;
	while (result[++i] != '\0')
		if (result[i] == ' ')
			result[i] = 'V';
	return(result);
}

char	**init_matrix(char **map, int height)
{
	char	**matrix;
	int		len;
	int		i;

	matrix = malloc(sizeof(char *) * (height + MINIMAP_SIZE / MINIMAP_REC + 1));
	matrix[height + MINIMAP_SIZE / MINIMAP_REC] = NULL;
	len = get_longest_line(map) + (MINIMAP_SIZE / MINIMAP_REC) - 1;
	i = -1;
	while (++i < (MINIMAP_SIZE / MINIMAP_REC) / 2)
		matrix[i] = dup3(len, 'V');
	while (map[i - (MINIMAP_SIZE / MINIMAP_REC) / 2] != NULL)
	{
		matrix[i] = init_line(map[i - (MINIMAP_SIZE / MINIMAP_REC) / 2], len);
		i++;
	}
	while (i != height + MINIMAP_SIZE / MINIMAP_REC )
		matrix[i++] = dup3(len, 'V');
	return (matrix);
}

t_map*	init_map(t_mlx_data *mlx_data, mlx_t *mlx)
{
	t_map	*minimap;

	minimap = malloc(sizeof(t_map));
	minimap->matrix = init_matrix(mlx_data->raw_map, mlx_data->map_length);
	ft_print_2d_char_array(minimap->matrix);
	set_player_position(minimap); // + init player dir & plane
	minimap->img_map = mlx_new_image(mlx, MINIMAP_SIZE, MINIMAP_SIZE);
	minimap->img_tmp = mlx_new_image(mlx, WIDTH, HEIGHT);
	return (minimap);
}