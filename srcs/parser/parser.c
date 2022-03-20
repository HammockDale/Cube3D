/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:39:52 by esylva            #+#    #+#             */
/*   Updated: 2022/03/19 15:17:02 by esylva           ###   ########.fr       */
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
		ft_lstadd_back(&cub, ft_lstnew_m(line));
		free(line);
		line = NULL;
	}
	not_the_end = ft_config(&cub, data);
	ft_lstclear(&cub, free);
	if (not_the_end)
		return (MAP_ERROR);
	return (0);
}

int	ft_config(t_list **cub, t_data *data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *cub;
	while (i < 6 && tmp)
	{
		i += ft_separate_textures(tmp->content, data);
		tmp = tmp->next;
	}
	if (i != 6)
		return (MAP_ERROR);	
	while (!ft_empty_line(tmp->content) && tmp)
		tmp = tmp->next;
	if (ft_parse_map(tmp, data))
		return (MAP_ERROR);
	return(0);
}

int		ft_parse_map(t_list *map, t_data *data)
{
	t_list	*tmp;
	int weght;
	int	hight;
	int a;

	hight = 0;
	weght = 0;
	tmp = map;
	while (tmp)
	{
		a = ft_strlen(tmp->content);
		if (weght < a)
			weght = a;
		hight++;
		tmp = tmp->next;
	}
	if (ft_init_map(data, map, weght, hight))
		return(MAP_ERROR);
	return (0);
}





// void	ft_make_coords(t_map *map)
// {
// 	int		error;
// 	int		y;
// 	map->coords = (int **)malloc(sizeof(int *) * map->height);
// 	error = errno;
// 	if (!map->coords)
// 	{
// 		printf("%s\n", strerror(error));
// 		exit(error);
// 	}
// 	y = 0;
// 	while (y < map->height)
// 	{
// 		map->coords[y] = (int *)malloc(sizeof(int) * map->weight);
// 		if (!map->coords[y])
// 		{
// 			printf("%s\n", strerror(error));
// 			exit(error);
// 		}
// 		y++;
// 	}
// }


// void	ft_check_lines(t_map *map)
// {
// 	int		x;
// 	int		y;
// 	x = 0;
// 	y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->weight)
// 		{
// 			ft_check_sym(x, y, map);
// 			x++;
// 		}
// 		y++;
// 	}
// 	ft_check_player_position(map);
// }

// void	ft_check_sym(int x, int y, t_map *map)
// {
// 	if (y == 0 || y == map->height - 1 || x == 0 || x == map->weight - 1)
// 	{
// 		if (map->coords[y][x] != (int) '1')
// 		{
// 			printf("Map error: walls are not around the field\n");
// 			exit (22);
// 		}
// 	}	
// 	else if (map->coords[y][x] == (int) 'C')
// 		map->loot++;
// 	else if (map->coords[y][x] == (int) 'E')
// 		map->exit++;
// 	else if (map->coords[y][x] == (int) 'P')
// 		map->player++;
// 	else if (map->coords[y][x] == (int) '0' || map->coords[y][x] == (int) '1')
// 		return ;
// 	else
// 	{
// 		printf("Map error: wrong symbol\n");
// 		exit (22);
// 	}
// }

// void	ft_check_player_position(t_map *map)
// {
// 	if (map->player != 1)
// 	{
// 		printf("Map error: have to be one player position\n");
// 		exit (22);
// 	}
// 	if (!map->exit)
// 	{
// 		printf("Map error: no exit\n");
// 		exit (22);
// 	}
// 	if (!map->loot)
// 	{
// 		printf("Map error: no loot\n");
// 		exit (22);
// 	}
// }
