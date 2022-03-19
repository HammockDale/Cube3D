/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:46:58 by esylva            #+#    #+#             */
/*   Updated: 2022/03/19 14:53:21 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include "../libft/libft.h"

# define BONUS 0

# define ARGUMENT_OPEN_ERROR 1
# define INIT_ERROR 2
# define MAP_ERROR 3

typedef struct s_image
{
	void	*image;
	void	*addr;
	int		line;
	int		bitpp;
	int		endian;
	char	*loc;
	int		trgb;
}				t_image;

typedef struct s_player
{
	int		p_x;
	int		p_y;
	int		look;
}				t_player;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		weight;
	int		height;
	int		**coords;
}				t_window;

typedef struct s_map
{
	int		loot;
	int		exit;
	int		moves;
	int		x;
	int		y;
	int		size_x;
	int		size_y;
}				t_map;

typedef struct s_strite
{
	int			*i;
	t_image		*sprites;
	int			status;
}				t_sprite;

typedef struct s_data
{
	t_window		*window;
	t_map			*map;
	t_player		*player;	
	t_image			*ground;
	t_image			*cloud;
	t_image			*north;
	t_image			*east;
	t_image			*south;
	t_image			*west;
	t_sprite		*door;
	t_sprite		*loot;
	char			bonus;
}				t_data;
	
/* main.c */
int		ft_cube(char *carta, t_data *data);
int		ft_exit(int keycode);

/* checker.c */
int		ft_name_check(char *carta);

/* init.c */
t_data	*ft_data_init(t_data *data);
int		ft_init_main_struct(t_data *data);
t_image	*ft_init_image(t_image *wall);
int		ft_init_map(t_data *data, t_list *map, int weght, int hight);

/* parcer.c */
t_list	*ft_lstnew_m(char *content);
int		ft_parce_data(t_data *data, int fd);
int		ft_config(t_list **cub, t_data *data);
int		ft_parse_map(t_list *tmp, t_data *data);

/* parcer_utils.c */
int		ft_separate_textures(char *str, t_data *data);
int		ft_save_texture(char *str, t_image *wall);
int		ft_save_texture_c(char *str, t_image *wall, t_data *data);
int		ft_parsing_trgb(char *str, int *trgb);
int		ft_tind_map_begin(char *str);

/* parcer_utils2.c */
int	ft_empty_line(char *str);


/*other*/
// int		key_hook(int keycode, t_map *map);
// int		ft_player_action(t_map *map);
// void	ft_render_1(t_map *map);
// int		render_next_frame(t_map *map);
// void	ft_change_ground(t_map *map);

// void	ft_put_img_to_win(t_map *map);
// void	ft_img_init(t_map *map);
// int		ft_win_init(t_map *map);
// void	ft_put_by_sym(t_map *map);
// void	ft_save_player_position(t_map *map);
// void	ft_check_player_position(t_map *map);
// void	ft_check_sym(int x, int y, t_map *map);
// void	ft_check_lines(t_map *map);
// void	ft_make_map(t_map *map, int fd);
// void	ft_make_coords(t_map *map);

// void	ft_check_rect(int sh, int ne, char *line);

// t_map	*ft_map_init(t_map *map);

// void	ft_name_check(char *carta);
// void	ft_free_all(t_map *map);
#endif
