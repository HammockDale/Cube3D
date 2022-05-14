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

void	ft_sprite(t_data *data, double *k, int l)
{
	double a, b;
	double sprite;
	int *text;
	double	tmp;
	double	dx, dy;
	int dk;

	text = (int*)data->collet->addr;
	a = data->player->ray_x - data->player->pos_x;
	b = data->player->ray_y - data->player->pos_y;
	sprite = (1 / sqrt(powf(data->player->ray_x - data->player->pos_x, 2) + powf(data->player->ray_y - data->player->pos_y, 2)))  * 200;
	dx = modf(data->player->ray_x, &tmp);
	dy = modf(data->player->ray_y, &tmp);
	// d = modf(sprite, &tmp);

	(void)k;
	(void)l;
	// int		kx;
	// int		ky;
	// printf("k = % d ", k);
// mlx_put_image_to_window(data->window->mlx_ptr, data->window->win_ptr, data->collet->image , i, j);
// 	mlx_loop(data->window->mlx_ptr);

	// int i, j;
	// i = 0;
	// j = 0;
	// while(i < ONE_SIZE * 4 && i + k < l)
	// {
	// 	while (j < ONE_SIZE * 4)
	// 	{
			
	// 		my_mlx_pixel_put(data, i + k, j + H_PANEL / 4, text[i/ 4 + j/ 4  * ONE_SIZE]  );
	// 		// break;
	// 		j++;
	// 	}
	// 	j = 0;
	// 	i++;
	// 	// break;
	// }

	tmp = sprite;
	double wid;
	// wid = *k;
	wid = tmp;
	int n = l;
	double k1;
	k1 =*k;
	*k  += 1 / (sprite * 4);
	while (sprite  > -tmp)
	{
		// while (wid > -tmp)
		{
			// ky = (int)((tmp - sprite) / tmp * ONE_SIZE) / 2 * ONE_SIZE + (int)(dy * ONE_SIZE);
			// kx = (int)((tmp - sprite) / tmp * ONE_SIZE) / 2 * ONE_SIZE + (int)(dx * ONE_SIZE);
			// kx = (int)((tmp - sprite) / tmp * ONE_SIZE) / 2 * ONE_SIZE + (int)(d * ONE_SIZE);
			// if (dx > 0.2 && dx < 0.8)
			// {
			// 	if (wid < dx)
			// 	{
			// 		wid = dx;

			// 	}
			// 	// my_mlx_pixel_put(data, n, H_PANEL / 2 - sprite, ((int*)data->collet->addr)[kx]);
			// }
			// else
			// if (dy > 0.2 && dy < 0.8)
			// {
			// 	if (wid < dy)
			// 	{
			// 		wid = dy;

			// 	}
			// }

			// if (k1 <= 1)
			// {
					dk = (int)((tmp - sprite) / tmp * ONE_SIZE) / 2 * ONE_SIZE + (int)(*k * ONE_SIZE);
		// kx = (int)((tmp - sprite) / tmp * ONE_SIZE) / 2 * ONE_SIZE + (int)(d * ONE_SIZE);
		if (((int*)data->collet->addr)[dk] != 0)
			my_mlx_pixel_put(data, n, H_PANEL / 2 - sprite, ((int*)data->collet->addr)[dk]);
				// dk = (int)((tmp - sprite) / tmp * ONE_SIZE) / 2 * ONE_SIZE + (int)(*k * ONE_SIZE);
				// if (((int*)data->collet->addr)[dk] != 0)
				// 	my_mlx_pixel_put(data, l, H_PANEL / 2 - sprite, ((int*)data->collet->addr)[dk]);
				// wid--;
			// }
			// 	n++;
			// 	// if (*k <= 1 - 1 / (sprite * 4) )
			// 	(k1) += 1 / (sprite * 8);
			// else
			// if (dy > 0.2 && dy < 0.8)
			// {
			// 	if (((int*)data->collet->addr)[ky] != 0)
			// 	my_mlx_pixel_put(data, n, H_PANEL / 2 - sprite, ((int*)data->collet->addr)[ky]);
			// }
			// else
			// if (((int*)data->collet->addr)[dk] != 0)
			// {
			// 	my_mlx_pixel_put(data, n, H_PANEL / 2 - sprite, ((int*)data->collet->addr)[dk]);
				wid--;
			// 	// n++;
			// }
		}
		wid = tmp;
	k1 = *k;
	n = l;
	// wid = tmp;
	sprite--;
	}
}

