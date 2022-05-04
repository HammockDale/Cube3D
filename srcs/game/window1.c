/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:46:37 by esylva            #+#    #+#             */
/*   Updated: 2022/05/04 09:34:56 by esylva           ###   ########.fr       */
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

	// printf("y = %f, x= %f\n", data->player->pos_y, data->player->pos_x );
	if (data->map->coord[(int)floor(data->player->pos_y )][(int)floor(data->player->pos_x )] == 'L')
	{
		data->map->coord[(int)floor(data->player->pos_y )][(int)floor(data->player->pos_x )] = '0';
	}
	if (data->map->coord[(int)ceil(data->player->pos_y )][(int)ceil(data->player->pos_x)] == 'L')
	{
		data->map->coord[(int)ceil(data->player->pos_y )][(int)ceil(data->player->pos_x )] = '0';
	}
	if (data->map->coord[(int)floor(data->player->pos_y )][(int)ceil(data->player->pos_x)] == 'L')
	{
		data->map->coord[(int)floor(data->player->pos_y )][(int)ceil(data->player->pos_x )] = '0';
	}
	if (data->map->coord[(int)ceil(data->player->pos_y )][(int)floor(data->player->pos_x )] == 'L')
	{
		data->map->coord[(int)ceil(data->player->pos_y )][(int)floor(data->player->pos_x)] = '0';
	}
	mlx_clear_window(data->window->mlx_ptr, data->window->win_ptr);
	if (!data->bonus)
		ft_back(data);
	else
		ft_back_bonus(data);
	ft_cast_rays(data, 65432, '1');
	if (data->bonus)
	{
		ft_cast_rays(data, 65432, 'L');
		ft_put_minimap(data);
	}
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

void	ft_sprite(t_data *data, double *k, int l)
{
	// double a, b;
	double sprite;
	// int *text;
	double	tmp;
	// double	dx, dy, d;

	// text = (int*)data->collet->addr;
	// a = data->player->ray_x - data->player->pos_x;
	// b = data->player->ray_y - data->player->pos_y;
	sprite = (1 / sqrt(powf(data->player->ray_x - data->player->pos_x, 2) + powf(data->player->ray_y - data->player->pos_y, 2)))  * 200;
	// dx = modf(data->player->ray_x, &tmp);
	// dy = modf(data->player->ray_y, &tmp);
	// d = modf(sprite, &tmp);

	(void)k;
	(void)l;
	int		kx;
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
	(*k) += 1/ (sprite * 4);
	while (sprite  > -tmp)
	{
		// ky = (int)((tmp - sprite) / tmp * ONE_SIZE) / 2 * ONE_SIZE + (int)(dy * ONE_SIZE);
		// kx = (int)((tmp - sprite) / tmp * ONE_SIZE) / 2 * ONE_SIZE + (int)(dx * ONE_SIZE);
		kx = (int)((tmp - sprite) / tmp * ONE_SIZE) / 2 * ONE_SIZE + (int)(*k * ONE_SIZE);
		// kx = (int)((tmp - sprite) / tmp * ONE_SIZE) / 2 * ONE_SIZE + (int)(d * ONE_SIZE);
		if (((int*)data->collet->addr)[kx] != 0)
			my_mlx_pixel_put(data, l, H_PANEL / 2 - sprite, ((int*)data->collet->addr)[kx]);
		sprite--;
	}
}

void	ft_walls_paint(t_data *data, int i)
{
	double	wall;
	double	tmp;
	int		kx, ky;
	double	dx, dy;

	wall = (1 / sqrt(powf(data->player->ray_x - data->player->pos_x, 2) + powf(data->player->ray_y - data->player->pos_y, 2)))  * 200;
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
			my_mlx_pixel_put(data, i, H_PANEL / 2 - wall,  0);

		// printf("%d ", (int)(data->window->addr + ((int)( H_PANEL / 2 - wall) * data->window->line_length +
		// (i - 8) * (data->window->bits_per_pixel / 8))));
		}
		else
		if (dy > 0.98)
			my_mlx_pixel_put(data, i, H_PANEL / 2 - wall, ((int*)data->north->addr)[kx]);
		else if (dx > 0.98)
		// // if (dx > 0.95 && (int)(data->player->look + PI) % (int)(2*PI) < PI )
			my_mlx_pixel_put(data, i, H_PANEL / 2 - wall, ((int*)data->south->addr)[ky]);
		else if (dy < 0.02)
		// if ( (int)(data->player->look + PI/2) % (int)(2*PI) > PI)
			my_mlx_pixel_put(data, i, H_PANEL / 2 - wall, ((int*)data->west->addr)[kx]);
		else if (dx < 0.02)
			my_mlx_pixel_put(data, i, H_PANEL / 2 - wall, ((int*)data->east->addr)[ky]);
		wall--;
	}

}

