/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:46:37 by esylva            #+#    #+#             */
/*   Updated: 2022/04/20 18:14:44 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_win_init(t_data *data)
{
	data->window->mlx_ptr = mlx_init();
	if (!data->bonus)
		data->window->win_ptr = mlx_new_window(data->window->mlx_ptr,
			W_PANEL, H_PANEL, "cub3D without bonuses");
	else
		data->window->win_ptr = mlx_new_window(data->window->mlx_ptr,
			W_PANEL, H_PANEL, "CUB3D with BONUSES!");
	data->window->img = mlx_new_image(data->window->mlx_ptr, W_PANEL, H_PANEL);
	data->window->addr = mlx_get_data_addr(data->window->img,
		&data->window->bits_per_pixel, &data->window->line_length,
		&data->window->endian);
	ft_img_init(data);
	return (0);
}

void	ft_paint(t_data *data)
{
	// mlx_clear_window(data->window->mlx_ptr, data->window->win_ptr);
	if (!data->bonus)
		ft_back(data);
	else
		ft_back_bonus(data);
	ft_cast_rays(data, 65432);
	if (data->bonus)
		ft_put_minimap(data);	
	//TODO//
	 mlx_put_image_to_window(data->window->mlx_ptr, data->window->win_ptr, data->window->img, 0, 0);
}


// void	ft_draw_2D_wall(t_data *data)
// {

// }


// void    ft_import_imgxpm(t_data *data, int *texture, char *path, t_img *img)

// {
//     int y;
//     int x;

//     img->img = mlx_xpm_file_to_image(data->window->mlx_ptr, path, &img->img_w, &img->img_h);
//     if (img->img == NULL)
//         ft_err_exit("xpm file error");
//     img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->endian);
//     y = 0;
//     while (y < img->img_h)
//     {
//         x = 0;
//         while (x < img->img_w)
//         {
//             texture[img->img_w * y + x] = img->data[img->img_w * y + x];
//             x++;
//         }
//         y++;
//     }
//     mlx_destroy_image(data->window->mlx_ptr, img->img);
// }


void	ft_cast_rays(t_data *data, int color)
{
	// ft_import_imgxpm(data, data->north->image glb->texturs[0], glb->map.north_texture, &img);
	(void)color;
	int i;
	double d;

	i = 0;
	d = data->player->look - (double)(PI / 2);

	if (d < 0)
		d = d + 2 * PI;

// printf("\n\n ugol = %f\n\n", d);

	float	start = (d  - UGOL / 2) ;// - [половина угла обзора]; // начало веера лучей
	float	end = d + UGOL / 2;//ray.dir + [половина угла обзора]; // край веера лучей
	double	a, b;
	double	wall;
	while (start <= end)
	{
		data->player->ray_x  = data->player->pos_x; // каждый раз возвращаемся в точку начала
		data->player->ray_y = data->player->pos_y;
		while (data->map->coord[(int)(data->player->ray_y)][(int)(data->player->ray_x)] != '1')
		{
			data->player->ray_x += cos(start)  / ONE_SIZE;
			data->player->ray_y += sin(start)  / ONE_SIZE;
			// my_mlx_pixel_put(data, data->player->ray_x * ONE_SIZE, data->player->ray_y * ONE_SIZE, color);
		}
	
/* здесь нужна функция вертикального кастинга*/
	int j;
		double gip;
	j = H_PANEL / 2;
	gip = 0;
		wall = 0;
		a = data->player->ray_x - data->player->pos_x;
		b = data->player->ray_y - data->player->pos_y;
		gip = sqrt((a*a) + (b*b));
	
		if (gip > 0)
			wall =  H_PANEL / 2 + (1 / gip)  * 200;
			// wall =   H_PANEL/2 * 1/(gip*cos(d));
		// printf("a = %f b = %f ", a, b  );
		// if ((int)(tan(start)*1000) && (fabs)(tan(start)) < 0.99)
		{
			
				// wall = (double)(((sqrt(a*a + b*b) * ONE_SIZE )* (fabs)(tan(start))));//   * ONE_SIZE * ONE_SIZE;
		// printf("gip = %f wall = %f gip = %f statrt = %f tan = %f\n", gip, wall, sqrt(a*a + b*b), start, tan( start));
		}
		// mlx_loop(data->window->mlx_ptr);
		// data->ground->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
		// 	data->ground->loc, &data->ground->size_x, &data->ground->size_y);
	
		// mlx_put_image_to_window(data->window->mlx_ptr, data->window->win_ptr, data->north->image , i, j);
		// mlx_loop(data->window->mlx_ptr);
			int *text;
			text = (int*)data->north->addr;
			int *text2;
			text2 = (int*)data->south->addr;
			int *text3;
			text3 = (int*)data->west->addr;
			int *text4;
			text4 = (int*)data->east->addr;
		double tmp;
			// tmp =1 +  ((1 / gip)  * 200) / ONE_SIZE;
			tmp =  (1 / (gip)  * 200) + 1;
			// tmp = 1 + (wall) / ONE_SIZE;
		// 	printf("i = %d, tmp= %d ", i, tmp);
		// 	j = 30;
			// my_mlx_pixel_put(data, i, j, text[(int)i  % 50 * j ]  );
		int n = 0;
		int m = 0;
		int k, k2;
		int k3, k4;
		// int l = 2;
		// while(n < 100)
		// {
		// 	while (m < 100)
		// 	{
		// 		k = (int)m / tmp * 50  + n / tmp % 50;
		// 		my_mlx_pixel_put(data, n+300, m+300, text2[k ]  );
		// 		m++;
		// 		// printf("int = %d",k);
		// 	}
		// 	m = 0;
		// 	n++;
		// }
		// printf("wall= %f", wall);
		// printf("data->player->ray_y = %f", data->player->ray_y);
		double da, db, dx, dy, c, d;
			da = modf((a), &dx);
			db = modf((b), &dy);
			dx = modf(( data->player->ray_x ), &c);
			dy = modf(( data->player->ray_y ), &c);
			d = modf(fabs( gip ), &c);
			// printf("%f ", dx);
		// 	while (j < wall && j < 1000)
		// {
		// 	my_mlx_pixel_put(data, i, j, 0x0FF00FF);
		// while (j < wall && j < 1000)
		// {
		// 	m = j;
		// 	n = i ;
			
		// 	// printf(" j = %d, tmp = %f", j, tmp);
		// 	// k = m / tmp * ONE_SIZE  + n / tmp % ONE_SIZE;
		// 	// k =( m % (int)(da * 100) )+ n  % ONE_SIZE * ONE_SIZE;
		// 	k =  m  / tmp + (int)(da * ONE_SIZE) * ONE_SIZE;
		// 	k2 =  m  / tmp  + (int)(db * ONE_SIZE) * ONE_SIZE;
		// 	k = (int)(dy * j) % ONE_SIZE + (int)(da * ONE_SIZE) * ONE_SIZE ;
		// 	// k =m  / tmp  % ONE_SIZE + (int)(da * ONE_SIZE) * ONE_SIZE;
		// 	// if( ( db < 0.05 || db > 0.95))
		// 	// my_mlx_pixel_put(data, i, j, 0x0FF00FF);
		// 	k2 = (int)(m / tmp)  + (int)(dy * ONE_SIZE) * ONE_SIZE;
		// 	k =   (int)(( (j - H_PANEL / 2))  / (tmp ) * ONE_SIZE ) / 2 * ONE_SIZE + (int)(dx * ONE_SIZE) - 300;
		// 	k2 =   (int)(((j - H_PANEL / 2) )  / (tmp ) * ONE_SIZE ) / 2 * ONE_SIZE + (int)(dy * ONE_SIZE);
		// 	// printf("k = %d ", k);
		// 	k3 = (int)( m / tmp) % ONE_SIZE + (int)(da * ONE_SIZE) * ONE_SIZE;
		// 	// k4 =  m  / tmp % ONE_SIZE + (int)(db * ONE_SIZE) * ONE_SIZE;
		// 	k4 = (int)data->player->pos_x & (ONE_SIZE - 1);
		// 	// printf(" 1 %d 2 %d", k, m / tmp);
		// 	if (k <= k2 )
		// 		my_mlx_pixel_put(data, n, m, text[k]);
		// 		// my_mlx_pixel_put(data, n, m, text[(int)(data->player->ray_x * data->player->ray_y * j /ONE_SIZE)]  );
		// 	else 
		// 	// if (data->player->ray_x > 0)
		// 	// if (data->player->ray_x  < data->player->ray_y)
		// 		my_mlx_pixel_put(data, n, m, text2[k2]);
		// 		// my_mlx_pixel_put(data, n, m, text2[k4 * ONE_SIZE + k4 ]  );
		// 	// else
		// 	// 	my_mlx_pixel_put(data, n, m, text3[k3 ]  );
		// 	// else 
		// 	// else
			
		// 	j += 1;
		// }

			// mlx_put_image_to_window(data->window->mlx_ptr, data->window->win_ptr, data->north->image, 0, 0);
		wall -= H_PANEL / 2;
		// double tmp;
			// tmp =  ((1 / gip)  * 200) + 1;
			// tmp = wall ;
			int l;
			
			if (wall >= H_PANEL / 2)
			{
				wall = H_PANEL / 2;
			
			}
			l = wall;
			// printf("wall = %f d = %f ",data->player->look, d);
			k2 =  (int)((tmp - wall)/ tmp * ONE_SIZE) / 2* ONE_SIZE  + (int)(dy * ONE_SIZE) ;
			k3 =  (int)((tmp - wall)/ tmp * ONE_SIZE) / 2* ONE_SIZE  - (int)(dy * ONE_SIZE) ;
			k = (int)( (tmp - wall)/tmp * ONE_SIZE) / 2 * ONE_SIZE + (int)(dx * ONE_SIZE) ;
			k4 = (int)( (tmp - wall)/tmp * ONE_SIZE) / 2 * ONE_SIZE - (int)(dx * ONE_SIZE) ;
			// printf("k1 = %d, k2 = %d, k3 = %d, k4 = %d ", k, k2, k3, k4);
			// printf("dx = %f, dy = %f\n", dx, dy);
		while (wall  > -l)
		{
			n = i ;
			// if (wall >= H_PANEL / 2)
			// {
			// 	wall = H_PANEL / 2;
			// 	l = - wall;
			// }
			// my_mlx_pixel_put(data, i, H_PANEL / 2 - wall, 0x0FF00FF);
			m =  H_PANEL / 2 - wall;
			k2 =  (int)((tmp - wall)/ tmp * ONE_SIZE) / 2* ONE_SIZE  + (int)(dy * ONE_SIZE) ;
			k3 =  (int)((tmp - wall)/ tmp * ONE_SIZE) / 2* ONE_SIZE  + (int)(da * ONE_SIZE) ;
			k = (int)( (tmp - wall)/tmp * ONE_SIZE) / 2 * ONE_SIZE + (int)(dx * ONE_SIZE) ;
			k4 = (int)( (tmp - wall)/tmp * ONE_SIZE) / 2 * ONE_SIZE + (int)(db * ONE_SIZE) ;
			// if ( dy > 0.95 && k <= k2 && (int)(data->player->look + PI/2) % (int)(2*PI) < PI)
			if (dy > 0.98 )
				my_mlx_pixel_put(data, i, H_PANEL / 2 - wall, text[k ]  );
			else 
			if (dx > 0.98)
			// // if (dx > 0.95 && (int)(data->player->look + PI) % (int)(2*PI) < PI )
				my_mlx_pixel_put(data, i, H_PANEL / 2 - wall, text2[k2 ]  );
			else
			if (dy < 0.02)
			// if ( (int)(data->player->look + PI/2) % (int)(2*PI) > PI)
			 	my_mlx_pixel_put(data, i, H_PANEL / 2 - wall, text3[k3 ]  );
			else
				my_mlx_pixel_put(data, i, H_PANEL / 2 - wall, text4[k4 ]  );
			wall--;
		}
		i++;
		j = H_PANEL / 2;
		start += UGOL / (W_PANEL);//[угол обзора] / [количество лучей];
	}
	// printf("\n");
}

