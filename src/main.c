/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:08:10 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/14 18:05:16 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ifmai.h"

/* static void define_and_fill(char *path, t_data *data)
{
    data->map->game_map = ft_calloc(sizeof(char *) , lenght_find(path));
    read_file(path, data);
	check_map_wall(data->map->game_map);
    error_check_file(data, 0);
    data->map->ground_color = ft_split(data->map->ground_colors, ',');
    data->map->in_color = ft_split(data->map->inner_color, ',');
} */

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
        //data->map = malloc(sizeof(t_map));
        //data->player = malloc(sizeof(t_player));
        //data->game_data = malloc(sizeof(t_game_data));
        //define_and_fill(av[1], data);
        //macro_select("FILLSTRUCT", data);
        data->mlx = mlx_init();
        data->mlx_window = mlx_new_window(data->mlx, MAP_W, MAP_H, "Hello world!");
        data->img = mlx_new_image(data->mlx, MAP_W, MAP_H);
        data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
                                    &data->endian);
        my_mlx_pixel_put(data, 23, 42, 0x00FF0000);
        //mlx_put_image_to_window(data->mlx, data->mlx_window, data->img, 0, 0);
        mlx_loop(data->mlx);
        //screen_fill(data);
        //mlx_loop_hook(data->mlx, screen_fill, data);
        mlx_loop(data->mlx);
    }
}