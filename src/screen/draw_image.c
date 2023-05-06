/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:25:08 by hozdemir          #+#    #+#             */
/*   Updated: 2023/05/05 22:50:01 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

void	set_image_values(t_game_data *map)
{
	if (map->side == 0)
		map->wallx = map->player->p_y + map->wall_dist * map->raydir_y;
	else
		map->wallx = map->player->p_x + map->wall_dist * map->raydir_x;
	map->wallx -= floor(map->wallx);
	map->mx = (int)(map->wallx * (double)map->w_sixtyfour);
	if (map->side == 0 && map->raydir_x > 0)
		map->mx = map->w_sixtyfour - map->mx - 1;
	if (map->side == 1 && map->raydir_y < 0)
		map->mx = map->w_sixtyfour - map->mx - 1;
	map->pixel_cal = 1.0 * map->h_sixtyfour / map->line_height;
	map->pixel_nbr = (map->draw_start - MAP_H / 2 + map->line_height \
	/ 2) * map->pixel_cal;
}

void	draw_image(t_game_data *map, t_data *data, int i)
{
	int	a;

	a = map->draw_start;
	while (a < map->draw_end)
	{
		map->my = (int)map->pixel_nbr & (map->h_sixtyfour - 1);
		map->pixel_nbr += map->pixel_cal;	
		if (map->raydir_x > 0 && map->side != 1)
			map->colour = map->image->so_image[map->h_sixtyfour * \
			map->my + map->mx];
		else if (map->raydir_x < 0 && map->side != 1)
			map->colour = map->image->no_image[map->h_sixtyfour * \
			map->my + map->mx];
		else if ((map->raydir_x <= 2 && map->raydir_y >= 0) && map->side == 1)
			map->colour = map->image->ea_image[map->h_sixtyfour * \
			map->my + map->mx];
		else
			map->colour = map->image->we_image[map->h_sixtyfour * \
			map->my + map->mx];
		data->addr[a * MAP_W + i] = map->colour;
		a++;
	}
}