void ft_draw_(t_data *data, double x, double y, int color)
{
	double	i;
	double	j;

	i = x;
	j = y;
// printf("i = %f && j = %f\n", i, j);
	// data->window->addr = mlx_get_data_addr(data->window->img, &data->window->bits_per_pixel, &data->window->line_length, &data->window->endian);
	while (i <= x + ONE_SIZE)
	{
		while (j <= y + ONE_SIZE)
		{
			my_mlx_pixel_put(data, (int)i + (x  * ONE_SIZE), (int)(j + y  * ONE_SIZE), color);
			j++;
		}
		j =  y;
		i++;
	}
	// mlx_put_image_to_window(data->window->mlx_ptr, data->window->win_ptr, data->window->img, 0, 0);

}

void ft_draw_player(t_data *data, int color)
{
	
			my_mlx_pixel_put(data, (int)(data->player->pos_x  * ONE_SIZE), (int)(data->player->pos_y * ONE_SIZE), color);

		ft_cast_rays(data, color);
}


void	ft_draw_2D_woll(t_data *data)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	// printf("x = %d %d, y = %d %d\n", data->map->x, data->map->size_x, data->map->y, data->map->size_y);
	while(j < data->map->size_y)
	{
		while (i < data->map->size_x)
		{
			if (data->map->coord[j][i] == '1')
			ft_draw_(data, i, j, WOLL);
			i++;
		}
		j++;
		i = 0;
	}
}

