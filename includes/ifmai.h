/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifmai.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:07:45 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/06 10:29:33 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IFMAI_H
# define IFMAI_H

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
    char    **map;
}				t_map;

typedef struct s_data
{
	t_map	*map;
    char	*buffer;
    
}            t_data;

//utils fonksiyonları
int 	check_file_extention(char *path);
void	error_print(char *error_msg);

//map fonksiyonları
void    read_file(char *path, t_data *data);

//macro fonksiyonları
int     macro_select(char *str, t_data *data);
int		fillstruct(t_data *data);

#endif