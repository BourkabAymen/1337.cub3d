/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:47:33 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 10:39:50 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	normal_sprite(t_prog *p, t_sprite *s)
{
	int	i;

	i = p->map_keys[s->k - 33]->tex_index[0];
	s->tex = p->texs[i];
}

void	heal_sprite(t_prog *p, t_sprite *s)
{
	double	dist;

	dist = (p->player.x - s->x) * (p->player.x - s->x)
		+ (p->player.y - s->y) * (p->player.y - s->y);
	if (dist < 1 && s->health > 0 && p->player.health < PLAYER_HEALTH)
	{
		s->health = 0;
		p->player.health += HEAL_ADD;
		if (p->player.health > PLAYER_HEALTH)
			p->player.health = PLAYER_HEALTH;
		p->player.map[(int)s->y][(int)s->x] = '0';
	}
	s->tex = p->static_tex.heal[0];
}
