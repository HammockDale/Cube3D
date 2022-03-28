/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:53:53 by esylva            #+#    #+#             */
/*   Updated: 2022/03/28 09:39:17 by esylva           ###   ########.fr       */
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