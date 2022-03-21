/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  esylva < esylva@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:42:12 by  esylva           #+#    #+#             */
/*   Updated: 2022/03/14 14:42:12 by  esylva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_name_check(char *carta)
{
	char	*point;
	int	fd;
	int	error;

	error = 0;
	point = ft_strrchr(carta, '.');
	fd = open(carta, O_RDONLY);
	if (fd == -1)
		error = errno;
	else if (!point || ft_strcmp(point, ".cub"))
		error = EINVAL;
	else if(read(fd, NULL, 0) == -1)
		error = errno;
	if (error)
	{
		printf("%s\n", strerror(error));
		fd = 0;
	}
	return (fd);
}

int		ft_check_map(t_data *data, t_list *map, int weght, int hight)
{

	if (ft_init_map(data, hight))
		return(MAP_ERROR);
	if (ft_init_coords(data, map, weght, hight))
		return(MAP_ERROR);

	return (0);
}