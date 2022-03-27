/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:46:37 by esylva            #+#    #+#             */
/*   Updated: 2022/03/27 18:49:32 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->window->addr + (int)(y * data->window->line_length + x * (data->window->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	ft_cast_rays(t_data *data, int color)
{
	(void)color;
	int i;
	double d;

	i = 0;
	d = data->player->cameraX - (double)(PI / 2);
	// printf ("a = %f\n", data->player->cameraX);
	// 	printf ("a = %f\n", a);
	// if (d > 2 * PI)
	// 	d = d - 2 * PI;
	if (d < 0)
		d = d + 2 * PI;

printf("\n\n ugol = %f\n\n", d);

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
			my_mlx_pixel_put(data, data->player->ray_x * ONE_SIZE, data->player->ray_y * ONE_SIZE, color);
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

void	ft_back(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	// data->window->addr = mlx_get_data_addr(data->window->img, &data->window->bits_per_pixel, &data->window->line_length, &data->window->endian);
	while (i < W_PANEL)
	{
		while (j < H_PANEL / 2)
		{
			my_mlx_pixel_put(data, i, j, data->cloud->trgb);
			j++;
		}
		while (j < H_PANEL)
		{
			my_mlx_pixel_put(data, i, j, data->ground->trgb);
			j++;
		}
		j = 0;
		i++;
	}
	// mlx_put_image_to_window(data->window->mlx_ptr, data->window->win_ptr, data->window->img, 0, 0);
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

void	ft_paint(t_data *data)
{
	mlx_clear_window(data->window->mlx_ptr, data->window->win_ptr);
	
	data->window->addr = mlx_get_data_addr(data->window->img, &data->window->bits_per_pixel, &data->window->line_length, &data->window->endian);

	ft_back(data);
	// ft_draw_2D_woll(data);
	
	// ft_draw_(data, data->player->pos_x, data->player->pos_y, 0x0F0FFFF);
	ft_draw_player(data, 0x0F0FFFF);
	mlx_put_image_to_window(data->window->mlx_ptr, data->window->win_ptr, data->window->img, 0, 0);

	// ft_background(var);
	// ft_beahive(var);
	// ft_woll(var);
	// ft_chamomile(var, 0, 0);
	// if (var->max_score == 0)
	// 	ft_close();
	// ft_bee_l1(var);
	// ft_hornet_L(var, 0, 0);
	// ft_paint_text(var);
}

int	key_kb_hook(int keycode, t_data *data)
{
	if (keycode == GO_FORWARD)
		ft_Pup(data);
	else if (keycode == STR_LEFT)
		ft_Pleft(data);
	else if (keycode == GO_BACKWARD)
		ft_Pdown(data);
	else if (keycode == STR_RIGHT)
		ft_Pright(data);
	else if (keycode == TURN_RIGHT)
		ft_Pclock(data);
	else if (keycode == TURN_LEFT)
		ft_Pconterclock(data);
	printf("keycode = %d\n", keycode);
	if (keycode == EXIT)
	{
		mlx_destroy_window(data->window->mlx_ptr, data->window->win_ptr);
		ft_exit(data, 0);
	}
	return (keycode);
}

// int	ft_win_d3_init(t_data *data)
// {
// 	// ft_coords(data);
	
// 	data->d3->mlx_ptr = mlx_init();
// 	data->d3->win_ptr = mlx_new_window(data->d3->mlx_ptr,  1920, 1080, "cub3D");
// 	// mlx_key_hook(data->window->win_ptr, key_kb_hook, data);
// 	// mlx_hook(data->window->win_ptr, 2, 0, key_kb_hook, data);
// 	// mlx_hook(data->window->win_ptr, 3, 0, key_kb_hook, data);		// проверить
// 	data->d3->img = mlx_new_image(data->d3->mlx_ptr, 1920, 1080);
// 	// ft_paint(data);
// 	// mlx_clear_window(data->d3->mlx_ptr, data->d3->win_ptr);
	
// 	// mlx_put_image_to_window(data->d3->mlx_ptr, data->d3->win_ptr, data->window->img, 0, 0);

// 	// ft_button(data);

// 	// ft_img_init(map);
// 	// ft_put_img_to_win(data);
// 	// mlx_loop_hook(data->window->mlx_ptr, render_next_frame, data->window);
// 	// mlx_hook(data->window->win_ptr, 2, 0, key_hook, data->window);
// 	mlx_hook(data->d3->win_ptr, 17, 0L, ft_exit, data);
// 	mlx_loop(data->d3->mlx_ptr);
// 	return (0);
// }


int	ft_win_init(t_data *data)
{
	// ft_coords(data);
	data->window->mlx_ptr = mlx_init();
	data->window->win_ptr = mlx_new_window(data->window->mlx_ptr, W_PANEL, H_PANEL, "cub2D");
	// mlx_key_hook(data->window->win_ptr, key_kb_hook, data);
	mlx_hook(data->window->win_ptr, 2, 0, key_kb_hook, data);
	mlx_hook(data->window->win_ptr, 3, 0, key_kb_hook, data);		// проверить
	data->window->img = mlx_new_image(data->window->mlx_ptr, W_PANEL, H_PANEL);
	ft_paint(data);
	// ft_button(data);

	// ft_img_init(map);
	// ft_put_img_to_win(data);
	// mlx_loop_hook(data->window->mlx_ptr, render_next_frame, data->window);
	// mlx_hook(data->window->win_ptr, 2, 0, key_hook, data->window);
	mlx_hook(data->window->win_ptr, 17, 0L, ft_exit, data);
	mlx_loop(data->window->mlx_ptr);
	return (0);
}

// void	ft_img_init(t_map *map)
// {
// 	map->ground.loc = "./img/ground.xpm";
// 	map->ground.image = mlx_xpm_file_to_image(map->mlx_ptr, map->ground.loc,
// 			&map->size_x, &map->size_y);
// 	map->ground.addr = mlx_get_data_addr(map->ground.image, &map->ground.bitpp,
// 			&map->ground.line, &map->ground.endian);
// 	map->wall.loc = "./img/wall.xpm";
// 	map->wall.image = mlx_xpm_file_to_image(map->mlx_ptr, map->wall.loc,
// 			&map->size_x, &map->size_y);
// 	map->wall.addr = mlx_get_data_addr(map->wall.image, &map->wall.bitpp,
// 			&map->wall.line, &map->wall.endian);
// 	map->fish.loc = "./img/fish.xpm";
// 	map->fish.image = mlx_xpm_file_to_image(map->mlx_ptr, map->fish.loc,
// 			&map->size_x, &map->size_y);
// 	map->fish.addr = mlx_get_data_addr(map->fish.image, &map->fish.bitpp,
// 			&map->fish.line, &map->fish.endian);
// 	map->cat.loc = "./img/smallcat.xpm";
// 	map->cat.image = mlx_xpm_file_to_image(map->mlx_ptr, map->cat.loc,
// 			&map->size_x, &map->size_y);
// 	map->cat.addr = mlx_get_data_addr(map->cat.image, &map->cat.bitpp,
// 			&map->cat.line, &map->cat.endian);
// 	map->gate.loc = "./img/gate.xpm";
// 	map->gate.image = mlx_xpm_file_to_image(map->mlx_ptr, map->gate.loc,
// 			&map->size_x, &map->size_y);
// 	map->gate.addr = mlx_get_data_addr(map->gate.image, &map->gate.bitpp,
// 			&map->gate.line, &map->gate.endian);
// }


// void	ft_put_img_to_win(t_map *map)
// {
// 	map->y = 0;
// 	while (map->y < map->height)
// 	{
// 		map->x = 0;
// 		while (map->x < map->weight)
// 		{
// 			ft_put_by_sym(map);
// 			map->x++;
// 		}
// 		map->y++;
// 	}
// }

// void	ft_put_by_sym(t_map *map)
// {
// 	if (map->coords[map->y][map->x] == (int) '1')
// 		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->wall.image,
// 			map->x * map->size_x, map->y * map->size_y);
// 	else if (map->coords[map->y][map->x] == (int) '0')
// 		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->ground.image,
// 			map->x * map->size_x, map->y * map->size_y);
// 	else if (map->coords[map->y][map->x] == (int) 'C')
// 		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->fish.image,
// 			map->x * map->size_x, map->y * map->size_y);
// 	else if (map->coords[map->y][map->x] == (int) 'E')
// 		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->gate.image,
// 			map->x * map->size_x, map->y * map->size_y);
// 	else if (map->coords[map->y][map->x] == (int) 'P')
// 	{
// 		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->cat.image,
// 			map->x * map->size_x, map->y * map->size_y);
// 		map->p_x = map->x;
// 		map->p_y = map->y;
// 	}
// }

// void ft_coords(t_data *data)
// {
// 	int i;

// 	i = 0;
// 	data->window->coords = calloc(sizeof(int*) , 8);
// 	while (i < 8)
// 	{
// 		data->window->coords[i] = (int *)calloc(sizeof(int), 10);
// 	}
// 	data->window->coords[0] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};   
// 	data->window->coords[1] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 1};
// 	data->window->coords[2] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 1};   
// 	data->window->coords[3] = {1, 0, 1, 0, 0, 0, 1, 0, 0, 1};   
// 	data->window->coords[4] = {1, 0, 1, 0, 0, 0, 0, 0, 0, 1};   
// 	data->window->coords[5] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 1};  
// 	data->window->coords[6] = {1, 0, 1, 0, 0, 0, 0, N, 0, 1};   
// 	data->window->coords[7] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};   

// }
