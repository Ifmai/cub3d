/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:04:27 by hozdemir          #+#    #+#             */
/*   Updated: 2023/05/03 19:43:13 by hozdemir         ###   ########.fr       */
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

static int	space_count(char *str, int j)
{
	int	i;
	int count;

	i = j;
	count = 0;
	while (str[j] != 0)
	{
		if(str[j] == 32 || str[j] == 9)
			count++;
		j++;
	}
	if (count == 0)
		return (1);
	return (count);
}

static void	check_map_wall_2(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[0][j] && (map[0][j] == 32 || map[0][++j] == 9)) // 9 ascii de tab.
		j++;
	while(map[0][j] != 0)
	{
		if(map[0][j] == 32 || map[0][j] == '\n')
		{
			j++;
			continue;
		}
		if(map[0][j] != '1')
			error_print(MAP_WALL);
		j++;
	}
	j = -1;
	i = double_strlen(map) - 1;
	while(map[i][++j])
	{
		if(map[0][j] == 32 || map[0][j] == 9)
			continue;
		if(map[0][j] != '1')
			error_print(MAP_WALL);
	}
}

void	check_map_wall(char **map)
{
	int	i;
	int	j;
	int	loop_count;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j] && (map[i][j] == 32 || map[i][j] == 9)) // 9 ascii de tab. // bu döngü tab ve spaceleri geçti
			j++;
		loop_count = space_count(map[i], j);// o satırda kaç space olduğunu saydık eğer hiç yoksa değer 1 döndü
		while(loop_count--)
		{
			if(map[i][j] != '1')// geçtikten sonra ilk görmesini beklenin 1 değilse error'a düştü
				error_print(MAP_WALL);
			while(map[i][j] != '\n' && map[i][j] != 32 && map[i][j] != 9)// satırın ilk başını yukarda kontrol ettik bu yüzden şimdi diğer köşeleri kontrol etme vakti.
				j++;
			if(map[i][j - 1] != '1') // -1 çünkü şuan map[i][j] space veya tabda.
				error_print(MAP_WALL);
			while(map[i][j] && (map[i][j] == 32 || map[i][j] == 9))// burda da tekrar boşlukları geçtim. 10001 10001 10001 gibi bir mapte ilk 10001 bitmiş oldu 2 defa bu tekrarlancak.
				j++;
		}
	}
	check_map_wall_2(map);
}

void	error_check_file(t_data *data, int count)
{
	int	i;
	int	j;

	i = -1;
	while(data->map->game_map[++i])
	{
		j = -1;
		printf("%s",data->map->game_map[i]);
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