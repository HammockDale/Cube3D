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

void	ft_open_door(t_data *data)
{
	if (data->map->coord[(int)data->player->pos_y + 1][(int)
		data->player->pos_x] == 'D')
		data->map->coord[(int)data->player->pos_y + 1][(int)
			data->player->pos_x] = '0';
	if (data->map->coord[(int)
			data->player->pos_y - 1][(int)data->player->pos_x] == 'D')
		data->map->coord[(int)
			data->player->pos_y - 1][(int)data->player->pos_x] = '0';
	if (data->map->coord[(int)data->player->pos_y][(int)
		data->player->pos_x - 1] == 'D')
		data->map->coord[(int)data->player->pos_y][(int)
			data->player->pos_x - 1] = '0';
	if (data->map->coord[(int)
			data->player->pos_y][(int)data->player->pos_x + 1] == 'D')
		data->map->coord[(int)
			data->player->pos_y][(int)data->player->pos_x + 1] = '0';
	ft_open_door2(data);
	ft_paint(data);
}

void	ft_open_door2(t_data *data)
{
	if (data->map->coord[(int)data->player->pos_y + 1][(int)
		data->player->pos_x + 1] == 'D')
		data->map->coord[(int)data->player->pos_y + 1][(int)
			data->player->pos_x + 1] = '0';
	if (data->map->coord[(int)
			data->player->pos_y - 1][(int)data->player->pos_x + 1] == 'D')
		data->map->coord[(int)
			data->player->pos_y - 1][(int)data->player->pos_x + 1] = '0';
	if (data->map->coord[(int)data->player->pos_y - 1][(int)
		data->player->pos_x - 1] == 'D')
		data->map->coord[(int)data->player->pos_y - 1][(int)
			data->player->pos_x - 1] = '0';
	if (data->map->coord[(int)
			data->player->pos_y + 1][(int)data->player->pos_x - 1] == 'D')
		data->map->coord[(int)
			data->player->pos_y + 1][(int)data->player->pos_x - 1] = '0';
}


void	ft_setloot(t_data *data);
