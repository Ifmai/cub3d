/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:04:27 by hozdemir          #+#    #+#             */
/*   Updated: 2023/05/06 17:46:59 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"


void	fill_one(t_data *data)
{
	int	i;
	int y;

	i = 0;
	while(data->map->game_map[i])
	{
		y = 0;
		while(data->map->game_map[i][y])
		{
			if(data->map->game_map[i][y] == 32 || (data->map->game_map[i][y] <= 13 && data->map->game_map[i][y] >= 9))
				data->map->game_map[i][y] = '1';
			y++;
		}
		i++;
	}
}

void	check_map_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (i == 0 || i == double_strlen(map))
				if(map[i][j] != '1')
					error_print(MAP_WALL);
			if (i != 0 && i != double_strlen(map) && j == 0 && j == str_len(map[i]))
				if(map[i][j] != 1)
					error_print(MAP_WALL);
			j++;
		}
		i++;
	}
}

void	error_check_file(t_data *data, int count)
{
	int	i;
	int	j;

	i = -1;
	while(data->map->game_map[++i])
	{
		j = -1;
		while(data->map->game_map[i][++j])
		{
			if (data->map->game_map[i][j] == 'N' || \
				data->map->game_map[i][j] == 'S' || \
				data->map->game_map[i][j] == 'W' || \
				data->map->game_map[i][j] == 'E')
			{
				count++;
				data->player->player_direction = data->map->game_map[i][j];
				data->player->p_x = i;
				data->player->p_y = j;
			}
		}
	}
	if (i < 3 || count != 1)
		error_print(MAP_SIZE);
	if (count != 1)
		error_print(PLAYER_ERR);
}