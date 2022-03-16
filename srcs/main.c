/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:45:05 by esylva            #+#    #+#             */
/*   Updated: 2021/10/26 23:45:11 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	int		i;
	int		ret;
	t_data	*data;

	data = NULL;
	if (argc == 1)
	{
		printf("%s\n",
			"Please, use cub3D with arguments 'map' in format *.cub");
		return(1);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			ret = ft_cube(argv[i], data)
			if(ret)
				return (ret);
			i++;
		}
	}
	return(0);
}

int	ft_cube(char *carta, t_data *data)
{
	int	fd;

	fd = ft_name_check(carta);
	if (!fd)
		return (1);
	data = ft_map_init(data);
	if (!data)
		return (2);
	if (!ft_parce_map(data, fd))
		return (3);
	ft_make_coords(data);
	ft_make_map(data, fd);
	ft_check_lines(data);
	ft_win_init(data);
	ft_free_all(data);
	return (0);
}

void	ft_free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->coords[i])
		{
			free(map->coords[i]);
			map->coords[i] = NULL;
		}
		i++;
	}
	if (map->coords)
	{
		free(map->coords);
		map->coords = NULL;
	}
	if (map)
	{
		free(map);
		map = NULL;
	}
}

int	ft_exit(int keycode)
{
	(void)keycode;
	printf("Exit");
	exit (0);
}
