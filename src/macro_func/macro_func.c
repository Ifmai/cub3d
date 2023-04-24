/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:07:52 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/24 21:25:23 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

t_bool	mapstr(t_data *data)
{
	if(!(ft_strnstr(data->buffer, "NO", 2)) && \
		!(ft_strnstr(data->buffer, "SO", 2)) && \
		!(ft_strnstr(data->buffer, "WE", 2)) && \
		!(ft_strnstr(data->buffer, "EA", 2)) && \
		!(ft_strnstr(data->buffer, "C", 1)) && \
		!(ft_strnstr(data->buffer, "F", 1)) && \
        !(ft_strnstr(data->buffer, "\n", 1)))
		return (TRUE);
	return (FALSE);
}

t_bool  select_direction(t_data *data)
{
    if(data->player->player_direction == 'N')
    {
		data->game_data->dir_x = -1;
		data->game_data->plane_y = -0.66;
    }
	else if (data->player->player_direction == 'S')
	{
		data->game_data->dir_x = 1;
		data->game_data->plane_y = 0.66;
	}
    else if (data->player->player_direction == 'E')
	{
		data->game_data->dir_y = -1;
		data->game_data->plane_x = 0.66;
	}
	else if (data->player->player_direction == 'W')
	{
		data->game_data->dir_y = 1;
		data->game_data->plane_x = 0.66;
	}
    return (TRUE);
}

t_bool fillstruct(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx, MAP_W, MAP_H, "Cub3D");
	data->img = mlx_new_image(data->mlx, MAP_W, MAP_H);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
									&data->endian);
    data->buffer = 0;
    data->map->ea_wall_path = 0;
    data->map->no_wall_path = 0;
    data->map->so_wall_path = 0;
    data->map->we_wall_path = 0;
    data->map->inner_color = 0;
    data->map->ground_colors = 0;
    data->player->p_x = 0;
    data->player->p_y = 0;
    data->game_data->ray_x = 0;
    data->game_data->ray_y = 0;
    data->game_data->dir_x = 0;
    data->game_data->dir_y = 0;
    data->game_data->plane_x = 0;
    data->game_data->plane_y = 0.66;
    data->game_data->player = data->player;
    data->map->color_g = malloc(sizeof(int) * 3);
    data->map->color_inner = malloc(sizeof(int) * 3);
    return (TRUE);
}