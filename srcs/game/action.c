/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:42:45 by esylva            #+#    #+#             */
/*   Updated: 2022/05/14 16:35:03 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	mouse_move(int x, int y, t_data *data)
{
	static int	mouse_x = W_PANEL / 2;
	static int	mouse_y = H_PANEL / 2;

	if (x > 0 && x < W_PANEL && y > 0 && y < H_PANEL)
	{
		mlx_mouse_hide(data->window->mlx_ptr, data->window->win_ptr);
		data->player->look -= ((double)(PI / 2) / (W_PANEL / 2) * (mouse_x - x));
		ft_paint(data);
	}
	else
		mlx_mouse_show();
	if (y > H_PANEL / 4 && y < H_PANEL / 4 * 3 )
		mlx_mouse_move(data->window->win_ptr, mouse_x, mouse_y);
	return (0);
}

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