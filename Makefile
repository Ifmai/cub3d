SRCS = ./src/main.c
		./src/utils/utils.C
		./src/map_func/map_parse.c
		./src/macro_func/macro_main.c ./src/macro_func/struct_macro.c

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-g
RM = rm -rf
LIBFT = ./libft/libft.a
GET_NEXT_LINE = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

all: $(LIB) $(LIBFT) ${NAME} 


$(NAME): $(SRCS) ${LIBFT}
	$(CC) $(CFLAGS) $(SRCS) $(GET_NEXT_LINE) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C ./libft

fclean:
	@${RM} $(NAME)
	@make -C ./libft fclean

re: fclean all

.PHONY: all bonus fclean re 
