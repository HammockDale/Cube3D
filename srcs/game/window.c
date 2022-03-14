/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:46:37 by esylva            #+#    #+#             */
/*   Updated: 2021/10/26 23:46:40 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_win_init(t_map *map)
{
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->weight * 50, map->height
			* 50, "So long");
	ft_img_init(map);
	ft_put_img_to_win(map);
	mlx_loop_hook(map->mlx_ptr, render_next_frame, map);
	mlx_hook(map->win_ptr, 2, 0, key_hook, map);
	mlx_hook(map->win_ptr, 17, 0L, ft_exit, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}

void	ft_img_init(t_map *map)
{
	map->ground.loc = "./img/ground.xpm";
	map->ground.image = mlx_xpm_file_to_image(map->mlx_ptr, map->ground.loc,
			&map->size_x, &map->size_y);
	map->ground.addr = mlx_get_data_addr(map->ground.image, &map->ground.bitpp,
			&map->ground.line, &map->ground.endian);
	map->wall.loc = "./img/wall.xpm";
	map->wall.image = mlx_xpm_file_to_image(map->mlx_ptr, map->wall.loc,
			&map->size_x, &map->size_y);
	map->wall.addr = mlx_get_data_addr(map->wall.image, &map->wall.bitpp,
			&map->wall.line, &map->wall.endian);
	map->fish.loc = "./img/fish.xpm";
	map->fish.image = mlx_xpm_file_to_image(map->mlx_ptr, map->fish.loc,
			&map->size_x, &map->size_y);
	map->fish.addr = mlx_get_data_addr(map->fish.image, &map->fish.bitpp,
			&map->fish.line, &map->fish.endian);
	map->cat.loc = "./img/smallcat.xpm";
	map->cat.image = mlx_xpm_file_to_image(map->mlx_ptr, map->cat.loc,
			&map->size_x, &map->size_y);
	map->cat.addr = mlx_get_data_addr(map->cat.image, &map->cat.bitpp,
			&map->cat.line, &map->cat.endian);
	map->gate.loc = "./img/gate.xpm";
	map->gate.image = mlx_xpm_file_to_image(map->mlx_ptr, map->gate.loc,
			&map->size_x, &map->size_y);
	map->gate.addr = mlx_get_data_addr(map->gate.image, &map->gate.bitpp,
			&map->gate.line, &map->gate.endian);
}

void	ft_put_img_to_win(t_map *map)
{
	map->y = 0;
	while (map->y < map->height)
	{
		map->x = 0;
		while (map->x < map->weight)
		{
			ft_put_by_sym(map);
			map->x++;
		}
		map->y++;
	}
}

void	ft_put_by_sym(t_map *map)
{
	if (map->coords[map->y][map->x] == (int) '1')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->wall.image,
			map->x * map->size_x, map->y * map->size_y);
	else if (map->coords[map->y][map->x] == (int) '0')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->ground.image,
			map->x * map->size_x, map->y * map->size_y);
	else if (map->coords[map->y][map->x] == (int) 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->fish.image,
			map->x * map->size_x, map->y * map->size_y);
	else if (map->coords[map->y][map->x] == (int) 'E')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->gate.image,
			map->x * map->size_x, map->y * map->size_y);
	else if (map->coords[map->y][map->x] == (int) 'P')
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->cat.image,
			map->x * map->size_x, map->y * map->size_y);
		map->p_x = map->x;
		map->p_y = map->y;
	}
}
