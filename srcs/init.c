/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:45:19 by esylva            #+#    #+#             */
/*   Updated: 2021/10/26 23:45:23 by esylva           ###   ########.fr       */
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
