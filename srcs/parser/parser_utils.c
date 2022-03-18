/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:49:56 by  esylva           #+#    #+#             */
/*   Updated: 2022/03/18 19:46:07 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_separate_textures(char *str, t_data *data)
{
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] && (str[i] == 'N' && (str[i + 1] == 'O')))
		flag = ft_save_texture(&str[i + 2], data->north);
	else if (str[i] && (str[i] == 'S' && (str[i + 1] == 'O')))
		flag = ft_save_texture(&str[i + 2], data->south);
	else if (str[i] && (str[i] == 'W' && (str[i + 1] == 'E')))
		flag = ft_save_texture(&str[i + 2], data->west);
	else if (str[i] && (str[i] == 'E' && (str[i + 1] == 'A')))
		flag = ft_save_texture(&str[i + 2], data->east);
	else if (str[i] && (str[i] == 'C' && (str[i + 1] == ' ')))
		flag = ft_save_texture_c(&str[i + 2], data->cloud, data);
	else if (str[i] && (str[i] == 'F' && (str[i + 1] == ' ')))
		flag = ft_save_texture_c(&str[i + 2], data->ground, data);
	if (flag)
		return(0);
	return (1); //при успехе
}

int	ft_save_texture(char *str, t_image *wall)
{
	char *tmp;
	int	fd;

	tmp = ft_strtrim(str, "\t\v\n\f\r ");
	wall = ft_init_image(wall);
	if (!wall)
		return (MAP_ERROR);
	fd = open(tmp, O_RDONLY);
	if (fd != -1)
	{
		if (read(fd, 0, 0) != -1)
		{
			close(fd);
			wall->loc = tmp;
			return (0);
		}
		close(fd);
	}
	free(wall);
	wall = NULL;
	return (MAP_ERROR);
}

int	ft_save_texture_c(char *str, t_image *wall, t_data *data)
{
	if (data->bonus)
	{
		if(ft_save_texture(str, wall))
			return(MAP_ERROR);
	}
	else
	{
		wall = ft_init_image(wall);
		if (!wall)
			return (MAP_ERROR);
		wall->trgb = 0;
		if (ft_parsing_trgb(str, &wall->trgb))
		{
			free(wall);
			wall = NULL;
			return(MAP_ERROR);
		}
	}
	return (0);
}

int	ft_parsing_trgb(char *str, int *trgb)
{
	int	n;
	int	i;

	i = 0;
	while (*str)
	{
		n = 0;
		str += ft_numspases(str);
		while (ft_isdigit(*str))
		{
			n = n * 10 + *str - '0';
			str++;
		}
		if (n > 255)
			return(MAP_ERROR);
		else
			*trgb = (*trgb << 8) + n;
		str += ft_numspases(str);
		if (i++ < 3 && *str == ',')
			str++;
		else if (*str)
			return(MAP_ERROR);
	}
	return (0);
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
