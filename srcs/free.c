/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:13:14 by esylva            #+#    #+#             */
/*   Updated: 2022/03/25 15:32:35 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_window	*ft_free_window(t_window *window)
{
	free(window);
	return (NULL);
}

t_map	*ft_free_map(t_map *map)
{
	free(map);
	return (NULL);
}

t_player	*ft_free_player(t_player *player)
{
	free(player);
	return (NULL);
}

t_image	*ft_free_image(t_image *image)
{
	free(image);
	return (NULL);
}

t_sprite	*ft_free_sprite(t_sprite *sprite)
{
	free(sprite);
	return (NULL);
}