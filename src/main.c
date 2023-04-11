/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:08:10 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/11 18:12:29 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ifmai.h"

static void define_and_fill(char *path, t_data *data)
{
    data->map->game_map = ft_calloc(sizeof(char *) , lenght_find(path));
    macro_select("FILLSTRUCT", data);
    read_file(path, data);
	check_map_wall(data->map->game_map);
    error_check_file(data, 0);
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
        define_and_fill(av[1], data);
        data->mlx_window = mlx_new_window(data->mlx, MAP_W, MAP_H, "Cub3d");
        mlx_loop_hook(data->mlx, screen_fill, data);
        mlx_loop(data->mlx);
    }
}