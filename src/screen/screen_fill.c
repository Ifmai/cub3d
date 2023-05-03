/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:12:47 by hozdemir          #+#    #+#             */
/*   Updated: 2023/05/03 20:42:15 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

static void	set_data(t_game_data *game, int width)
{
	game->camera_x = (2 * width / (double)MAP_W - 1);
	game->raydir_x = game->dir_x + game->plane_x * game->camera_x;
	game->raydir_y = game->dir_y + game->plane_y * game->camera_x;
	game->map_x = (int)game->player->p_x;
	game->map_y = (int)game->player->p_y;
	game->delta_dist_x = fabs(1 / game->raydir_x);
	game->delta_dist_y = fabs(1 / game->raydir_y);
	game->hit = 0;
}

static void	color_painting(t_data *data)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < MAP_H)
	{
		j = 0;
		while (j < MAP_W)
		{
			if (i < MAP_H / 2)
				my_mlx_pixel_put(data, j, i, data->inner);
			else
				my_mlx_pixel_put(data, j, i, data->ground);
			j++;
		}
		i++;
	}
}

static void	img_print_screen(t_data *data)
{
	int	width;

	width = 0;
	while (width < MAP_W)
	{
		set_data(data->game_data, width);
		wallcheck(data->game_data);
		hitcheck(data->game_data, data->map);
		get_dist(data->game_data);
		set_image_values(data->game_data);
		draw_image(data->game_data, data, width); 
		width++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img, 0, 0);
}

int	screen_fill(t_data	*data)
{
	mlx_clear_window(data->mlx, data->mlx_window);
	color_painting(data);
	img_print_screen(data);
	return (0);
}
