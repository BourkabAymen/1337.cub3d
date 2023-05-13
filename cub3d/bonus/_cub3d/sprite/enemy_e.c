/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:56:56 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 15:13:53 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_info(t_prog *p, t_sprite *s)
{
	double	x;
	double	y;
	double	u;

	x = (s->x - p->player.x);
	y = (s->y - p->player.y);
	u = sqrt(x * x + y * y);
	x /= u;
	y /= u;
	s->e->dir_x = -1.0 * x;
	s->e->dir_y = -1.0 * y;
	s->dist = u;
	s->vx = 0;
	s->vy = 0;
}

static void	set_state_tex(t_prog *p, t_sprite *s)
{
	if (s->state == DIE)
		s->tex = p->static_tex.enemy_1[11];
	else if (s->state == DIEING)
	{
		s->tex = p->static_tex.enemy_1[(s->e->f % 80) / 20 + 8];
		if (s->e->f == 79)
			s->is_die = 1;
	}
	else if (s->state == WALKING)
	{
		s->tex = p->static_tex.enemy_1[(s->e->f % 30) / 10 + 1];
		s->vx = s->e->dir_x * 0.07;
		s->vy = s->e->dir_y * 0.07;
		sprite_move(s, p->player.map);
	}
	else if (s->state == ATTACKING)
	{
		s->tex = p->static_tex.enemy_1[(s->e->f % 68) / 17 + 4];
		if (s->e->f % 68 == 67)
			add_bullet(create_bullet(p, s->x, s->y, 2),
				s->e->dir_x, s->e->dir_y);
	}
	else
		s->tex = p->static_tex.enemy_1[0];
}

void	enemy_e(t_prog *p, t_sprite *s)
{
	int	new_state;

	set_info(p, s);
	if (s->is_die)
		new_state = DIE;
	else if (s->health < 0)
		new_state = DIEING;
	else if (s->dist > 12.0)
		new_state = STANDING;
	else if (s->dist > 6 && (s->state != ATTACKING || s->dist > 10))
		new_state = WALKING;
	else
		new_state = ATTACKING;
	if (s->state == new_state)
		s->e->f++;
	else
	{
		s->state = new_state;
		s->e->f = 0;
	}
	set_state_tex(p, s);
}
