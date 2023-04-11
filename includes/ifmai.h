/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifmai.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:07:45 by hozdemir          #+#    #+#             */
/*   Updated: 2023/04/11 20:10:05 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IFMAI_H
# define IFMAI_H

# include <stdio.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define KEY 2
# define W	13
# define S	1
# define A	0
# define D	2
# define UP	126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define ESC 53

# define MAP_W 1280
# define MAP_H 1024

# define ERRARG "Error. Sorry only 1 parameters."
# define ERRFİLE "Wrong File Extension. Error."
# define EMPTYFILE "Empty File. Error"
# define MAP_SIZE "Map size min tree line. Error."
# define PLAYER_ERR "Max one player. Error."
# define MAP_WALL "Map must be surrounded by walls. Error."

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

typedef struct s_player
{
	char	player_direction;
    double  p_x;
    double  p_y;

}			t_player;


typedef struct s_data
{
	t_map		*map;
	t_player	*player;
	void		*mlx;
	void		*mlx_window;
	void		*no_wall;
	void		*so_wall;
	void		*we_wall;
	void		*ea_wall;
	double		ray_x;
	double		ray_y;
	double		plane_x;
	double		plane_y;
	double		wall_x;
	double		wall_y;
	double		dir_x;
	double		dir_y;
    char		*buffer;
}            t_data;


//Main func.
void    read_file(char *path, t_data *data);
void	check_map_wall(char **map);
void	error_check_file(t_data *data, int count);

//General utils
void	error_print(char *error_msg);
void	free_double_array(char **free_array);
int 	double_strlen(char **str);

//map : utils func.
int 	check_file_extention(char *path);
int		lenght_find(char *path);

//macro func.
int     macro_select(char *str, t_data *data);
t_bool	fillstruct(t_data *data);
t_bool	mapstr(t_data *data);
t_bool  select_direction(t_data *data);

#endif