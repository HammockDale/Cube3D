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

	point = ft_strrchr(carta, '.');
	if (!point || ft_strcmp(point, ".cub"))
	{
		printf("%s\n", strerror(EINVAL));
		exit(EINVAL);
	}
  	fd = open(carta, O_RDONLY);
	error = errno;
	if (fd == -1)
	{
		printf("%s\n", strerror(error));
		exit(error);
	}
	return (fd);
}