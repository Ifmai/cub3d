/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rturker <rturker@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:27:51 by hozdemir          #+#    #+#             */
/*   Updated: 2023/06/12 14:02:23 by rturker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

void	wallcheck(t_game_data *game)
{
	if (game->raydir_x < 0)
	{
		game->step_x = -1;
		game->sidedist_x = (game->player->p_x - game->map_x)
			* game->delta_dist_x;
	}
	else
	{
		game->step_x = 1;
		game->sidedist_x = (game->map_x + 1.0 - game->player->p_x)
			* game->delta_dist_x;
	}
	if (game->raydir_y < 0)
	{
		game->step_y = -1;
		game->sidedist_y = (game->player->p_y - game->map_y)
			* game->delta_dist_y;
	}
	else
	{
		game->step_y = 1;
		game->sidedist_y = (game->map_y + 1.0 - game->player->p_y)
			* game->delta_dist_y;
	}
}

void	hitcheck(t_game_data *map, t_map *data)
{
	while (map->hit == 0)
	{
		if (map->sidedist_x < map->sidedist_y)
		{
			map->sidedist_x += map->delta_dist_x;
			map->map_x += map->step_x;
			map->side = 0;
		}
		else
		{
			map->sidedist_y += map->delta_dist_y;
			map->map_y += map->step_y;
			map->side = 1;
		}
		if (data->game_map[map->map_x][map->map_y] == '1')
			map->hit = 1;
	}
}

void	get_dist(t_game_data *map)
{
	if (map->side == 0)
		map->wall_dist = map->sidedist_x - map->delta_dist_x;
	else
		map->wall_dist = map->sidedist_y - map->delta_dist_y;
	map->line_height = (int)(MAP_H / map->wall_dist);
	map->draw_start = -map->line_height / 2 + MAP_H / 2;
	if (map->draw_start < 0)
		map->draw_start = 0;
	map->draw_end = map->line_height / 2 + MAP_H / 2;
	if (map->draw_end >= MAP_H)
		map->draw_end = MAP_H - 1;
}
