/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:45:05 by esylva            #+#    #+#             */
/*   Updated: 2022/03/19 19:08:14 by esylva           ###   ########.fr       */
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
			ret = ft_cube(argv[i], data);
printf("CUB3D!!!\n ret = %d\n", ret);
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
int i;
	fd = ft_name_check(carta);
	if (!fd)
		return (ARGUMENT_OPEN_ERROR);
	data = ft_data_init(data);
	if (!data)
		return (INIT_ERROR);
	if (ft_parce_data(data, fd))
		ft_exit (MAP_ERROR);
printf("%s\n", data->north->loc);
printf("%s\n", data->east->loc);
printf("%s\n", data->south->loc);
printf("%s\n", data->west->loc);
printf("%d\n", data->cloud->trgb);
printf("%d\n", data->ground->trgb);
i = -1;
while (data->map->coords[++i])
printf("0%s0\n", data->map->coords[i]);

	// ft_make_coords(data);
	// ft_make_map(data, fd);
	// ft_check_lines(data);
	// ft_win_init(data);
	// ft_free_all(data);
	close (fd);
	return (0);
}

// void	ft_free_all(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < map->height)
// 	{
// 		if (map->coords[i])
// 		{
// 			free(map->coords[i]);
// 			map->coords[i] = NULL;
// 		}
// 		i++;
// 	}
// 	if (map->coords)
// 	{
// 		free(map->coords);
// 		map->coords = NULL;
// 	}
// 	if (map)
// 	{
// 		free(map);
// 		map = NULL;
// 	}
// }

int	ft_exit(int keycode)
{

printf("CUB3D!!!\n keycode = %d\n", keycode);
	exit (keycode);
}
