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
	t_map	*map;

	map = NULL;
	if (argc == 1)
	{
		printf("%s\n",
			"Please, use cub3D with arguments 'map' in format *.cub");
		exit(1);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			ft_so_long(argv[i], map);
			i++;
		}
	}
}

void	ft_so_long(char *carta, t_map *map)
{
	int		fd;

	ft_name_check(carta);
	fd = ft_check_file(carta);
	map = ft_map_init(map);
	ft_parce_map(map, fd);
	ft_make_coords(map);
	ft_make_map(map, fd);
	ft_check_lines(map);
	ft_win_init(map);
	ft_free_all(map);
}

void	ft_free_all(t_map *map)
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
