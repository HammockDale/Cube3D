/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:53:53 by esylva            #+#    #+#             */
/*   Updated: 2022/03/28 15:05:52 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		ft_open_door(t_data *data)
{
	// data->map->y = (int)data->player->pos_y;
	// data->map->x = (int)data->player->pos_x;
	if (data->map->coord[data->map->y][data->map->x] == (int) 'D')
	{	
		(data->map->coord[data->map->y][data->map->x] = (int) '0');
	}
}

void	ft_change_ground(t_data *data)
{
	if (data->map->coord[data->map->y][data->map->x] == (int) 'L')
	{	
		(data->map->coord[data->map->y][data->map->x] = '0');
		data->map->loot--;
	}
	if (!data->map->loot && data->map->coord[data->map->y][data->map->x] == 'X')
	{
		printf("YOU WIN!");
		ft_exit(data, 0);
	}
}