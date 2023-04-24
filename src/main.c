/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:08:10 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/24 21:25:28 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ifmai.h"

static void define_and_fill(char *path, t_data *data)
{
    int i;

    i = 0;
    macro_select("FILLSTRUCT", data);
    data->map->game_map = ft_calloc(sizeof(char *) , lenght_find(path));
    read_file(path, data);
	check_map_wall(data->map->game_map);
    error_check_file(data, 0);
    data->map->ground_color = ft_split(data->map->ground_colors, ',');
    data->map->in_color = ft_split(data->map->inner_color, ',');
    while(i < 3)
    {
        data->map->color_g[i] = ft_atoi(data->map->ground_color[i]);
        data->map->color_inner[i] = ft_atoi(data->map->in_color[i]);
        i++;
    }
    data->ground = get_color(data->map->color_g);
    data->inner = get_color(data->map->color_inner);
}

int main(int ac, char **av)
{
    t_data  *data;

    if(ac != 2)
        error_print(ERRARG);
    else
    {
        if(!check_file_extention(av[1]))
            error_print(ERRFİLE);
        data = malloc(sizeof(t_data));
        data->map = malloc(sizeof(t_map));
        data->player = malloc(sizeof(t_player));
        data->game_data = malloc(sizeof(t_game_data));
        define_and_fill(av[1], data);
        screen_fill(data);
        //mlx_loop_hook(data->mlx, screen_fill, data);
        mlx_loop(data->mlx);
    }
}