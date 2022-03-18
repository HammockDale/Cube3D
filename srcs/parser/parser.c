/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:39:52 by esylva            #+#    #+#             */
/*   Updated: 2022/03/16 20:39:52 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_list	*ft_lstnew_m(char *content)
{
	t_list	*aa;

	aa = (t_list *)malloc(sizeof (*aa));
	if (!aa)
		return (NULL);
	aa->content = ft_strdup(content);
	aa->next = NULL;
	return (aa);
}

int	ft_parce_data(t_data *data, int fd)
{
	char	*line;
	int		not_the_end;
	t_list	*cub;

	line = NULL;
	cub = NULL;
	not_the_end = 1;
	while (not_the_end > 0)
	{
		not_the_end = get_next_line(fd, &line);
		new = ft_lstnew_m(line);
		ft_lstadd_back(&cub, new);
		free(line);
		line = NULL;
	}
	not_the_end = ft_config(&cub, data)
	ft_lstclear(&cub, free());
	if (not_the_end)
		return (MAP_ERROR);
	return (0);
}

int	ft_config(t_list **cub, t_data *data)
{
	t_list	tmp;
	int		i;

	i = 0;
	tmp = *cub;
	while (tmp)
	{
		i += (ft_separate_textures(tmp->content; data)) //  ищем данные в строках
		if (i == 6) // если все данные
			if (ft_tind_map_begin(tmp->content)) // иначе ищем начало карты
				break; // при успехе выходим из цикла или переходим к следующей строке
		tmp = tmp->next;
	}
	if (i != 6 || ft_parse_map(tmp, data)) // требуется фикс для учета обработки ошибки предыдущего этапа
		return (MAP_ERROR);
	return(0);
}








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
