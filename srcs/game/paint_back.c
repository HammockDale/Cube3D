/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:54:05 by esylva            #+#    #+#             */
/*   Updated: 2022/03/29 16:48:02 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->window->addr + (y * data->window->line_length +
		x * (data->window->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_back(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (i < W_PANEL)
	{
		while (j < H_PANEL / 2)
		{
			my_mlx_pixel_put(data, i, j, data->cloud->trgb);
			j++;
		}
		while (j < H_PANEL)
		{
			my_mlx_pixel_put(data, i, j, data->ground->trgb);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_back_bonus(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < W_PANEL)
	{
		while (j < H_PANEL / 2)
		{
			my_mlx_pixel_put(data, i, j, data->cloud->trgb);                //TODO
			j++;
		}
		while (j < H_PANEL)
		{
			my_mlx_pixel_put(data, i, j, data->ground->trgb);               //TODO
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_draw_2D_obj(t_data *data, int x, int y, int size, int color)
{
	int a;
	int b;
	
	a = 0;
	while (a < size)
	{
		b = 0;
		while (b < size)
		{
			my_mlx_pixel_put(data, x + a, x + b, color);
			b++;
		}
		a++;
	}
}

void	ft_put_minimap(t_data *data)
{
	int beg_x;
	int beg_y;
	int x;
	int y;

	ft_draw_2D_obj(data, 0, 0, W_MAP, 0xf6ff00);
	beg_x = W_MAP/2 - (data->map->size_x / 2) * SCALE;
	beg_y = W_MAP/2 - (data->map->size_y / 2) * SCALE;

	y = 0;
	while (y < data->map->size_y)
	{
		x = 0;
		while (x < data->map->size_x)
		{
			if (data->map->coord[y][x] == ' ')
				ft_draw_2D_obj(data, beg_x + x * SCALE, beg_y + y * SCALE, SCALE, 0);
			else if (data->map->coord[y][x] == '1')
				ft_draw_2D_obj(data, beg_x + x * SCALE, beg_y + y * SCALE, SCALE, 0xcacaca);
			else if (data->map->coord[y][x] == 'N' || data->map->coord[y][x] == 'W'
				|| data->map->coord[y][x] == 'S' || data->map->coord[y][x] == 'E')
				ft_draw_2D_obj(data, beg_x + x * SCALE, beg_y + y * SCALE, SCALE, 0x476aff);
			else if (data->map->coord[y][x] == 'D')
				ft_draw_2D_obj(data, beg_x + x * SCALE, beg_y + y * SCALE, SCALE, 0xffffff);
			else if (data->map->coord[y][x] == 'L')
				ft_draw_2D_obj(data, beg_x + x * SCALE, beg_y + y * SCALE, SCALE, 0x06f666);
			else if (data->map->coord[y][x] == 'X')
				ft_draw_2D_obj(data, beg_x + x * SCALE, beg_y + y * SCALE, SCALE, 0xff0000);
			x++;
		}
		y++
	}

	
	if ()


}