/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wasd1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:08:59 by hdale             #+#    #+#             */
/*   Updated: 2022/04/02 21:16:01 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		ft_go_forward(t_data *data)
{
	int	x;
	int	y;

	y = data->map->y;
	x = data->map->x;
	if (data->map->coord[y - 1][x] == '0' || data->map->coord[y - 1][x] == 'L'
		|| data->map->coord[y - 1][x] == 'X')
	y--;
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
}

void		ft_turn_right(t_data *data)
{
	(void)data;
}

void		ft_turn_left(t_data *data)
{
	(void) data;
}


void	ft_Pup(t_data *data)
{
	// (void)data;
	double a, b;
	double d;
	d = data->player->cameraX;

	b = data->player->pos_x;
	a = data->player->pos_y;
	if (data->map->coord[(int)(floor)(a - 0.2 * cos(d))][(int)(floor)(b)] != '1')
		data->player->pos_y -= 0.2 * cos(d);
	if (data->map->coord[(int)(floor)(a)][(int)(floor)(b + 0.2  * sin(d))] != '1')
		data->player->pos_x += 0.2  * sin(d);;
	ft_paint(data);
// 	if (var->per_y - 1 > 0 && var->map[var->per_y - 1][var->per_x] == '0')
// 	{
// 		var->map[var->per_y][var->per_x] = '0';
// 		var->per_y--;
// 		var->map[var->per_y][var->per_x] = 'P';
// 	}
// 	else if (var->per_y - 1 > 0
// 		&& var->map[var->per_y - 1][var->per_x] == 'C')
// 	{
// 		var->score += 1;
// 		var->map[var->per_y][var->per_x] = '0';
// 		var->per_y--;
// 		var->map[var->per_y][var->per_x] = 'P';
// 	}
// 	else if (var->map[var->per_y - 1][var->per_x] == 'A')
// 		ft_wrong(var);
// 	else if (var->per_y - 1 > 0 && var->max_score == var->score
// 		&& var->map[var->per_y - 1][var->per_x] == 'E')
// 	{
// 		ft_printf("Your score is %d\nYOU WIN!\n", var->score);
// 		ft_close();
// 	}
// 	ft_paint(var);
}

void	ft_Pleft(t_data *data)
{

	// data->player->pos_y += 0.2 * cos(d);
	// data->player->pos_x -= 0.2  * sin(d);
	// ft_paint(data);

	double a, b;
	double d;
	d = data->player->cameraX + (double)(PI / 2);
	// printf ("a = %f\n", data->player->cameraX);
	// 	printf ("a = %f\n", a);
	if (d > 2 * PI)
		d = d - 2 * PI;
	// if (d < 0)
	// 	d = d + 2 * PI;
	b = data->player->pos_x;
	a = data->player->pos_y;
	if (data->map->coord[(int)(floor)(a + 0.2 * cos(d))][(int)(floor)(b)] != '1')
		data->player->pos_y += 0.2 * cos(d);
	if (data->map->coord[(int)(floor)(a)][(int)(floor)(b - 0.2  * sin(d))] != '1')
		data->player->pos_x -= 0.2  * sin(d);;
	ft_paint(data);

// 	if (var->per_x - 1 > 0 && var->map[var->per_y][var->per_x - 1] == '0')
// 	{
// 		var->map[var->per_y][var->per_x] = '0';
// 		var->per_x--;
// 		var->map[var->per_y][var->per_x] = 'P';
// 	}
// 	else if (var->per_x - 1 > 0
// 		&& var->map[var->per_y][var->per_x - 1] == 'C')
// 	{
// 		var->score += 1;
// 		var->map[var->per_y][var->per_x] = '0';
// 		var->per_x--;
// 		var->map[var->per_y][var->per_x] = 'P';
// 	}
// 	else if (var->map[var->per_y][var->per_x - 1] == 'A')
// 		ft_wrong(var);
// 	else if (var->per_x - 1 > 0 && var->max_score == var->score
// 		&& var->map[var->per_y][var->per_x - 1] == 'E')
// 	{
// 		ft_printf("Your score is %d\nYOU WIN!\n", var->score);
// 		ft_close();
// 	}
// 	ft_paint(var);
}

void	ft_Pdown(t_data *data)
{
	// data->player->pos_y += 0.2 * cos(data->player->cameraX);
	// data->player->pos_x -= 0.2  * sin(data->player->cameraX);;
	// ft_paint(data);

double a, b;
	double d;
	d = data->player->cameraX;
	// printf ("a = %f\n", data->player->cameraX);
	// 	printf ("a = %f\n", a);
	// if (d > 2 * PI)
	// 	d = d - 2 * PI;
	// if (d < 0)
	// 	d = d + 2 * PI;
	b = data->player->pos_x;
	a = data->player->pos_y;
	if (data->map->coord[(int)(floor)(a + 0.2 * cos(d))][(int)(floor)(b)] != '1')
		data->player->pos_y += 0.2 * cos(d);
	if (data->map->coord[(int)(floor)(a)][(int)(floor)(b - 0.2  * sin(d))] != '1')
		data->player->pos_x -= 0.2  * sin(d);;
	ft_paint(data);


// 	if (var->per_y + 1 < var->size_y
// 		&& var->map[var->per_y + 1][var->per_x] == '0')
// 	{
// 		var->map[var->per_y][var->per_x] = '0';
// 		var->per_y++;
// 		var->map[var->per_y][var->per_x] = 'P';
// 	}
// 	else if (var->per_y + 1 < var->size_y
// 		&& var->map[var->per_y + 1][var->per_x] == 'C')
// 	{
// 		var->score += 1;
// 		var->map[var->per_y][var->per_x] = '0';
// 		var->per_y++;
// 		var->map[var->per_y][var->per_x] = 'P';
// 	}
// 	else if (var->map[var->per_y + 1][var->per_x] == 'A')
// 		ft_wrong(var);
// 	else if (var->per_y + 1 < var->size_y && var->max_score == var->score
// 		&& var->map[var->per_y + 1][var->per_x] == 'E')
// 	{
// 		ft_printf("Your score is %d\nYOU WIN!\n", var->score);
// 		ft_close();
// 	}
// 	ft_paint(var);
}

void	ft_Pright(t_data *data)
{

	// data->player->pos_y -= 0.2 * cos(d);
	// data->player->pos_x += 0.2  * sin(d);
	// ft_paint(data);

	double a, b;
	double d;
	d = data->player->cameraX + (double)(PI / 2);
	// printf ("a = %f\n", data->player->cameraX);
	// 	printf ("a = %f\n", a);
	if (d > 2 * PI)
		d = d - 2 * PI;
	if (d < 0)
		d = d + 2 * PI;
	b = data->player->pos_x;
	a = data->player->pos_y;
	if (data->map->coord[(int)(floor)(a - 0.2 * cos(d))][(int)(floor)(b)] != '1')
		data->player->pos_y -= 0.2 * cos(d);
	if (data->map->coord[(int)(floor)(a)][(int)(floor)(b + 0.2  * sin(d))] != '1')
		data->player->pos_x += 0.2  * sin(d);;
	ft_paint(data);


// 	if (var->per_x + 1 < var->size_x
// 		&& var->map[var->per_y][var->per_x + 1] == '0')
// 	{
// 		var->map[var->per_y][var->per_x] = '0';
// 		var->per_x++;
// 		var->map[var->per_y][var->per_x] = 'P';
// 	}
// 	else if (var->per_x + 1 < var->size_x
// 		&& var->map[var->per_y][var->per_x + 1] == 'C')
// 	{
// 		var->score += 1;
// 		var->map[var->per_y][var->per_x] = '0';
// 		var->per_x++;
// 		var->map[var->per_y][var->per_x] = 'P';
// 	}
// 	else if (var->map[var->per_y][var->per_x + 1] == 'A')
// 		ft_wrong(var);
// 	else if (var->per_x + 1 < var->size_x && var->max_score == var->score
// 		&& var->map[var->per_y][var->per_x + 1] == 'E')
// 	{
// 		ft_printf("Your score is %d\nYOU WIN!\n", var->score);
// 		ft_close();
// 	}
// 	ft_paint(var);
}

void	ft_Pclock(t_data *data)
{
	data->player->cameraX += PI / 60;
	if (data->player->cameraX > 2 * PI)
	{
		data->player->cameraX -= 2 * PI;
	}
	// data->player->pos_x +=20;
	ft_paint(data);
}

void	ft_Pconterclock(t_data *data)
{
	data->player->cameraX -= PI / 60;
	if (data->player->cameraX < 0)
	{
		data->player->cameraX += 2 * PI;
	}
	// data->player->pos_x +=20;
	ft_paint(data);
}
