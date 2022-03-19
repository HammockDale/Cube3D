/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:46:37 by esylva            #+#    #+#             */
/*   Updated: 2022/03/19 18:39:58 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_win_init(t_data *data)
{
	// ft_coords(data);
	data->window->mlx_ptr = mlx_init();
	data->window->win_ptr = mlx_new_window(data->window->mlx_ptr, data->window->weight, data->window->height, "cub3D");
	// ft_img_init(map);
	// ft_put_img_to_win(data);
	// mlx_loop_hook(data->window->mlx_ptr, render_next_frame, data->window);
	// mlx_hook(data->window->win_ptr, 2, 0, key_hook, data->window);
	mlx_hook(data->window->win_ptr, 17, 0L, ft_exit, data);
	mlx_loop(data->window->mlx_ptr);
	return (0);
}

// void	ft_img_init(t_map *map)
// {
// 	map->ground.loc = "./img/ground.xpm";
// 	map->ground.image = mlx_xpm_file_to_image(map->mlx_ptr, map->ground.loc,
// 			&map->size_x, &map->size_y);
// 	map->ground.addr = mlx_get_data_addr(map->ground.image, &map->ground.bitpp,
// 			&map->ground.line, &map->ground.endian);
// 	map->wall.loc = "./img/wall.xpm";
// 	map->wall.image = mlx_xpm_file_to_image(map->mlx_ptr, map->wall.loc,
// 			&map->size_x, &map->size_y);
// 	map->wall.addr = mlx_get_data_addr(map->wall.image, &map->wall.bitpp,
// 			&map->wall.line, &map->wall.endian);
// 	map->fish.loc = "./img/fish.xpm";
// 	map->fish.image = mlx_xpm_file_to_image(map->mlx_ptr, map->fish.loc,
// 			&map->size_x, &map->size_y);
// 	map->fish.addr = mlx_get_data_addr(map->fish.image, &map->fish.bitpp,
// 			&map->fish.line, &map->fish.endian);
// 	map->cat.loc = "./img/smallcat.xpm";
// 	map->cat.image = mlx_xpm_file_to_image(map->mlx_ptr, map->cat.loc,
// 			&map->size_x, &map->size_y);
// 	map->cat.addr = mlx_get_data_addr(map->cat.image, &map->cat.bitpp,
// 			&map->cat.line, &map->cat.endian);
// 	map->gate.loc = "./img/gate.xpm";
// 	map->gate.image = mlx_xpm_file_to_image(map->mlx_ptr, map->gate.loc,
// 			&map->size_x, &map->size_y);
// 	map->gate.addr = mlx_get_data_addr(map->gate.image, &map->gate.bitpp,
// 			&map->gate.line, &map->gate.endian);
// }


// void	ft_put_img_to_win(t_map *map)
// {
// 	map->y = 0;
// 	while (map->y < map->height)
// 	{
// 		map->x = 0;
// 		while (map->x < map->weight)
// 		{
// 			ft_put_by_sym(map);
// 			map->x++;
// 		}
// 		map->y++;
// 	}
// }

// void	ft_put_by_sym(t_map *map)
// {
// 	if (map->coords[map->y][map->x] == (int) '1')
// 		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->wall.image,
// 			map->x * map->size_x, map->y * map->size_y);
// 	else if (map->coords[map->y][map->x] == (int) '0')
// 		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->ground.image,
// 			map->x * map->size_x, map->y * map->size_y);
// 	else if (map->coords[map->y][map->x] == (int) 'C')
// 		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->fish.image,
// 			map->x * map->size_x, map->y * map->size_y);
// 	else if (map->coords[map->y][map->x] == (int) 'E')
// 		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->gate.image,
// 			map->x * map->size_x, map->y * map->size_y);
// 	else if (map->coords[map->y][map->x] == (int) 'P')
// 	{
// 		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->cat.image,
// 			map->x * map->size_x, map->y * map->size_y);
// 		map->p_x = map->x;
// 		map->p_y = map->y;
// 	}
// }

// void ft_coords(t_data *data)
// {
// 	int i;

// 	i = 0;
// 	data->window->coords = calloc(sizeof(int*) , 8);
// 	while (i < 8)
// 	{
// 		data->window->coords[i] = (int *)calloc(sizeof(int), 10);
// 	}
// 	data->window->coords[0] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};   
// 	data->window->coords[1] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 1};
// 	data->window->coords[2] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 1};   
// 	data->window->coords[3] = {1, 0, 1, 0, 0, 0, 1, 0, 0, 1};   
// 	data->window->coords[4] = {1, 0, 1, 0, 0, 0, 0, 0, 0, 1};   
// 	data->window->coords[5] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 1};  
// 	data->window->coords[6] = {1, 0, 1, 0, 0, 0, 0, N, 0, 1};   
// 	data->window->coords[7] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};   

// }
