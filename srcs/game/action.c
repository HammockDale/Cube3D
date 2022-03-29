/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:42:45 by esylva            #+#    #+#             */
/*   Updated: 2022/03/29 09:09:15 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// static void	move_render(t_all *all, int *walk_turn, int i)
// {
// 	*walk_turn = i;
// 	move_player(all, &all->player);
// 	render(all);
// }

// int	key_press(int keycode, t_all *all)
// {
// 	if (keycode == W_KEYM || keycode == W_KEYL)
// 		move_render(all, &all->player.walk_dir, +1);
// 	if (keycode == S_KEYM || keycode == S_KEYL)
// 		move_render(all, &all->player.walk_dir, -1);
// 	if (keycode == D_KEYM || keycode == D_KEYL)
// 		move_render(all, &all->player.walk_dir_side, +1);
// 	if (keycode == A_KEYM || keycode == A_KEYL)
// 		move_render(all, &all->player.walk_dir_side, -1);
// 	if (keycode == RIGHT_ARROW_KEYM || keycode == RIGHT_ARROW_KEYL)
// 		move_render(all, &all->player.turn_dir, +1);
// 	if (keycode == LEFT_ARROW_KEYM || keycode == LEFT_ARROW_KEYL)
// 		move_render(all, &all->player.turn_dir, -1);
// 	if (keycode == ESC_KEYM || keycode == ESC_KEYL)
// 		destroy_window(all);
// 	return (1);
// }

// int	key_release(int keycode, t_all *all)
// {
// 	if (keycode == W_KEYM || keycode == W_KEYL)
// 		all->player.walk_dir = 0;
// 	if (keycode == S_KEYM || keycode == S_KEYL)
// 		all->player.walk_dir = 0;
// 	if (keycode == D_KEYM || keycode == D_KEYL)
// 		all->player.walk_dir_side = 0;
// 	if (keycode == A_KEYM || keycode == A_KEYL)
// 		all->player.walk_dir_side = 0;
// 	if (keycode == RIGHT_ARROW_KEYM || keycode == RIGHT_ARROW_KEYL)
// 		all->player.turn_dir = 0;
// 	if (keycode == LEFT_ARROW_KEYM || keycode == LEFT_ARROW_KEYL)
// 		all->player.turn_dir = 0;
// 	return (1);
// }

// static int	refresh(t_all *all)
// {
// 	render(all);
// 	return (1);
// }

// void	process_input(t_all *all)
// {
// 	mlx_hook(all->mlx.window, 2, 1L << 0, key_press, all);
// 	mlx_hook(all->mlx.window, 3, 1L << 1, key_release, all);
// 	mlx_hook(all->mlx.window, 9, 1L << 21, refresh, all);
// 	mlx_hook(all->mlx.window, 17, 1L << 17, destroy_window, all);
// }

// int	key_hook(int keycode, t_map *map)
// {
// 	if (keycode == 2 && (map->coords[map->p_y][map->p_x + 1] != '1'))
// 		map->p_x++;
// 	else if (keycode == 0 && (map->coords[map->p_y][map->p_x - 1] != '1'))
// 		map->p_x--;
// 	else if (keycode == 13 && (map->coords[map->p_y - 1][map->p_x] != '1'))
// 		map->p_y--;
// 	else if (keycode == 1 && (map->coords[map->p_y + 1][map->p_x] != '1'))
// 		map->p_y++;
// 	else if (keycode == 53)
// 		ft_exit(keycode);
// 	if (keycode == 2 || keycode == 0 || keycode == 13 || keycode == 1)
// 		map->moves++;
// 	ft_player_action(map);
// 	ft_change_ground(map);
// 	printf("Moves count - %d\n", map->moves);
// 	return (0);
// }

// int	render_next_frame(t_map *map)
// {
// 	map->y = 0;
// 	while (map->y < map->height)
// 	{	
// 		map->x = 0;
// 		while (map->x < map->weight)
// 		{
// 			if (map->coords[map->y][map->x] != '1')
// 				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
// 					map->ground.image, map->x * map->size_x, map->y
// 					* map->size_y);
// 			else
// 				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
// 					map->wall.image, map->x * map->size_x, map->y
// 					* map->size_y);
// 			ft_render_1(map);
// 			map->x++;
// 		}
// 		map->y++;
// 	}
// 	return (0);
// }

// void	ft_render_1(t_map *map)
// {
// 	if (map->coords[map->y][map->x] == 'C')
// 		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
// 			map->fish.image, map->x * map->size_x, map->y
// 			* map->size_y);
// 	if (map->coords[map->y][map->x] == 'E')
// 		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
// 			map->gate.image, map->x * map->size_x, map->y
// 			* map->size_y);
// 	ft_player_action(map);
// }
/*
int	ft_player_action(t_map *map)
{	
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->cat.image, \
		map->p_x * map->size_x, map->p_y * map->size_y);
	return (0);
}
*/
