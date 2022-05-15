/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:46:27 by hdale             #+#    #+#             */
/*   Updated: 2022/05/12 19:41:37 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_cycle_paint_walls(t_data *data, int i)
{
	if (data->wall->f_door == 1)
		my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - data->wall->wall),
			((int*)data->door->addr)[data->wall->kx]);
	else if ((data->wall->dy < 0.02 || data->wall->dy > 0.98)
		&& (data->wall->dx > 0.98 || data->wall->dx < 0.02))
	{
		return (0);
		my_mlx_pixel_put(data, i, H_PANEL / 2 - data->wall->wall, 0);
	}
	else if (data->wall->dy > 0.98)
		my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - data->wall->wall),
			((int*)data->north->addr)[data->wall->kx]);
	else if (data->wall->dx > 0.98)
		my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - data->wall->wall),
			((int*)data->south->addr)[data->wall->ky]);
	else if (data->wall->dy < 0.02)
		my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - data->wall->wall),
			((int*)data->west->addr)[data->wall->kx]);
	else if (data->wall->dx < 0.02)
		my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - data->wall->wall),
			((int*)data->east->addr)[data->wall->ky]);
	data->wall->wall--;
	return (1);
}

int	ft_walls_paint(t_data *data, int i, double start)
{
	data->wall->wall = H_PANEL / 3 / (sqrt(powf(data->player->ray_x
					- data->player->pos_x, 2) + powf(data->player->ray_y
					- data->player->pos_y, 2)));
	data->wall->wall /= sin(data->player->look - start);
	if (data->wall->wall >= H_PANEL / 2)
		data->wall->wall = H_PANEL / 2;
	data->wall->dx = modf(data->player->ray_x, &data->wall->tmp);
	data->wall->dy = modf(data->player->ray_y, &data->wall->tmp);
	data->wall->tmp = data->wall->wall;
	while (data->wall->wall > -data->wall->tmp)
	{
		data->wall->ky = ((int)((data->wall->tmp - data->wall->wall)
					/ data->wall->tmp * ONE_SIZE) / 2 + 0) * ONE_SIZE
			+ (int)(data->wall->dy * ONE_SIZE);
		data->wall->kx = ((int)((data->wall->tmp - data->wall->wall)
					/ data->wall->tmp * ONE_SIZE) / 2 + 0) * ONE_SIZE
			+ (int)(data->wall->dx * ONE_SIZE);
		if (!ft_cycle_paint_walls(data, i))
		{
			return (0);
		}
	}
	data->wall->f_door = 0;
	return (1);
}

void	ft_rais(t_data *data, double start)
{
	data->player->ray_x = data->player->pos_x;
	data->player->ray_y = data->player->pos_y;
	while (data->map->coord[(int)(data->player->ray_y)][(int)
		(data->player->ray_x)] != '1')
	{
		if (data->map->coord[(int)(data->player->ray_y)][(int)
			(data->player->ray_x)] == 'D')
		{
			data->wall->f_door = 1;
			break ;
		}
		data->player->ray_x += cos(start) / ONE_SIZE / 4;
			data->player->ray_y += sin(start) / ONE_SIZE / 4;
	}
}

void	ft_cast_rays2(t_data *data, int i, double start, double end)
{
	i = W_PANEL / 2;
	start = data->player->look - (double)(PI / 2);
	end = data->player->look - (double)(PI / 2) - UGOL / 2;
	while (start >= end)
	{
		ft_rais(data, start);
		if (!ft_walls_paint(data, i, start))
		{
			i++;
			end -= UGOL / (W_PANEL);
		}
		i--;
		start -= UGOL / (W_PANEL);
	}
}

void	ft_cast_rays(t_data *data)
{
	int		i;
	double	start;
	double	end;

	data->wall->f_door = 0;
	i = W_PANEL / 2;
	start = data->player->look - (double)(PI / 2);
	end = data->player->look - (double)(PI / 2) + UGOL / 2;
	while (start <= end)
	{
		ft_rais(data, start);
		if (!ft_walls_paint(data, i, start))
		{
			i--;
			end += UGOL / (W_PANEL);
		}
		i++;
		start += UGOL / (W_PANEL);
	}
	ft_cast_rays2(data, i, start, end);
}
