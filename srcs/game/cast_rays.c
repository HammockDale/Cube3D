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
	data->wall->wall = H_PANEL / 3 /(sqrt(powf(data->player->ray_x
		- data->player->pos_x, 2) + powf(data->player->ray_y
		- data->player->pos_y, 2)) ) ;
	data->wall->wall /= sin(data->player->look - start);
	if (data->wall->wall >= H_PANEL / 2)
		data->wall->wall = H_PANEL / 2;
	data->wall->dx = modf(data->player->ray_x, &data->wall->tmp);
	data->wall->dy = modf(data->player->ray_y, &data->wall->tmp);
	data->wall->tmp = data->wall->wall;
	while (data->wall->wall  > -data->wall->tmp)
	{
		data->wall->ky = ((int)((data->wall->tmp - data->wall->wall) / data->wall->tmp * ONE_SIZE) / 2 + 0)* ONE_SIZE + (int)(data->wall->dy * ONE_SIZE);
		data->wall->kx = ((int)((data->wall->tmp - data->wall->wall) / data->wall->tmp * ONE_SIZE) / 2 + 0)* ONE_SIZE + (int)(data->wall->dx * ONE_SIZE);
		if (data->wall->f_door == 1)
			my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - data->wall->wall), ((int*)data->door->addr)[data->wall->kx]);
		else if ((data->wall->dy < 0.02 || data->wall->dy > 0.98) && (data->wall->dx > 0.98 || data->wall->dx < 0.02))
		{
			return (0);
			my_mlx_pixel_put(data, i, H_PANEL / 2 - data->wall->wall,  0);
		}
		else if (data->wall->dy > 0.98)
			my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - data->wall->wall), ((int*)data->north->addr)[data->wall->kx]);
		else if (data->wall->dx > 0.98)
			my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - data->wall->wall), ((int*)data->south->addr)[data->wall->ky]);
		else if (data->wall->dy < 0.02)
			my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - data->wall->wall), ((int*)data->west->addr)[data->wall->kx]);
		else if (data->wall->dx < 0.02)	
			my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - data->wall->wall), ((int*)data->east->addr)[data->wall->ky]);
		data->wall->wall--;
	}
	data->wall->f_door = 0;
	return (1);
}

// void	ft_cycle_paint_walls(double	wall, 	double	tmp, )
// {
// 	while (wall  > -tmp)
// 	{
// 		ky = ((int)((tmp - wall) / tmp * ONE_SIZE) / 2 + 0)* ONE_SIZE + (int)(dy * ONE_SIZE);
// 		kx = ((int)((tmp - wall) / tmp * ONE_SIZE) / 2 + 0)* ONE_SIZE + (int)(dx * ONE_SIZE);
// 		if (data->wall->f_door == 1)
// 			my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - wall), ((int*)data->door->addr)[kx]);
// 		else if ((dy < 0.02 || dy > 0.98) && (dx > 0.98 || dx < 0.02))
// 		{
// 			return (0);
// 			my_mlx_pixel_put(data, i, H_PANEL / 2 - wall,  0);
// 		}
// 		else if (dy > 0.98)
// 			my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - wall), ((int*)data->north->addr)[kx]);
// 		else if (dx > 0.98)
// 			my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - wall), ((int*)data->south->addr)[ky]);
// 		else if (dy < 0.02)
// 			my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - wall), ((int*)data->west->addr)[kx]);
// 		else if (dx < 0.02)	
// 			my_mlx_pixel_put(data, i, (int)(H_PANEL / 2 - wall), ((int*)data->east->addr)[ky]);
		
// 		wall--;
// 	}	
// }




void	ft_cast_rays(t_data *data, char str)
{
	int i;
	double	start;
	double	end;
	
	data->wall->f_door = 0;
		(void)str;
	i = W_PANEL / 2;
	start  = data->player->look - (double)(PI / 2) ;
	end = data->player->look - (double)(PI / 2) + UGOL / 2;
	while (start <= end)
	{
		data->player->ray_x  = data->player->pos_x; 
		data->player->ray_y = data->player->pos_y;
		
// ft1()
		while ( data->map->coord[(int)(data->player->ray_y)][(int)(data->player->ray_x)] != '1')
		{
			if (data->map->coord[(int)(data->player->ray_y)][(int)(data->player->ray_x)] == 'D')
			{
				data->wall->f_door = 1;
				break;
			}
// ft2()
			data->player->ray_x += cos(start)  / ONE_SIZE / 4;
			data->player->ray_y += sin(start)  / ONE_SIZE / 4;
		}
		if (str == '1')
		{
			if (!ft_walls_paint(data, i, start))
			{
				i--;
				end += UGOL / (W_PANEL);
			}
		}
		i++;
		start += UGOL / (W_PANEL);
	}
	
	i = W_PANEL / 2;
	start  = data->player->look - (double)(PI / 2);
	end = data->player->look - (double)(PI / 2) - UGOL / 2;
	while (start >= end)
	{
		data->player->ray_x  = data->player->pos_x; 
		data->player->ray_y = data->player->pos_y;
		
// ft1()
		while ( data->map->coord[(int)(data->player->ray_y)][(int)(data->player->ray_x)] != '1')
		{
			if (data->map->coord[(int)(data->player->ray_y)][(int)(data->player->ray_x)] == 'D')
			{
				data->wall->f_door = 1;
				break;
			}
// ft2()
			data->player->ray_x += cos(start)  / ONE_SIZE / 4;
			data->player->ray_y += sin(start)  / ONE_SIZE / 4;
		}
		if (str == '1')
		{
			if (!ft_walls_paint(data, i, start))
			{
				i++;
				end -= UGOL / (W_PANEL);
			}
		}
		i--;
		start -= UGOL / (W_PANEL);
	}
}
