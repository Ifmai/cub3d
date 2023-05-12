/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:44:04 by hozdemir          #+#    #+#             */
/*   Updated: 2023/05/12 16:48:27 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

int	move(int key, t_data *data)
{
	if (key == ESC)
		close_window(data);
	if (key == W)
		data->key->w_key = 1;
	if (key == A)
		data->key->a_key = 1;
	if (key == S)
		data->key->s_key = 1;
	if (key == D)
		data->key->d_key = 1;
	if (key == LEFT)
		data->key->cam_left = 1;
	if (key == RIGHT)
		data->key->cam_right = 1;
	if (key == M)
		data->key->map_key = 1;
	return (0);
}

int	move_two(int key, t_data *data)
{
	if (key == ESC)
		close_window(data);
	if (key == W)
		data->key->w_key = 0;
	if (key == A)
		data->key->a_key = 0;
	if (key == S)
		data->key->s_key = 0;
	if (key == D)
		data->key->d_key = 0;
	if (key == LEFT)
		data->key->cam_left = 0;
	if (key == RIGHT)
		data->key->cam_right = 0;
	if (key == M)
		data->key->map_key = 0;
	return (0);
}

void	move_draw(t_data *data, t_game_data *game_data)
{
	move_forward_backward(data, game_data);
	if(data->key->a_key)
		move_left(data,game_data);
	if (data->key->cam_left)
		cam_left(game_data);
	if (data->key->d_key)
		move_right(data, game_data);
	if (data->key->cam_right)
		cam_right(game_data);
}