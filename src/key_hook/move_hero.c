/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:34:28 by hozdemir          #+#    #+#             */
/*   Updated: 2023/05/12 16:47:28 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

static void	move_forward_backward_2(t_data *data, t_game_data *g_data)
{
	if (data->map->game_map[(int)(data->player->p_x - g_data->dir_x * \
	g_data->move_speed)][(int)(data->player->p_y)] == '0' \
	|| data->map->game_map[(int)(data->player->p_x - g_data->dir_x * \
	g_data->move_speed)][(int)(data->player->p_y)] == data->player->player_direction)
		data->player->p_x -= g_data->dir_x * g_data->move_speed;
	if (data->map->game_map[(int)data->player->p_x][(int) (data->player->p_y \
	- g_data->dir_y * g_data->move_speed)] == '0' || \
	data->map->game_map[(int)data->player->p_x][(int)(data->player->p_y \
	- g_data->dir_y * g_data->move_speed)] == data->player->player_direction)
		data->player->p_y -= g_data->dir_y * g_data->move_speed;
}

void	move_forward_backward(t_data *data, t_game_data *g_data)
{
	if (data->key->w_key)
	{
		if (data->map->game_map[(int)(data->player->p_x + g_data->dir_x * \
		g_data->move_speed)][(int)(data->player->p_y)] == '0' \
		|| data->map->game_map[(int)(data->player->p_x + g_data->dir_x * \
		g_data->move_speed)][(int)(data->player->p_y)] == data->player->player_direction)
			data->player->p_x += g_data->dir_x * g_data->move_speed;
		if (data->map->game_map[(int)data->player->p_x] \
		[(int)(data->player->p_y + g_data->dir_y * g_data->move_speed)] == '0' || \
		data->map->game_map[(int)data->player->p_x][(int)(data->player->p_y \
		+ g_data->dir_y * g_data->move_speed)] == data->player->player_direction)
			data->player->p_y += g_data->dir_y * g_data->move_speed;
	}
	else if (data->key->s_key)
		move_forward_backward_2(data, g_data);
}

void	move_left(t_data *data, t_game_data *g_data)
{
	if (data->map->game_map[(int)(data->player->p_x \
	 - g_data->plane_x * g_data->move_speed)][(int)data->player->p_y] == '0' \
	|| data->map->game_map[(int)(data->player->p_x - g_data->plane_x \
	* g_data->move_speed)][(int)data->player->p_y] == data->player->player_direction)
		data->player->p_x -= g_data->plane_x * g_data->move_speed;
	if (data->map->game_map[(int)data->player->p_x][(int)(data->player->p_y \
	- g_data->plane_y * g_data->move_speed)] == '0' || \
	data->map->game_map[(int)data->player->p_x][(int)(data->player->p_y \
	- g_data->plane_y * g_data->move_speed)] == data->player->player_direction)
		g_data->plane_y -= g_data->plane_y * g_data->move_speed;
}

void	move_right(t_data *data, t_game_data *g_data)
{
	if (data->map->game_map[(int)(data->player->p_x \
	+ g_data->plane_x * g_data->move_speed)][(int)data->player->p_y] == '0' \
	|| data->map->game_map[(int)(data->player->p_x + g_data->plane_x \
	* g_data->move_speed)][(int)data->player->p_y] == data->player->player_direction)
		data->player->p_x += g_data->plane_x * g_data->move_speed;
	if (data->map->game_map[(int)data->player->p_x][(int)(data->player->p_y \
	+ g_data->plane_y * g_data->move_speed)] == '0' || \
	data->map->game_map[(int)data->player->p_x][(int)(data->player->p_y \
	+ g_data->plane_y * g_data->move_speed)] == data->player->player_direction)
		g_data->plane_y += g_data->plane_y * g_data->move_speed;
}