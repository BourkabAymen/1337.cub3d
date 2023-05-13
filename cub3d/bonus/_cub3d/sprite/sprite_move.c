/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:56:13 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/01 13:56:33 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_move(t_sprite *s, char **map)
{
	double	next_x;
	double	next_y;

	next_x = s->x + s->vx;
	next_y = s->y + s->vy;
	if (map[(int)(s->y)][(int)(next_x)] != '1')
		s->x += s->vx;
	else if (s->k == 'b')
		s->state = 0;
	if (map[(int)(next_y)][(int)(s->x)] != '1')
		s->y += s->vy;
	else
		s->state = 0;
}
