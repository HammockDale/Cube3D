/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:40:15 by esylva            #+#    #+#             */
/*   Updated: 2022/03/19 18:36:45 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_empty_line(char *str)
{
	if (!str)
		return (0);
	str+=ft_numspases(str);
	if (*str)
		return (1);
	return (0);
}

void	ft_copy_str(char *dest, char *src, int lim)
{
	int	i;
	int len;

	len = ft_strlen(src);
	i = 0;
	while (i < len)
	{		
		*(dest + i) = *(src + i);
			i++;
	}
	while (i < lim)
	{
		*(dest + i) = ' ';
		i++;
	}
	*(dest + i) = 0;
}

int	ft_tind_map_begin(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == ' ' || str[i] == '1')
			i++;
		else
			return (0);
	}
	return (i);
}
