/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:53:53 by esylva            #+#    #+#             */
/*   Updated: 2022/05/15 17:48:32 by esylva           ###   ########.fr       */
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
