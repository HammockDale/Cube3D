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





t_map	*ft_map_init(t_map *map)
{
	int	error;

	map = (t_map *)malloc(sizeof(t_map));
	error = errno;
	if (!map)
	{
		printf("%s\n", strerror(error));
		exit(error);
	}
	map->weight = 0;
	map->height = 0;
	map->loot = 0;
	map->exit = 0;
	map->player = 0;
	return (map);
}

void	ft_check_rect(int sh, int ne, char *line)
{
	int	len;

	len = (int)ft_strlen(line);
	if (sh && ne)
	{
		if ((sh + 1) != len)
		{
			free(line);
			printf("Map is not rectangular\n");
			exit (22);
		}
	}
}

void	ft_parce_map(t_map *map, int fd)
{
	char	*line;
	int		not_the_end;

	line = NULL;
	not_the_end = 1;
	while (not_the_end)
	{
		not_the_end = get_next_line(fd, &line);
		ft_check_rect(map->weight, not_the_end, line);
		if (not_the_end)
		{
			map->weight = ft_strlen(line) - 1;
			map->height++;
		}
		free(line);
	}
	lseek(fd, 0, SEEK_SET);
}