int	ft_walls_paint(t_data *data, int i, double	start)
{
	double	wall;
	double	tmp;
	int		kx, ky;
	double	dx, dy;

	wall = H_PANEL / 2 /(sqrt(powf(data->player->ray_x - data->player->pos_x, 2) + powf(data->player->ray_y - data->player->pos_y, 2)) ) ;
	wall /= sin(data->player->look - start);
	if (wall >= H_PANEL / 2)
	{
		wall = H_PANEL / 2;
	}
	dx = modf(data->player->ray_x, &tmp);
	dy = modf(data->player->ray_y, &tmp);
	tmp = wall;
	while (wall  > -tmp)
	{
		ky = ((int)((tmp - wall) / tmp * ONE_SIZE) / 2 + 0)* ONE_SIZE + (int)(dy * ONE_SIZE) + 0;
		kx = ((int)((tmp - wall) / tmp * ONE_SIZE) / 2 + 0)* ONE_SIZE + (int)(dx * ONE_SIZE) + 0;
		// if ( dy > 0.95 && k <= k2 && (int)(data->player->look + PI/2) % (int)(2*PI) < PI)
		if ((dy < 0.02 || dy > 0.98) && (dx > 0.98 || dx < 0.02))
		{
			return (0);
			my_mlx_pixel_put(data, i, H_PANEL / 2 - wall,  0);
		}
		else
		if (dy > 0.98)
		{
			my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - wall), ((int*)data->north->addr)[kx]);
			data->buf[i * (int)(H_PANEL / 2 - wall)] = ((int*)data->north->addr)[kx];
		}
		else if (dx > 0.98)
		// // if (dx > 0.95 && (int)(data->player->look + PI) % (int)(2*PI) < PI )
		{
			my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - wall), ((int*)data->south->addr)[ky]);
			data->buf[i * (int)(H_PANEL / 2 - wall)] = ((int*)data->south->addr)[ky];
		}
		else if (dy < 0.02)
		// if ( (int)(data->player->look + PI/2) % (int)(2*PI) > PI)
		{	
			my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - wall), ((int*)data->west->addr)[kx]);
			data->buf[i * (int)(H_PANEL / 2 - wall)] = ((int*)data->west->addr)[kx];
		}
		else if (dx < 0.02)
		{	
			my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - wall), ((int*)data->east->addr)[ky]);
			data->buf[i * (int)(H_PANEL / 2 - wall)] = ((int*)data->east->addr)[ky];
		}
		wall--;
	}
	return (1);
	// int w = 0;
	// while (w < data->map->size_x * ONE_SIZE * data->map->size_y * ONE_SIZE)
	// {
	// 	my_mlx_pixel_put(data, w % (H_PANEL * data->map->size_x), w / (H_PANEL * data->map->size_x), data->buf[w]);
	// 	// if (w / (H_PANEL * data->map->size_x) )
	// 	w++;
		
	// }

}
// void	ft_cast_rays(t_data *data, int color, char str)
void	ft_cast_rays(t_data *data, char str)
{
	// ft_import_imgxpm(data, data->north->image glb->texturs[0], glb->map.north_texture, &img);
	// (void)color;
	double d;
	int i;

	i = 0;
	double l;
	l = 0;
	d = data->player->look - (double)(PI / 2);

	if (d < 0)
		d = d + 2 * PI;

	data->buf = ft_calloc(sizeof(int), data->map->size_x * ONE_SIZE * data->map->size_y * ONE_SIZE);
	if (!data->buf)
	{
		return;
	}

	

// printf("\n\n ugol = %f\n\n", d);

double	start;
double	end;

	start  = d;
	// double	start = (d  - UGOL * 1 / 2) ;// - [половина угла обзора]; // начало веера лучей
	end = d + UGOL / 2;//ray.dir + [половина угла обзора]; // край веера лучей
	
	while (start <= end)
	{
		data->player->ray_x  = data->player->pos_x; // каждый раз возвращаемся в точку начала
		data->player->ray_y = data->player->pos_y;
		
		// double sprite;
		// while(str == 'L')
		// {
		// 	data->player->ray_x += cos(start - 0)  / ONE_SIZE;
		// 	data->player->ray_y += sin(start - 0)  / ONE_SIZE;
		// 	if (str == 'L'&& data->map->coord[(int)(data->player->ray_y)][(int)(data->player->ray_x)] != '1')
		// 	{
		// 		sprite = (1 / sqrt(powf(data->player->ray_x - data->player->pos_x, 2) + powf(data->player->ray_y - data->player->pos_y, 2)))  * 200;
		// 		l += 1/ (sprite * 42);
		// 	// l += 0.3;
		// 		printf("asd");
		// 		break;
		// 	if (data->map->coord[(int)(data->player->ray_y)][(int)(data->player->ray_x)] != '1' )
		// 	{
		// 		ft_sprite(data, &l, i);
		// 	}
		// 	}
		// }
		while ( data->map->coord[(int)(data->player->ray_y)][(int)(data->player->ray_x)] != '1')
		{
			// if (data->player->ray_y < data->map->size_y && data->player->ray_x < data->map->size_x && data->player->ray_y > 0 && data->player->ray_x > 0)
			// {
			// 	l = 0;
			// 	break;
			// }
			// if (str == 'L'&& data->map->coord[(int)(data->player->ray_y)][(int)(data->player->ray_x)] == 'L')
			// {
			// 	if (start > (d  - UGOL / 2) )
			// 	{
			// 		ft_sprite(data, &l, i);
			// 		// str = 'i';
			// 		break;
			// 		// return ;
			// 	}
			// 	// else
			// 	// {
			// 	// 	sprite = (1 / sqrt(powf(data->player->ray_x - data->player->pos_x, 2) + powf(data->player->ray_y - data->player->pos_y, 2)))  * 200;
			// 	// 	l += 1/ (sprite * 2);
			// 	// 	break;
			// 	// }
			// 		// l = 0;
			// 	// str = 'a';
			// 	// }
			// // 	data->player->ray_x += cos(start)  ;
			// // data->player->ray_y += sin(start)  ;
			// 	// data->player->ray_x += 1;
			// 	// data->player->ray_y += 1;
			// 	// i += 1;
			// }
			// if (data->map->coord[(int)(data->player->ray_y)][(int)(data->player->ray_x)] == '1')
			// {
			// 	// l = 0;
			// 	break;
			// }
			// l = 0;
			data->player->ray_x += cos(start)  / ONE_SIZE / 4;
			data->player->ray_y += sin(start)  / ONE_SIZE / 4;
			// my_mlx_pixel_put(data, data->player->ray_x * ONE_SIZE, data->player->ray_y * ONE_SIZE, color);
		}
		if (data->player->ray_y < data->map->size_y && data->player->ray_x < data->map->size_x  && data->player->ray_y > 0 && data->player->ray_x > 0 && start > (d  - UGOL / 2) )
		{
/* здесь нужна функция вертикального кастинга*/
			if (str == '1')
			{
				if (!ft_walls_paint(data, i, start))
				{
					i--;
					end += UGOL / (W_PANEL);
				}
			}
			i++;
		}
		start += UGOL / (W_PANEL);//[угол обзора] / [количество лучей];
	}

// 	start  = d;
// 	// double	start = (d  - UGOL * 1 / 2) ;// - [половина угла обзора]; // начало веера лучей
// 	end = d - UGOL / 2;
// 	while (start >= end)
// 	{
// 		data->player->ray_x  = data->player->pos_x; // каждый раз возвращаемся в точку начала
// 		data->player->ray_y = data->player->pos_y;
		
// 		// double sprite;
// 		// while(str == 'L')
// 		// {
// 		// 	data->player->ray_x += cos(start - 0)  / ONE_SIZE;
// 		// 	data->player->ray_y += sin(start - 0)  / ONE_SIZE;
// 		// 	if (str == 'L'&& data->map->coord[(int)(data->player->ray_y)][(int)(data->player->ray_x)] != '1')
// 		// 	{
// 		// 		sprite = (1 / sqrt(powf(data->player->ray_x - data->player->pos_x, 2) + powf(data->player->ray_y - data->player->pos_y, 2)))  * 200;
// 		// 		l += 1/ (sprite * 42);
// 		// 	// l += 0.3;
// 		// 		printf("asd");
// 		// 		break;
// 		// 	if (data->map->coord[(int)(data->player->ray_y)][(int)(data->player->ray_x)] != '1' )
// 		// 	{
// 		// 		ft_sprite(data, &l, i);
// 		// 	}
// 		// 	}
// 		// }
// 		while ( data->map->coord[(int)(data->player->ray_y)][(int)(data->player->ray_x)] != '1')
// 		{
// 			// if (data->player->ray_y < data->map->size_y && data->player->ray_x < data->map->size_x && data->player->ray_y > 0 && data->player->ray_x > 0)
// 			// {
// 			// 	l = 0;
// 			// 	break;
// 			// }
// 			// if (str == 'L'&& data->map->coord[(int)(data->player->ray_y)][(int)(data->player->ray_x)] == 'L')
// 			// {
// 			// 	if (start > (d  - UGOL / 2) )
// 			// 	{
// 			// 		ft_sprite(data, &l, i);
// 			// 		// str = 'i';
// 			// 		break;
// 			// 		// return ;
// 			// 	}
// 			// 	// else
// 			// 	// {
// 			// 	// 	sprite = (1 / sqrt(powf(data->player->ray_x - data->player->pos_x, 2) + powf(data->player->ray_y - data->player->pos_y, 2)))  * 200;
// 			// 	// 	l += 1/ (sprite * 2);
// 			// 	// 	break;
// 			// 	// }
// 			// 		// l = 0;
// 			// 	// str = 'a';
// 			// 	// }
// 			// // 	data->player->ray_x += cos(start)  ;
// 			// // data->player->ray_y += sin(start)  ;
// 			// 	// data->player->ray_x += 1;
// 			// 	// data->player->ray_y += 1;
// 			// 	// i += 1;
// 			// }
// 			// if (data->map->coord[(int)(data->player->ray_y)][(int)(data->player->ray_x)] == '1')
// 			// {
// 			// 	// l = 0;
// 			// 	break;
// 			// }
// 			// l = 0;
// 			data->player->ray_x += cos(start)  / ONE_SIZE / 4;
// 			data->player->ray_y += sin(start)  / ONE_SIZE / 4;
// 			// my_mlx_pixel_put(data, data->player->ray_x * ONE_SIZE, data->player->ray_y * ONE_SIZE, color);
// 		}
// 		if (data->player->ray_y < data->map->size_y && data->player->ray_x < data->map->size_x  && data->player->ray_y > 0 && data->player->ray_x > 0 && start > (d  - UGOL / 2) )
// 		{
// /* здесь нужна функция вертикального кастинга*/
// 			if (str == '1')
// 			{
// 				if (!ft_walls_paint(data, i, start))
// 				{
// 					i--;
// 					end -= UGOL / (W_PANEL);
// 				}
// 			}
// 			i++;
// 		}
// 		start -= UGOL / (W_PANEL);//[угол обзора] / [количество лучей];
// 	}

}
