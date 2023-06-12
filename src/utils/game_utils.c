/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:50:54 by hozdemir          #+#    #+#             */
/*   Updated: 2023/06/12 15:39:14 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"

void	setup_game(t_game_data *map)
{
	map->move_speed = 0.03;
	map->rotate_speed = 0.032;
	map->w_sixtyfour = 64;
	map->h_sixtyfour = 64;
}

void	add_game_image(t_game_data *game, t_data *data)
{
	game->image->no = mlx_xpm_file_to_image(data->mlx, data->map->no_wall_path, \
		&game->w_sixtyfour, &game->w_sixtyfour);
	game->image->so = mlx_xpm_file_to_image(data->mlx, data->map->so_wall_path, \
		&game->w_sixtyfour, &game->w_sixtyfour);
	game->image->ea = mlx_xpm_file_to_image(data->mlx, data->map->ea_wall_path, \
		&game->w_sixtyfour, &game->w_sixtyfour);
	game->image->we = mlx_xpm_file_to_image(data->mlx, data->map->we_wall_path, \
		&game->w_sixtyfour, &game->w_sixtyfour);
	game->image->no_image = (int *)mlx_get_data_addr(game->image->no,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	game->image->so_image = (int *)mlx_get_data_addr(game->image->so,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	game->image->ea_image = (int *)mlx_get_data_addr(game->image->ea,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	game->image->we_image = (int *)mlx_get_data_addr(game->image->we,
			&data->bits_per_pixel, &data->line_length, &data->endian);
}
