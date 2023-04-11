/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:12:47 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/11 20:36:49 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

int	screen_fill(t_data	*data)
{
	int		height;
	int		weight;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;

	weight = 0;
	macro_select("SELECT_DIRECTION", data);// dir_x dir_y değişkenlerini 1 veya 0 ile değiştiriyor nereye bakması gerekiyorsa.
	while (weight < MAP_W)
	{
		height = MAP_H;
		while (height--)
		{
			camera_x = 2 * weight / (double)height - 1; // işlem yapılan pikselin ışının hangi tarafında kaldığını buluyoruz -1 veya 1 değerini alıyor
			raydir_x = data->dir_x + data->plane_x * camera_x;
			raydir_y = data->dir_y + data->plane_y * camera_x;
		}
		weight++;
	}
	return (0);
}