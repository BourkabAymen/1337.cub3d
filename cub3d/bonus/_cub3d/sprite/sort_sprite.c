/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:51:42 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 10:39:03 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	insertion_sort(t_sprite **sprites)
{
	int			size;
	int			step;
	t_sprite	*key;
	int			j;

	size = 0;
	while (sprites[size])
		size++;
	step = 1;
	while (step < size)
	{
		key = sprites[step];
		j = step - 1;
		while (j >= 0 && key->dist >= sprites[j]->dist)
		{
			sprites[j + 1] = sprites[j];
			j--;
		}
		sprites[j + 1] = key;
		step++;
	}
}

void	sort_sprites(t_sprite **s, t_player *p)
{
	int	i;

	i = -1;
	while (s[++i])
		s[i]->dist = ((s[i]->x - p->x) * (s[i]->x - p->x)
				+ (s[i]->y - p->y) * (s[i]->y - p->y));
	insertion_sort(s);
}
