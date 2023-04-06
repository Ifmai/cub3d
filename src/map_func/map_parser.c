/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:25:25 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/06 13:40:38 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ifmai.h"


static char *new_ft_strdup(char *str)
{
	int		i;

	i = 0;
	printf("str : %s",str);
	while(str[i] != '.' && !(str[i] <= 57 && str[i] >= 48))
		i++;
	return (ft_strdup(str + i));
}

static void	select_direction_photo(char *check_str, t_data *data)
{
	if (ft_strnstr(check_str, "NO", 2))
		data->map->no_wall_path = new_ft_strdup(check_str);
	else if (ft_strnstr(check_str, "SO", 2))
		data->map->so_wall_path = new_ft_strdup(check_str);
	else if (ft_strnstr(check_str, "WE", 2))
		data->map->we_wall_path = new_ft_strdup(check_str);
	else if (ft_strnstr(check_str, "EA", 2))
		data->map->ea_wall_path = new_ft_strdup(check_str);
	else if (ft_strnstr(check_str, "C", 1))
		data->map->inner_lining_color = new_ft_strdup(check_str);
	else if (ft_strnstr(check_str, "F", 1))
		data->map->ground_color = new_ft_strdup(check_str);
	return ;
}

void    read_file(char *path, t_data *data)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	/* if (!data->buffer)//bu kalkabilir sadece kontrol ediyorum keyfi
		error_print(EMPTYFILE); */
	while(1)
	{
		data->buffer = get_next_line(fd);
		if(!data->buffer)
			return ;
		if(ft_isalpha(*data->buffer)) //ilk karakterse gitsin. boşuna sürekli tarama yapmasın
			select_direction_photo(data->buffer, data);
		else if(macro_select("MAPSTR",data)) // İçinde "NO SO WE EA C F" yoksa giricek yani map'i okuyorum demek.
		{
			data->map->map[i] = ft_strdup(data->buffer);
			i++;
		}
		free(data->buffer);
	}
}