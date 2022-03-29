/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:54:05 by esylva            #+#    #+#             */
/*   Updated: 2022/03/29 16:07:13 by esylva           ###   ########.fr       */
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
printf("11\n");
		while (j < H_PANEL / 2)
		{
			my_mlx_pixel_put(data, i, j, data->cloud->trgb);
			j++;
		}
printf("12\n");
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