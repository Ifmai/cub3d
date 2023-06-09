/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturker <rturker@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:25:25 by hozdemir          #+#    #+#             */
/*   Updated: 2023/06/12 14:15:10 by rturker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

static char	*new_ft_strdup(char *str, t_data *data, int flag)
{
	int		i;
	int		j;

	(void)data;
	i = 0;
	j = ft_strlen(str) - 1;
	while (str[i] != '.' && !(str[i] <= 57 && str[i] >= 48))
		i++;
	if (flag)
	{
		while (str[j - 1] != 'm')
			j--;
		return (ft_substr(str, i, j - i));
	}
	return (ft_strdup(str + i));
}

static void	select_direction_photo(char *check_str, t_data *data)
{
	if (ft_strnstr(check_str, "NO", 2))
		data->map->no_wall_path = new_ft_strdup(check_str, data, 1);
	else if (ft_strnstr(check_str, "SO", 2))
		data->map->so_wall_path = new_ft_strdup(check_str, data, 1);
	else if (ft_strnstr(check_str, "WE", 2))
		data->map->we_wall_path = new_ft_strdup(check_str, data, 1);
	else if (ft_strnstr(check_str, "EA", 2))
		data->map->ea_wall_path = new_ft_strdup(check_str, data, 1);
	else if (ft_strnstr(check_str, "C", 1))
		data->map->inner_color = new_ft_strdup(check_str, data, 0);
	else if (ft_strnstr(check_str, "F", 1))
		data->map->ground_colors = new_ft_strdup(check_str, data, 0);
	return ;
}

void	read_file(char *path, t_data *data)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(path, O_RDONLY);
	while (1)
	{
		data->buffer = get_next_line(fd);
		if (!data->buffer)
			return ;
		if (ft_isalpha(*data->buffer))
			select_direction_photo(data->buffer, data);
		else if (macro_select("MAPSTR", data))
		{
			data->map->game_map[i] = ft_strdup(data->buffer);
			i++;
		}
		free(data->buffer);
	}
}
