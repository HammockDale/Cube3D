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
