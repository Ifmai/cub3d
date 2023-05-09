/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:08:10 by hozdemir          #+#    #+#             */
/*   Updated: 2023/05/09 13:14:12 by hozdemir         ###   ########.fr       */
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
    fill_one(data);
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
    add_game_image(data->game_data, data);
    setup_game(data->game_data);
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
        data = malloc(sizeof(t_data) * 1);
        data->map = malloc(sizeof(t_map) * 1);
        data->player = malloc(sizeof(t_player) * 1);
        data->game_data = malloc(sizeof(t_game_data) * 1);
        data->image = malloc(sizeof(t_image) * 1);
        data->key = malloc(sizeof(t_key) * 1);
        data->mlx = mlx_init();
        define_and_fill(av[1], data);
	    data->mlx_window = mlx_new_window(data->mlx, MAP_W, MAP_H, "Cub3D");
	    data->img = mlx_new_image(data->mlx, MAP_W, MAP_H);
        data->addr = (int *)mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
									&data->endian);
	    macro_select("SELECT_DIRECTION", data);
	    //mlx_hook(data->mlx_window, 17, 0, clo, data);
       	mlx_loop_hook(data->mlx, screen_fill, data);
        mlx_hook(data->mlx_window, 2, 0, move, data);
        mlx_hook(data->mlx_window, 3, 0, move_two, data);
        mlx_loop(data->mlx);
    }
}