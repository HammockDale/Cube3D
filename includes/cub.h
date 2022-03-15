/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:46:58 by esylva            #+#    #+#             */
/*   Updated: 2022/03/14 12:46:58 by esylva           ###   ########.fr       */
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
# include "../Libft/libft.h"

typedef struct s_image
{
	void	*image;
	void	*addr;
	int		line;
	int		bitpp;
	int		endian;
	char	*loc;
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
	int	i;
}				t_sprite;

typedef struct s_data
{
	struct s_window;
	struct s_map;
	struct s_player;	
	struct s_image;
	t_image	ground;
	t_image	cloud;
	t_image	NO;
	t_image	EA;
	t_image	SO;
	t_image	WE;	
	struct s_strite;
}				t_data;
	
/* main.c */
void	ft_cube(char *carta, t_map *map);

/* checker.c */
int		ft_name_check(char *carta);


/*other*/
int		key_hook(int keycode, t_map *map);
int		ft_player_action(t_map *map);
void	ft_render_1(t_map *map);
int		render_next_frame(t_map *map);
void	ft_change_ground(t_map *map);

void	ft_put_img_to_win(t_map *map);
void	ft_img_init(t_map *map);
int		ft_win_init(t_map *map);
void	ft_put_by_sym(t_map *map);
void	ft_save_player_position(t_map *map);
void	ft_check_player_position(t_map *map);
void	ft_check_sym(int x, int y, t_map *map);
void	ft_check_lines(t_map *map);
void	ft_make_map(t_map *map, int fd);
void	ft_make_coords(t_map *map);

void	ft_check_rect(int sh, int ne, char *line);
void	ft_parce_map(t_map *map, int fd);
t_map	*ft_map_init(t_map *map);

void	ft_name_check(char *carta);
void	ft_free_all(t_map *map);
int		ft_exit(int keycode);
#endif
