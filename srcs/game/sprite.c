/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esylva <esylva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:27:33 by esylva            #+#    #+#             */
/*   Updated: 2022/05/15 17:34:04 by esylva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "cub.h"

void ft_sprite_init(t_data *data)
{
	int i;
	char *s;

	s = NULL;
	i = 0;
	while (i < NUMBER_OF_IMAGES)
	{
		s = ft_itoa(i);
		data->loot->sprites[i]->loc = ft_strjoin("img/cola/cola_", s);
		free(s);
		s = NULL;
		i++;
	}
}
