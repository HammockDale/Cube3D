NAME = cub3D

HEADER = includes/cub.h

INCLUDES = -I includes -I libft -I mlx

SRCS = srcs/main.c\
		init.c\
		pacer/*.c\
		game/*.c


CC = gcc -g
# CC = gcc
FLAGS = -Wall -Werror -Wextra

RM = rm -rf

MAKE_MLX = make -sC mlx
LINK_MLX = -lmlx -framework OpenGL -framework AppKit

MAKE_LIBFT = make -sC Libft
LINK_LIBFT = -Llibft -lft

all: init $(NAME)

init:
	@$(MAKE_LIBFT)
	@$(MAKE_MLX)


$(NAME): $(SRCS) $(HEADER)

	@$(CC) $(FLAGS) $(INCLUDES) $(SRCS) $(LINK_MLX) $(LINK_LIBFT) -o $@

clean:
	@$(MAKE_MLX) clean
	@$(MAKE_LIBFT) clean

fclean:
	@$(MAKE_LIBFT) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all init clean flcean re
