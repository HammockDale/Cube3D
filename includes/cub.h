/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:46:58 by marvin            #+#    #+#             */
/*   Updated: 2022/03/14 12:46:58 by marvin           ###   ########.fr       */
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

typedef struct s_map
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		weight;
	int		height;
	int		**coords;
	int		loot;
	int		exit;
	int		player;
	int		p_x;
	int		p_y;
	int		moves;
	t_image	ground;
	t_image	wall;
	t_image	fish;
	t_image	cat;
	t_image	gate;
	int		x;
	int		y;
	int		size_x;
	int		size_y;
}				t_map;

void	ft_cube(char *carta, t_map *map);

/*checer.c */
int		ft_name_check(char *carta);

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
