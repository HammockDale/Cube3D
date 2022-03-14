/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:42:45 by esylva            #+#    #+#             */
/*   Updated: 2021/10/27 17:42:52 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_change_ground(t_map *map)
{
	if (map->coords[map->p_y][map->p_x] == (int) 'C')
	{	
		(map->coords[map->p_y][map->p_x] = (int) '0');
		map->loot--;
	}
	if (!map->loot && map->coords[map->p_y][map->p_x] == (int) 'E')
	{
		printf("YOU WIN!");
		ft_free_all(map);
		exit(0);
	}
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 2 && (map->coords[map->p_y][map->p_x + 1] != '1'))
		map->p_x++;
	else if (keycode == 0 && (map->coords[map->p_y][map->p_x - 1] != '1'))
		map->p_x--;
	else if (keycode == 13 && (map->coords[map->p_y - 1][map->p_x] != '1'))
		map->p_y--;
	else if (keycode == 1 && (map->coords[map->p_y + 1][map->p_x] != '1'))
		map->p_y++;
	else if (keycode == 53)
		ft_exit(keycode);
	if (keycode == 2 || keycode == 0 || keycode == 13 || keycode == 1)
		map->moves++;
	ft_player_action(map);
	ft_change_ground(map);
	printf("Moves count - %d\n", map->moves);
	return (0);
}

int	render_next_frame(t_map *map)
{
	map->y = 0;
	while (map->y < map->height)
	{	
		map->x = 0;
		while (map->x < map->weight)
		{
			if (map->coords[map->y][map->x] != '1')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->ground.image, map->x * map->size_x, map->y
					* map->size_y);
			else
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->wall.image, map->x * map->size_x, map->y
					* map->size_y);
			ft_render_1(map);
			map->x++;
		}
		map->y++;
	}
	return (0);
}

void	ft_render_1(t_map *map)
{
	if (map->coords[map->y][map->x] == 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->fish.image, map->x * map->size_x, map->y
			* map->size_y);
	if (map->coords[map->y][map->x] == 'E')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->gate.image, map->x * map->size_x, map->y
			* map->size_y);
	ft_player_action(map);
}

int	ft_player_action(t_map *map)
{	
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->cat.image, \
		map->p_x * map->size_x, map->p_y * map->size_y);
	return (0);
}
