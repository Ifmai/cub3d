/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:08:10 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/06 10:30:02 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ifmai.h"

static void    map_all_func(char *path, t_data *data)
{
    if(!check_file_extention(path))
        error_print(ERRFİLE);
    read_file(path, data);
}

int main(int ac, char **av)
{
    t_data  *data;

    if(ac != 1)
        error_print(ERRARG);
    else
    {
        data = malloc(sizeof(t_data));
        data->map = malloc(sizeof(t_map));
        macro_select("FILLSTRUCT", data);
        map_all_func(av[1], data);
    }
}