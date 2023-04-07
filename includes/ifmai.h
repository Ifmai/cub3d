/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifmai.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:07:45 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/07 13:18:08 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IFMAI_H
# define IFMAI_H

# include <stdio.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

# define ERRARG "Error. Sorry only 1 parameters."
# define ERRFİLE "Wrong File Extension. Error."
# define EMPTYFILE "Empty File. Error"

typedef enum e_bool
{
    FALSE = 0,
    TRUE = 1
}	t_bool;

typedef struct s_map_data
{
	char    *no_wall_path;
    char    *so_wall_path;
    char    *we_wall_path;
    char    *ea_wall_path;
	char	*inner_lining_color;
	char	*ground_color;
    char    **game_map;
}				t_map;

typedef struct s_data
{
	t_map	*map;
    char	*buffer;
    
}            t_data;


//General Utils
void	error_print(char *error_msg);
void	free_double_array(char **free_array);


//map func.
void    read_file(char *path, t_data *data);

//map : utils func.
int 	check_file_extention(char *path);
int		lenght_find(char *path);

//macro func.
int     macro_select(char *str, t_data *data);
t_bool	fillstruct(t_data *data);
t_bool	mapstr(t_data *data);

#endif