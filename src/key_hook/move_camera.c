/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:35:25 by hozdemir          #+#    #+#             */
/*   Updated: 2023/05/12 16:47:45 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

void	cam_right(t_game_data *g_data)
{
	g_data->old = g_data->dir_x;
	g_data->dir_x = g_data->dir_x * cos(g_data->rotate_speed) - \
	g_data->dir_y * sin(g_data->rotate_speed);

	g_data->dir_y = g_data->old * sin(g_data->rotate_speed) + \
	g_data->dir_y * cos(g_data->rotate_speed);

	g_data->old2 = g_data->plane_x;
	
	g_data->plane_x = g_data->plane_x * cos(g_data->rotate_speed) - \
	g_data->plane_y * sin(g_data->rotate_speed);
	
	g_data->plane_y = g_data->old2 * sin(g_data->rotate_speed) + \
	g_data->plane_y * cos(g_data->rotate_speed);
}

void	cam_left(t_game_data *g_data)
{
	g_data->old = g_data->dir_x;

	g_data->dir_x = g_data->dir_x * cos(-g_data->rotate_speed) - \
	g_data->dir_y * sin(-g_data->rotate_speed);
	g_data->dir_y = g_data->old * sin(-g_data->rotate_speed) + \
	g_data->dir_y * cos(-g_data->rotate_speed);
	g_data->old2 = g_data->plane_x;
	g_data->plane_x = g_data->plane_x * cos(-g_data->rotate_speed) - \
	g_data->plane_y * sin(-g_data->rotate_speed);
	g_data->plane_y = g_data->old2 * sin(-g_data->rotate_speed) + \
	g_data->plane_y * cos(-g_data->rotate_speed);
}