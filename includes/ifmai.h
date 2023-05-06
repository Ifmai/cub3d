/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifmai.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:07:45 by hozdemir          #+#    #+#             */
/*   Updated: 2023/05/05 23:18:45 by hozdemir         ###   ########.fr       */
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

# define MAP_W 1920
# define MAP_H 1080

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
	char	*inner_color;
	char	*ground_colors;
	char	**in_color;
	char	**ground_color;
	int		*color_g;
	int		*color_inner;
    char    **game_map;
}				t_map;

typedef struct s_player
{
	char	player_direction;
    double  p_x;
    double  p_y;
}			t_player;

typedef	struct s_image
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	int		*no_image;
	int		*so_image;
	int		*we_image;
	int		*ea_image;
}			t_image;

typedef struct s_game_data
{
	t_player	*player;//player pozisyonuna ulaşmak için xd.
	t_image		*image;
	double		move_speed;
	double		rotate_speed;
	int			w_sixtyfour;
	int			h_sixtyfour;
	double		hit;//çarpıp çarmadığını kontrol eden değer.
	double		ray_x;
	double		ray_y;
	double		plane_x;// kamera vektörleri bize fov u ayarlıyorlar.
	double		plane_y;
	double		wall_x;
	double		wall_y;
	double		dir_x;// kamera başlangıç ve yönlendirme karakterin işte hangi yöne bakıcağını belirlediğimiz arkadaşlar bu değişkenler.
	double		dir_y;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		sidedist_x;
	double		sidedist_y;
	int			step_x;
	int			step_y;
	int			side;
	double		wall_dist;
	int			draw_start;
	int			draw_end;
	int			line_height;
	double		wallx;
	int			mx;
	int			my;
	int			colour;
	double		pixel_cal;
	double		pixel_nbr;
}				t_game_data;


typedef struct s_data
{
	t_map		*map;
	t_player	*player;
	t_game_data	*game_data;
	t_image		*image;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*mlx_window;
	void		*mlx_img;
	void		*no_wall;
	void		*so_wall;
	void		*we_wall;
	void		*ea_wall;
    char		*buffer;
	int			ground;
	int			inner;
}            t_data;


//Main func.
void    read_file(char *path, t_data *data);
void	check_map_wall(char **map);
void	error_check_file(t_data *data, int count);
int		screen_fill(t_data	*data);
void	setupgame(t_game_data *map);

//General utils
void	error_print(char *error_msg);
void	free_double_array(char **free_array);
int 	double_strlen(char **str);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_color(int *color_rgb);

//screen func :
void	wallcheck(t_game_data *game);
void	hitcheck(t_game_data *map, t_map *data);
void	get_dist(t_game_data *map, t_data *data);
void	set_image_values(t_game_data *map);
void	draw_image(t_game_data *map, t_data *data, int i);


//game : utils func.
void	setup_game(t_game_data *map);
void	add_game_image(t_game_data *map, t_data *data);

//map : utils func.
int 	check_file_extention(char *path);
int		lenght_find(char *path);
void	fill_one(t_data *data);

//macro func.
int     macro_select(char *str, t_data *data);
t_bool	fillstruct(t_data *data);
t_bool	mapstr(t_data *data);
t_bool  select_direction(t_data *data);

#endif