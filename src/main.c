/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:08:10 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/11 09:10:16 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ifmai.h"

static void define_and_fill(char *path, t_data *data)
{
    data->map->game_map = ft_calloc(sizeof(char *) , lenght_find(path));
    macro_select("FILLSTRUCT", data);
    read_file(path, data);
    error_check_file(data);
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
        define_and_fill(av[1], data);
        int z = 0;
        while(data->map->game_map[z])
            printf("%s",data->map->game_map[z++]);
    }
}