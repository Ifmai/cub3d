/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:07:52 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/07 13:19:08 by hozdemir         ###   ########.fr       */
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

t_bool fillstruct(t_data *data)
{
    data->buffer = 0;
    data->map->ea_wall_path = 0;
    data->map->no_wall_path = 0;
    data->map->so_wall_path = 0;
    data->map->we_wall_path = 0;
    data->map->inner_lining_color = 0;
    data->map->ground_color = 0;
    return (TRUE);
}