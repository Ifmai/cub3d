/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:12:47 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/12 14:58:26 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"


static int	ray_casting(t_data *data)
{
	int		i;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;

	i = 0;
	while (i < MAP_W)
	{
		//işlem yapcıağımı kısmın çizdiğimiz açıda nerde kalıdığını bakıyoruz bizim bir bakış açımız var ve bu bakış açısında
		//biz şuan hangi yöne bakıyoruz ?
		camera_x = 2 * i / (double)MAP_W - 1; // işlem yapılan pikselin ışının hangi tarafında kaldığını buluyoruz -1 veya 1 değerini alıyor
		raydir_x = data->dir_x + data->plane_x * camera_x;
		raydir_y = data->dir_y + data->plane_y * camera_x;
		
		i++;	
	}
}

void	color_painting(t_data *data)
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
				mlx_pixel_put(data->mlx, data->mlx_window, \
					i, j, data->map->inner_lining_color);
			else
				mlx_pixel_put(data->mlx, data->mlx_window, \
					i, j, data->map->ground_color);
			j++;
		}
		i++;
	}
}

int	screen_fill(t_data	*data)
{
	int	height;

	height = MAP_H;
	// dir_x dir_y değişkenlerini 1 veya 0 ile değiştiriyor nereye bakması gerekiyorsa.
	macro_select("SELECT_DIRECTION", data);
	color_painting(data);
	while (height--)
	{
		ray_casting(data);
	}
	return (0);
}