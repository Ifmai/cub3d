/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:12:47 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/15 17:38:05 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

static void	set_data(t_game_data *data, int width)
{
	//işlem yapcıağımı kısmın çizdiğimiz açıda nerde kalıdığını bakıyoruz bizim bir bakış açımız var ve bu bakış açısında
	//biz şuan hangi yöne bakıyoruz ?
	data->camera_x = 2 * width / (double)MAP_W - 1; // işlem yapılan pikselin ışının hangi tarafında kaldığını buluyoruz -1 veya 1 değerini alıyor
	data->raydir_x = data->dir_x + data->plane_x * data->camera_x;
	data->raydir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = (int)data->player->p_x;
	data->map_y = (int)data->player->p_y;
	data->delta_dist_x = fabs(1 / data->raydir_x);
	data->delta_dist_y = fabs(1 / data->raydir_y);
	data->hit = 0;
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
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img, 0, 0);
}

int	screen_fill(t_data	*data)
{
	int	width;

	width = 0;
	// dir_x dir_y değişkenlerini 1 veya 0 ile değiştiriyor nereye bakması gerekiyorsa.
	macro_select("SELECT_DIRECTION", data);
	color_painting(data);
	while (width < MAP_W)
	{
		set_data(data->game_data, width);
		width++;
	}
	return (0);
}
