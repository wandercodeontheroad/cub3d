/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:59:28 by zstenger          #+#    #+#             */
/*   Updated: 2023/05/16 07:56:50 by jergashe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

// printf("working\n");
// checking .cub format
//check the file content		
int	input_check(int argc, char *argv, t_mlx_data *data)
{
	int	i;

	i = ft_strlen(argv);
	if (argc != 2)
		return (ft_printf("%s%s", TMA, HOW_TO_LAUNCH), false);
	else if (argv && i > 3 && argv[i - 1] == 'b' && argv[i - 2] == 'u'
		&& argv[i - 3] == 'c' && argv[i - 4] == '.')
	{
		if (validate_content(argv, data) == false)
			return (false);
	}
	else
		return (printf(WRONG_EXTENSION), false);
	return (true);
}

// check the textures and colors
// check errors on the map
int	validate_content(char *map_file, t_mlx_data *data)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (printf("Map cannot be opened.\n"), false);
	line = get_next_line(fd);
	while (line != NULL)
	{
		data->reading_pos++;
		if (contains_valid_objects(line, data) == true)
		{
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (line == NULL)
		return (ft_printf("Error! Missing attributes.\n"), false);
	get_map_length(fd, map_file, data);
	if (map_validathor(map_file, data, fd) == false || data->error == true)
		return (printf("Error! Invalid map\n"), false);
	return (close(fd), true);
}
	// exit(0);

int	map_checks(t_mlx_data *data, int i)
{
	data->raw_map[i] = NULL;
	if (map_has_multiple_players_or_none(' ', 'Y') == true)
		return (false);
	data->map_copy = malloc(sizeof(char *) * (data->map_length + 1));
	data->map_copy = copy_2d_char_array(data->raw_map);
	dfs(data->map_copy, 3, 3, data);
	print_map_objects(data);
	ft_print_2d_char_array(data->map_copy);
	printf("\n");
	free_char_array(data->map_copy);
	data->map_copy = NULL;
	return (true);
}

int	is_duplicate(char *line, t_mlx_data *data)
{
	if ((ft_strncmp(line, "NO .", 4) == 0 && ft_strcmp(data->no, "X") == false)
		|| (ft_strncmp(line, "SO ", 4) == 0
			&& ft_strcmp(data->so, "X") == false)
		|| (ft_strncmp(line, "WE .", 4) == 0
			&& ft_strcmp(data->we, "X") == false)
		|| (ft_strncmp(line, "EA .", 4) == 0
			&& ft_strcmp(data->ea, "X") == false)
		|| (ft_strncmp(line, "F ", 2) == 0) && data->f_color[0] != -1
		|| (ft_strncmp(line, "C ", 2) == 0) && data->c_color[0] != -1)
		return (ft_printf(DUPLICATE), true);
	return (false);
}

char	put_chars(char c)
{
	char	colored_0[] = "\e[1;37m0\e[0m";
	char	colored_1[] = "\e[1;31m1\e[0m";
	char	colored_e[] = "\e[1;33mE\e[0m";
	char	colored_s[] = "\e[1;32mS\e[0m";
	char	colored_w[] = "\e[1;35mW\e[0m";
	char	colored_n[] = "\e[1;34mN\e[0m";
	char	colored_x[] = "\e[1;34mX\e[0m";
	char	colored_plus[] = "\e[1;34m+\e[0m";
	char	colored_v[] = "\e[1;33mV\e[0m";

	if (c == '0')
		write(1, &colored_0, 13);
	else if (c == '1')
		write(1, &colored_1, 13);
	else if (c == 'N')
		write(1, &colored_n, 13);
	else if (c == 'S')
		write(1, &colored_s, 13);
	else if (c == 'W')
		write(1, &colored_w, 13);
	else if (c == 'E')
		write(1, &colored_e, 13);
	else if (c == '+')
		write(1, &colored_plus, 13);
	else if (c == 'V')
		write(1, &colored_v, 13);
	else if (c == 'X')
		write(1, &colored_x, 13);
	else if (c == ' ')
		write(1, " ", 1);
	return (0);
}
