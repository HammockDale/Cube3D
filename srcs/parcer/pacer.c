/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pacer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:45:49 by esylva            #+#    #+#             */
/*   Updated: 2021/10/26 23:45:53 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_make_coords(t_map *map)
{
	int		error;
	int		y;

	map->coords = (int **)malloc(sizeof(int *) * map->height);
	error = errno;
	if (!map->coords)
	{
		printf("%s\n", strerror(error));
		exit(error);
	}
	y = 0;
	while (y < map->height)
	{
		map->coords[y] = (int *)malloc(sizeof(int) * map->weight);
		if (!map->coords[y])
		{
			printf("%s\n", strerror(error));
			exit(error);
		}
		y++;
	}
}

void	ft_make_map(t_map *map, int fd)
{	
	char	*line;
	int		x;
	int		y;

	line = NULL;
	y = 0;
	while (y < map->height)
	{
		get_next_line(fd, &line);
		x = ft_strlen(line) - 1;
		while (--x >= 0)
		{
			map->coords[y][x] = line[x];
		}
		y++;
		free(line);
	}
	close (fd);
}

void	ft_check_lines(t_map *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->weight)
		{
			ft_check_sym(x, y, map);
			x++;
		}
		y++;
	}
	ft_check_player_position(map);
}

void	ft_check_sym(int x, int y, t_map *map)
{
	if (y == 0 || y == map->height - 1 || x == 0 || x == map->weight - 1)
	{
		if (map->coords[y][x] != (int) '1')
		{
			printf("Map error: walls are not around the field\n");
			exit (22);
		}
	}	
	else if (map->coords[y][x] == (int) 'C')
		map->loot++;
	else if (map->coords[y][x] == (int) 'E')
		map->exit++;
	else if (map->coords[y][x] == (int) 'P')
		map->player++;
	else if (map->coords[y][x] == (int) '0' || map->coords[y][x] == (int) '1')
		return ;
	else
	{
		printf("Map error: wrong symbol\n");
		exit (22);
	}
}

void	ft_check_player_position(t_map *map)
{
	if (map->player != 1)
	{
		printf("Map error: have to be one player position\n");
		exit (22);
	}
	if (!map->exit)
	{
		printf("Map error: no exit\n");
		exit (22);
	}
	if (!map->loot)
	{
		printf("Map error: no loot\n");
		exit (22);
	}
}
