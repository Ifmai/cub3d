/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:08:10 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/07 13:43:38 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ifmai.h"

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
        data->map->game_map = ft_calloc(sizeof(char *) , lenght_find(av[1]));
        macro_select("FILLSTRUCT", data);
        read_file(av[1], data);
    }
}