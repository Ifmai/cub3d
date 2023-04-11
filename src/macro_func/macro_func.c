/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:07:52 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/11 20:09:48 by hozdemir         ###   ########.fr       */
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
		data->player->dir_y = 1;
	else if (data->player->player_direction == 'S')
		data->player->dir_y = -1;
    else if (data->player->player_direction == 'E')
		data->player->dir_x = 1;
	else if (data->player->player_direction == 'W')
		data->player->dir_x = -1;
    return (TRUE);
}

t_bool fillstruct(t_data *data)
{
    data->mlx = mlx_init();
    data->buffer = 0;
    data->map->ea_wall_path = 0;
    data->map->no_wall_path = 0;
    data->map->so_wall_path = 0;
    data->map->we_wall_path = 0;
    data->map->inner_lining_color = 0;
    data->map->ground_color = 0;
    data->player->p_x = 0;
    data->player->p_y = 0;
    data->ray_x = 0;
    data->ray_y = 0;
    data->dir_x = 0;
    data->dir_y = 0;
    data->plane_x = 0;
    data->plane_y = 0.66;
    return (TRUE);
}