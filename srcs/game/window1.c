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
	mlx_put_image_to_window(data->window->mlx_ptr, data->window->win_ptr,
		data->window->img, 0, 0);
}


// void	ft_draw_2D_wall(t_data *data)
// {

// }




void	ft_cast_rays(t_data *data, int color)
{
	(void)color;
	int i;
	double d;

	i = 0;
	d = data->player->look - (double)(PI / 2);

	if (d < 0)
		d = d + 2 * PI;

// printf("\n\n ugol = %f\n\n", d);

	float start = (d  - UGOL / 2) ;// - [половина угла обзора]; // начало веера лучей
	float end = d + UGOL / 2;//ray.dir + [половина угла обзора]; // край веера лучей
	double wall, a, b;
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

	double j;
		double gip;
	j = H_PANEL / 2;
	gip = 0;
		wall = 0;
		a = data->player->ray_x - data->player->pos_x;
		b = data->player->ray_y - data->player->pos_y;
		gip = sqrt((a*a) + (b*b));
	
		if (gip > 0)
			wall =  H_PANEL / 2 + (1 / gip)  * 300;
		// if ((int)(tan(start)*1000) && (fabs)(tan(start)) < 0.99)
		{
			
				// wall = (double)(((sqrt(a*a + b*b) * ONE_SIZE )* (fabs)(tan(start))));//   * ONE_SIZE * ONE_SIZE;
		// printf("gip = %f wall = %f gip = %f statrt = %f tan = %f\n", gip, wall, sqrt(a*a + b*b), start, tan( start));
		}
		while (j < wall && j < 1000)
		{
			my_mlx_pixel_put(data, i, j, 0x0FF00FF);
			j += 1;
		}

		wall -= H_PANEL / 2;
		while (wall  > 0)
		{
			if (wall >= H_PANEL / 2)
			wall = H_PANEL / 2;
			my_mlx_pixel_put(data, i, H_PANEL / 2 - wall, 0x0FF00FF);
			wall--;
		}
		i++;
		j = H_PANEL / 2;
		start += UGOL / (W_PANEL);//[угол обзора] / [количество лучей];
	}
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
