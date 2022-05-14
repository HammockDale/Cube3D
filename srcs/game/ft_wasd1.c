/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wasd1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:08:59 by hdale             #+#    #+#             */
/*   Updated: 2022/04/20 18:12:00 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		ft_go_forward(t_data *data)
{
	if (data->map->coord[(int)(floor)(data->player->pos_y - BARRIER * SPEED * cos(data->player->look))][(int)(floor)(data->player->pos_x)] != '1')
		data->player->pos_y -= SPEED * cos(data->player->look);
	if (data->map->coord[(int)(floor)(data->player->pos_y)][(int)(floor)(data->player->pos_x + BARRIER * SPEED  * sin(data->player->look))] != '1')
		data->player->pos_x += SPEED  * sin(data->player->look);;
	ft_paint(data);
}

void		ft_str_left(t_data *data)
{
	double d;

	d = data->player->look + (double)(PI / 2);
	if (d > 2 * PI)
		d = d - 2 * PI;
	if (data->map->coord[(int)(floor)(data->player->pos_y + BARRIER * SPEED * cos(d))][(int)(floor)(data->player->pos_x)] != '1')
		data->player->pos_y += SPEED * cos(d);
	if (data->map->coord[(int)(floor)(data->player->pos_y)][(int)(floor)(data->player->pos_x - BARRIER * SPEED  * sin(d))] != '1')
		data->player->pos_x -= SPEED  * sin(d);;
	ft_paint(data);

}

void		ft_go_backward(t_data *data)
{
	double d;

	d = data->player->look;
	if (data->map->coord[(int)(floor)(data->player->pos_y + BARRIER * SPEED * cos(d))][(int)(floor)(data->player->pos_x)] != '1')
		data->player->pos_y += SPEED * cos(d);
	if (data->map->coord[(int)(floor)(data->player->pos_y)][(int)(floor)(data->player->pos_x - BARRIER * SPEED  * sin(d))] != '1')
		data->player->pos_x -= SPEED  * sin(d);;
	ft_paint(data);

}

void		ft_str_right(t_data *data)
{
	double d;

	d = data->player->look + (double)(PI / 2);
	if (d > 2 * PI)
		d = d - 2 * PI;
	if (d < 0)
		d = d + 2 * PI;
	if (data->map->coord[(int)(floor)(data->player->pos_y - BARRIER * SPEED * cos(d))][(int)(floor)(data->player->pos_x)] != '1')
		data->player->pos_y -= SPEED * cos(d);
	if (data->map->coord[(int)(floor)(data->player->pos_y)][(int)(floor)(data->player->pos_x + BARRIER * SPEED  * sin(d))] != '1')
		data->player->pos_x += SPEED  * sin(d);;
	ft_paint(data);

}

void		ft_turn_right(t_data *data)
{
	data->player->look += PI / 60;
	if (data->player->look > 2 * PI)
	{
		data->player->look -= 2 * PI;
	}
	ft_paint(data);


}

void		ft_turn_left(t_data *data)
{
	data->player->look -= PI / 60;
	if (data->player->look < 0)
	{
		data->player->look += 2 * PI;
	}
	ft_paint(data);
}
