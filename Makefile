SRCS = ./src/main.c \
		./src/utils/general_utils.c ./src/utils/map_utils.c \
		./src/map_func/map_parser.c \
		./src/macro_func/macro_main.c ./src/macro_func/macro_func.c
NAME = Cub3D
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
LIBFT = ./libft/libft.a
GET_NEXT_LINE = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

all: ${NAME}

$(NAME): $(SRCS) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(GET_NEXT_LINE) -o $(NAME)
	@echo "<3 uWu <3 GO ! <3 uWu <3"

$(LIBFT):
	@make -C ./libft

fclean:
	@${RM} $(NAME)
	@make -C ./libft fclean

re: fclean all

.PHONY: all bonus fclean re 
