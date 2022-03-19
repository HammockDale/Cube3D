/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:45:19 by esylva            #+#    #+#             */
/*   Updated: 2022/03/19 14:54:28 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_data	*ft_data_init(t_data *data)
{
	int	error;

	data = (t_data *)malloc(sizeof(t_data));
	error = errno;
	if (!data)
	{
		printf("%s\n", strerror(error));
		return(NULL);
	}
	data->window = NULL;
	data->map = NULL;
	data->player = NULL;
	data->ground = NULL;
	data->cloud = NULL;
	data->north = NULL;
	data->east = NULL;
	data->south = NULL;
	data->west = NULL;
	data->door = NULL;
	data->loot = NULL;
	data->bonus = BONUS; 
	if (ft_init_main_struct(data))
		return(NULL);
	return (data);
}

int	ft_init_main_struct(t_data *data)
// функция инициализации (и удаления при неудаче) переменных основной структуры
{
	(void)data;
	return (0);
}

t_image	*ft_init_image(t_image *wall)
{
	wall = (t_image *)malloc(sizeof(t_image));
	if (!wall)
		return (NULL);
	wall->loc = NULL;
	wall->image = NULL;
	wall->addr = NULL;
	wall->line = 0;
	wall->bitpp = 0;
	wall->endian = 0;
	wall->trgb = 0;
	return (wall);
}

int		ft_init_map(t_data *data, t_list *map, int weght, int hight)
{
	(void)data;
	(void)map;
	(void)weght;
	(void)hight;
	return (0);
}
