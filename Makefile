SRCS = ./src/main.c \
		./src/utils/general_utils.c ./src/utils/map_utils.c src/utils/game_utils.c ./src/utils/color_utils.c \
		./src/map_func/map_parser.c ./src/map_func/error_check_file.c \
		./src/macro_func/macro_main.c ./src/macro_func/macro_func.c \
		./src/screen/screen_fill.c ./src/screen/draw_image.c ./src/screen/screen_check.c \
		./src/key_hook/move_camera.c ./src/key_hook/move_hero.c ./src/key_hook/move_hook.c \

NAME = Cub3D
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g 
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx
RM = rm -rf
LIBFT = ./libft/libft.a
MINILIBX = ./minilibx/libmlx.a
GET_NEXT_LINE = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

all: ${NAME}

$(NAME): $(SRCS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(LFLAGS) $(SRCS) $(LIBFT) $(MINILIBX) $(GET_NEXT_LINE) -o $(NAME)
	@echo "<3 uWu <3 GO ! <3 uWu <3"

$(LIBFT):
	@make -C ./libft

$(MINILIBX):
	@make -C ./minilibx

clean: 
	@make -C ./libft clean
	@make -C ./minilibx clean

fclean:
	@${RM} $(NAME)
	@make -C ./libft fclean
	@make -C ./minilibx clean

re: fclean all

.PHONY: all bonus fclean re 