// int	mouse_move(int keycode, t_data *data)
// {
// 	static int old = 350;
// 	(void)data;
// 	printf("keycode = %d", keycode);
// 	// if (old < keycode)
// 	// 	ft_turn_left(data);
// 	// if (old > keycode)
// 	// 	ft_turn_right(data);
// 	old = keycode;
// 	return(keycode);
// }

int	key_kb_hook(int keycode, t_data *data)
{
	if (keycode == GO_FORWARD)
		ft_go_forward(data);
	else if (keycode == STR_LEFT)
		ft_str_left(data);
	else if (keycode == GO_BACKWARD)
		ft_go_backward(data);
	else if (keycode == STR_RIGHT)
		ft_str_right(data);
	else if (keycode == TURN_RIGHT)
		ft_turn_right(data);
	else if (keycode == TURN_LEFT)
		ft_turn_left(data);
	else if (keycode == USE)
		ft_open_door(data);
// printf("keycode = %d\n", keycode);
	if (keycode == EXIT)
	{
		mlx_destroy_window(data->window->mlx_ptr, data->window->win_ptr);
		ft_exit(data, 0);
	}
	return (keycode);
}


void	ft_img_init(t_data *data)
{
	if (data->bonus)
		ft_img_bonus_init(data);
	// data->north->loc = "/Users/hdale/Desktop/cubic/camila.XPM";
	data->north->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
		data->north->loc, &data->north->size_x, &data->north->size_y);
	data->north->addr = mlx_get_data_addr(data->north->image,
		&data->north->bitpp, &data->north->line, &data->north->endian);
	data->south->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
		data->south->loc, &data->south->size_x, &data->south->size_y);
	data->south->addr = mlx_get_data_addr(data->south->image,
		&data->south->bitpp, &data->south->line, &data->south->endian);
	data->west->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
		data->west->loc, &data->west->size_x, &data->west->size_y);
	data->west->addr = mlx_get_data_addr(data->west->image,
		&data->west->bitpp, &data->west->line, &data->west->endian);
	data->east->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
		data->east->loc, &data->east->size_x, &data->east->size_y);
	data->east->addr = mlx_get_data_addr(data->east->image,
		&data->east->bitpp, &data->east->line, &data->east->endian);
}

void	ft_img_bonus_init(t_data *data)
	{
		data->ground->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
			data->ground->loc, &data->ground->size_x, &data->ground->size_y);
		data->ground->addr = mlx_get_data_addr(data->ground->image,
			&data->ground->bitpp, &data->ground->line, &data->ground->endian);
		data->cloud->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
			data->cloud->loc, &data->cloud->size_x, &data->cloud->size_y);
		data->cloud->addr = mlx_get_data_addr(data->cloud->image,
			&data->cloud->bitpp, &data->cloud->line, &data->cloud->endian);
	}






// void	process_input(t_all *all)
// {
// 	mlx_hook(all->mlx.window, 2, 1L << 0, key_press, all);
// 	mlx_hook(all->mlx.window, 3, 1L << 1, key_release, all);
// 	mlx_hook(all->mlx.window, 9, 1L << 21, refresh, all);
// 	mlx_hook(all->mlx.window, 17, 1L << 17, destroy_window, all);
// }
