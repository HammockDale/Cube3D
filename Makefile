NAME = cub3D

HEADER = includes/cub.h
INCLUDES = -I includes -I libft -I mlx
# INCLUDES = -I includes -I libft

SRC_DIR = srcs/
SRCS_F = main.c init.c

PARS_DIR = parser/
PARS_F = parser.c parser_utils.c checker.c parser_utils2.c 
PARSER =  $(addprefix $(PARS_DIR), $(PARS_F))

GAME_DIR = game/
GAME_F = window.c action.c
GAME = $(addprefix $(GAME_DIR), $(GAME_F))

SRC_F =  $(addprefix $(SRC_DIR), $(SRCS_F) $(PARSER) $(GAME))

OBJ_DIR = obj/
OBJ_F = $(addprefix $(OBJ_DIR), $(SRCS_F) $(PARS_F) $(GAME_F))
OBJ = $(patsubst %.c, %.o, $(SRC_F))



CC = gcc -g
# CC = gcc
FLAGS = -Wall -Werror -Wextra

RM = rm -rf

MAKE_MLX = make -sC mlx
LINK_MLX = -lmlx -framework OpenGL -framework AppKit

MAKE_LIBFT = make -sC libft

LINK_LIBFT = -Llibft -lft

all: init $(NAME)

init:
	@$(MAKE_LIBFT)
	@$(MAKE_MLX)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o : %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(INCLUDES) $(LINK_MLX) $(LINK_LIBFT) $(OBJ) -o $@
# @$(CC) $(FLAGS) $(INCLUDES) $(LINK_LIBFT) $(OBJ) -o $@
	@echo Done!

clean:
	@$(RM) $(OBJ_F)
	@$(RM) $(OBJ)
	@$(MAKE_MLX) clean
	@$(MAKE_LIBFT) clean

fclean: clean
	@$(MAKE_LIBFT) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all init clean flcean re
