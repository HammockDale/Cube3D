/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:45:19 by esylva            #+#    #+#             */
/*   Updated: 2022/05/04 08:46:40 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_data	*ft_data_init(t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->window = NULL;
	data->map = NULL;
	data->player = NULL;
	data->ground = NULL;
	data->cloud = NULL;
	data->north = NULL;
	data->east = NULL;
	data->south = NULL;
	data->west = NULL;
	data->door = NULL;
	data->loot = NULL;
	data->mmap = NULL;
	data->wall = NULL;

	data->collet = NULL;
	data->bonus = BONUS;
	if (ft_init_main_struct(data))
		return (NULL);
	return (data);
}

int	ft_init_main_struct(t_data *data)
{
	data->window = ft_init_window(data->window);
	if (!data->window)
		return (INIT_ERROR);
	data->player = ft_init_player(data->player);
	if (!data->player)
		return (INIT_ERROR);
	data->wall = ft_init_wall(data->wall);
	if (!data->wall)
		return (INIT_ERROR);
	return (0);
}

t_image	*ft_init_image(t_image *wall)
{
	wall = (t_image *)malloc(sizeof(t_image));
	if (!wall)
		return (NULL);
	wall->loc = NULL;
	wall->image = NULL;
	wall->addr = NULL;
	wall->line = 0;
	wall->bitpp = 0;
	wall->endian = 0;
	wall->trgb = 0;
	wall->size_x = 0;
	wall->size_y = 0;
	return (wall);
}

int	ft_init_map(t_data *data, int weght, int hight)
{
	data->map = (t_map *)malloc(sizeof(t_map));
	if (!data->map)
		return (MAP_ERROR);
	data->map->coord = NULL;
	data->map->exit = 0;
	data->map->loot = 0;
	data->map->x = 0;
	data->map->y = 0;
	data->map->size_x = weght;
	data->map->size_y = hight;
	data->map->coord = (char **)malloc(sizeof(char *) * (hight + 1));
	if (!data->map->coord)
	{
		free(data->map);
		data->map = NULL;
		return (MAP_ERROR);
	}
	data->map->coord[hight] = NULL;
	return (0);
}

t_window	*ft_init_window(t_window *window)
{
	window = (t_window *)malloc(sizeof(t_window));
	if (!window)
		return (NULL);
	window->mlx_ptr = NULL;
	window->win_ptr = NULL;
	window->img = NULL;
	window->coord = NULL;
	window->bits_per_pixel = 32;
	window->line_length = 0;
	window->endian = 0;
	return (window);
}

t_player	*ft_init_player(t_player *player)
{
	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->look = -1;
	player->pos_x = 0;
	player->pos_y = 0;
	player->dirX = -1;
	player->dirY = 0;
	player->planeX = 0;
	player->planeY = 0.66;
	player->time = 0;
	player->oldTime = 0;
	return (player);
}

t_wall	*ft_init_wall(t_wall *wall)
{
	wall = (t_wall *)malloc(sizeof(t_wall));
	if (!wall)
		return (NULL);
	wall->f_door = 0;
	wall->wall = 0;
	wall->tmp = 0;
	wall->kx = 0;
	wall->ky = 0;
	wall->dx = 0;
	wall->dy = 0;
	return (wall);
}