void	ft_cast_rays(t_data *data, int color, char str)
{
	// ft_import_imgxpm(data, data->north->image glb->texturs[0], glb->map.north_texture, &img);
	(void)color;
	double d;
	int i;

	i = 0;
	double l;
	l = 0;
	d = data->player->look - (double)(PI / 2);

	if (d < 0)
		d = d + 2 * PI;

// printf("\n\n ugol = %f\n\n", d);

	float	start = (d  - UGOL * 2 / 3) ;// - [половина угла обзора]; // начало веера лучей
	float	end = d + UGOL / 2;//ray.dir + [половина угла обзора]; // край веера лучей
	// int l = 0;
	
	while (start <= end)
	{
		data->player->ray_x  = data->player->pos_x; // каждый раз возвращаемся в точку начала
		data->player->ray_y = data->player->pos_y;
		
		double sprite;
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
		while (data->map->coord[(int)(data->player->ray_y)][(int)(data->player->ray_x)] != '1' )
		{
			if (str == 'L'&& data->map->coord[(int)(data->player->ray_y)][(int)(data->player->ray_x)] == 'L')
			{
				if (start > (d  - UGOL / 2) )
	{
					ft_sprite(data, &l, i);
					break;
	}
	else
	{
			sprite = (1 / sqrt(powf(data->player->ray_x - data->player->pos_x, 2) + powf(data->player->ray_y - data->player->pos_y, 2)))  * 200;
			l += 1/ (sprite * 4);
		break;
	}
					// l = 0;
				// str = 'a';
				// }
			// 	data->player->ray_x += cos(start)  ;
			// data->player->ray_y += sin(start)  ;
				// data->player->ray_x += 1;
				// data->player->ray_y += 1;
				// i += 1;
			}
			// l = 0;
			data->player->ray_x += cos(start)  / ONE_SIZE;
			data->player->ray_y += sin(start)  / ONE_SIZE;
			// my_mlx_pixel_put(data, data->player->ray_x * ONE_SIZE, data->player->ray_y * ONE_SIZE, color);
		}
	if (start > (d  - UGOL / 2) )
	{
/* здесь нужна функция вертикального кастинга*/
		if (str == '1')
			ft_walls_paint(data, i);
		i++;
	}
		start += UGOL / (W_PANEL);//[угол обзора] / [количество лучей];
		// i -=k;
		// end += (UGOL / (W_PANEL)) * k;
	}
}

void	ft_draw_(t_data *data, double x, double y, int color)
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

void	ft_draw_player(t_data *data, int color)
{
	
			my_mlx_pixel_put(data, (int)(data->player->pos_x  * ONE_SIZE), (int)(data->player->pos_y * ONE_SIZE), color);

		ft_cast_rays(data, color, '1');
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

int	mouse_move(int keycode, t_data *data)
{
	static int mouse_x = W_PANEL / 2;
	static int mouse_y = H_PANEL / 2;
	int x;
	int y;

	x = 0;
	y = 0;
	mlx_mouse_hide(data->window->mlx_ptr, data->window->win_ptr);
	mlx_mouse_get_pos(data->window->mlx_ptr, data->window->win_ptr, &x, &y);
	data->player->look += (double)(PI / 2) / (W_PANEL / 2) * (mouse_x - x);
	ft_paint(data);
	mlx_mouse_move(data->window->mlx_ptr, data->window->win_ptr, mouse_x, mouse_y);
	return(keycode);
}






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
		// "img/barrnel.xpm"

		// data->loot = mlx_xpm_file_to_image(vars->mlx, CHAMOMILE,
		// 	&vars->img_width, &vars->img_height);
		
	// data->loot->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
	// 	data->loot->loc, &data->loot->size_x, &data->loot->size_y);
	// data->loot->addr = mlx_get_data_addr(data->loot->image,
	// 	&data->loot->bitpp, &data->loot->line, &data->loot->endian);
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

		data->collet = ft_init_image(data->collet);
		printf("loc = %s", data->east->loc);
		if (!data->collet)
			exit(6);
		data->collet->image = mlx_xpm_file_to_image(data->window->mlx_ptr,
			"img/barrel.xpm", &data->collet->size_x, &data->collet->size_y);

		data->collet->addr = mlx_get_data_addr(data->collet->image,
			&data->collet->bitpp, &data->collet->line, &data->collet->endian);
	}






// void	process_input(t_all *all)
// {
// 	mlx_hook(all->mlx.window, 2, 1L << 0, key_press, all);
// 	mlx_hook(all->mlx.window, 3, 1L << 1, key_release, all);
// 	mlx_hook(all->mlx.window, 9, 1L << 21, refresh, all);
// 	mlx_hook(all->mlx.window, 17, 1L << 17, destroy_window, all);
// }
