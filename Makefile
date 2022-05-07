NAME = cub3D

HEADER = includes/cub.h
INCLUDES = -I includes -I libft -I mlx -I minilibx_opengl_20191021
# INCLUDES = -I includes -I libft -I/usr/include -Imlx_linux -O3

SRC_DIR = srcs/
SRCS_F = main1.c init.c free.c

PARS_DIR = parser/
PARS_F = parser.c parser_utils.c checker.c parser_utils2.c 
PARSER =  $(addprefix $(PARS_DIR), $(PARS_F))

GAME_DIR = game/
GAME_F = window1.c action.c ft_wasd1.c paint_back.c ft_button.c cast_rays.c
# GAME_F = window.c action.c ft_wasd.c paint_back.c ft_button.c cast_rays.c

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

# MAKE_MLX = make -sC mlx_linux
LINK_MLX = -Lmlx -lmlx -framework OpenGL   -lz   -framework AppKit
# LINK_MLX = -Lmlx_linux -lmlx_linux -L/usr/lib -lXext -lX11 -lm -lz

MAKE_LIBFT = make -sC libft
LINK_LIBFT = -Llibft -lft

MAKE_OPENGL = make -sC minilibx_opengl_20191021

all: init $(NAME)

init:
	@$(MAKE_LIBFT)
	@$(MAKE_MLX)
	@$(MAKE_OPENGL)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
#	@$(CC) $(FLAGS) $(INCLUDES) $(OBJ) $(LINK_MLX) $(LINK_LIBFT) -o $@
	$(CC) $(INCLUDES) $(OBJ) $(LINK_LIBFT) $(LINK_MLX) -o $@
	@echo Done!

clean:
	@$(RM) $(OBJ_F)
	@$(RM) $(OBJ)
	@$(MAKE_MLX) clean
	@$(MAKE_LIBFT) clean
	@$(MAKE_OPENGL) clean

fclean: clean
	@$(MAKE_LIBFT) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all init clean flcean re
