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
	int	x;
	int	y;
double a, b;

	y = data->map->y;
	x = data->map->x;
	if (data->map->coord[y - 1][x] == '0' || data->map->coord[y - 1][x] == 'L'
		|| data->map->coord[y - 1][x] == 'X')
	y--;
	

	b = data->player->pos_x;
	a = data->player->pos_y;
	if (data->map->coord[(int)(floor)(y - SPEED * cos(data->player->look))][(int)(floor)(x)] != '1')
		data->player->pos_y -= SPEED * cos(data->player->look);
	if (data->map->coord[(int)(floor)(y)][(int)(floor)(x + SPEED  * sin(data->player->look))] != '1')
		data->player->pos_x += SPEED  * sin(data->player->look);;
	ft_paint(data);
}

void		ft_str_left(t_data *data)
{
	int	x;
	int	y;

	y = data->map->y;
	x = data->map->x;
	if (data->map->coord[y][x - 1] == '0' || data->map->coord[y][x - 1] == 'L'
		|| data->map->coord[y][x - 1] == 'X')
	x--;

	double a, b;
	double d;
	d = data->player->look + (double)(PI / 2);
	// printf ("a = %f\n", data->player->look);
	// 	printf ("a = %f\n", a);
	if (d > 2 * PI)
		d = d - 2 * PI;
	// if (d < 0)
	// 	d = d + 2 * PI;
	b = data->player->pos_x;
	a = data->player->pos_y;
	if (data->map->coord[(int)(floor)(a + SPEED * cos(d))][(int)(floor)(b)] != '1')
		data->player->pos_y += SPEED * cos(d);
	if (data->map->coord[(int)(floor)(a)][(int)(floor)(b - SPEED  * sin(d))] != '1')
		data->player->pos_x -= SPEED  * sin(d);;
	ft_paint(data);

}

void		ft_go_backward(t_data *data)
{
	int	x;
	int	y;

	y = data->map->y;
	x = data->map->x;
	if (data->map->coord[y + 1][x] == '0' || data->map->coord[y + 1][x] == 'L'
		|| data->map->coord[y + 1][x] == 'X')
	y++;

double a, b;
	double d;
	d = data->player->look;
	// printf ("a = %f\n", data->player->look);
	// 	printf ("a = %f\n", a);
	// if (d > 2 * PI)
	// 	d = d - 2 * PI;
	// if (d < 0)
	// 	d = d + 2 * PI;
	b = data->player->pos_x;
	a = data->player->pos_y;
	if (data->map->coord[(int)(floor)(a + SPEED * cos(d))][(int)(floor)(b)] != '1')
		data->player->pos_y += SPEED * cos(d);
	if (data->map->coord[(int)(floor)(a)][(int)(floor)(b - SPEED  * sin(d))] != '1')
		data->player->pos_x -= SPEED  * sin(d);;
	ft_paint(data);

}

void		ft_str_right(t_data *data)
{
	int	x;
	int	y;

	y = data->map->y;
	x = data->map->x;
	if (data->map->coord[y][x + 1] == '0' || data->map->coord[y][x + 1] == 'L'
		|| data->map->coord[y][x + 1] == 'X')
	x++;

	double a, b;
	double d;
	d = data->player->look + (double)(PI / 2);
	// printf ("a = %f\n", data->player->look);
	// 	printf ("a = %f\n", a);
	if (d > 2 * PI)
		d = d - 2 * PI;
	if (d < 0)
		d = d + 2 * PI;
	b = data->player->pos_x;
	a = data->player->pos_y;
	if (data->map->coord[(int)(floor)(a - SPEED * cos(d))][(int)(floor)(b)] != '1')
		data->player->pos_y -= SPEED * cos(d);
	if (data->map->coord[(int)(floor)(a)][(int)(floor)(b + SPEED  * sin(d))] != '1')
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
	// data->player->pos_x +=20;
	ft_paint(data);


}

void		ft_turn_left(t_data *data)
{
	data->player->look -= PI / 60;
	if (data->player->look < 0)
	{
		data->player->look += 2 * PI;
	}
	// data->player->pos_x +=20;
	ft_paint(data);
}
