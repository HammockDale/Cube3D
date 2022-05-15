NAME = cub3D

HEADER = includes/cub.h

INCLUDES = -I includes -I libft -I mlx

SRC_DIR = srcs/

SRCS_F = main1.c init.c free.c

PARS_DIR = parser/

PARS_F = parser.c parser_utils.c checker.c parser_utils2.c

PARSER =  $(addprefix $(PARS_DIR), $(PARS_F))

GAME_DIR = game/

GAME_F = window1.c action.c ft_wasd1.c paint_back.c ft_button.c cast_rays.c

GAME = $(addprefix $(GAME_DIR), $(GAME_F))

SRC_F =  $(addprefix $(SRC_DIR), $(SRCS_F) $(PARSER) $(GAME))

OBJ_DIR = obj/

OBJ_F = $(addprefix $(OBJ_DIR), $(SRCS_F) $(PARS_F) $(GAME_F))

OBJ = $(patsubst %.c, %.o, $(SRC_F))

CC = gcc -g

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

MAKE_MLX = make -sC mlx

LINK_MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -lz

MAKE_LIBFT = make -C libft

LINK_LIBFT = -Llibft -lft

all: init $(NAME)

init:
	@$(MAKE_LIBFT)
	@$(MAKE_MLX)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	
%.o : %.c $(HEADER)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(INCLUDES) $(OBJ) $(LINK_LIBFT) $(LINK_MLX) -o $@
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
