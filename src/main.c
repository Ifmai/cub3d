/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:08:10 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/06 13:42:32 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ifmai.h"

static void    map_all_func(char *path, t_data *data)
{
    read_file(path, data);
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
        data->map->map = ft_calloc(sizeof(char *) , lenght_find(av[1]));
        macro_select("FILLSTRUCT", data);
        map_all_func(av[1], data);
        int i = 0;
        while(data->map->map[i])
            printf("%s\n",data->map->map[i++]);
        printf("%s\n",data->map->ea_wall_path);
        printf("%s\n",data->map->we_wall_path);
        printf("%s\n",data->map->so_wall_path);
        printf("%s\n",data->map->no_wall_path);

    }
}