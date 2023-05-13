/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:57:20 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 15:13:01 by aben-ham         ###   ########.fr       */
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

static void	rotate(double *x, double *y, double angle)
{
	double	t;

	t = *x;
	*x = *x * cos(angle) - *y * sin(angle);
	*y = t * sin(angle) + *y * cos(angle);
}

static void	m_add_bullet(t_prog *p, t_sprite *s)
{
	double	x;
	double	y;

	x = s->e->dir_x;
	y = s->e->dir_y;
	add_bullet(create_bullet(p, s->x - 0.5, s->y, 3), x, y);
	if (ft_rand() % 2)
	{
		rotate(&x, &y, 0.3);
		add_bullet(create_bullet(p, s->x, s->y, 3), x, y);
		rotate(&x, &y, 0.3 * -2);
		add_bullet(create_bullet(p, s->x + 0.5, s->y, 3), x, y);
	}
	else
	{
		add_bullet(create_bullet(p, s->x - 0.5, s->y, 3), x, y);
		add_bullet(create_bullet(p, s->x + 0.5, s->y, 3), x, y);
	}
}

static void	set_state_tex(t_prog *p, t_sprite *s)
{
	if (s->state == DIE)
		s->tex = p->static_tex.enemy_2[9];
	else if (s->state == DIEING)
	{
		s->tex = p->static_tex.enemy_2[(s->e->f % 90) / 30 + 7];
		if (s->e->f == 89)
			s->is_die = 1;
	}
	else if (s->state == WALKING)
	{
		s->tex = p->static_tex.enemy_2[(s->e->f % 30) / 10 + 1];
		s->vx = s->e->dir_x * 0.1;
		s->vy = s->e->dir_y * 0.1;
		sprite_move(s, p->player.map);
	}
	else if (s->state == ATTACKING)
	{
		s->tex = p->static_tex.enemy_2[(s->e->f % 51) / 17 + 4];
		if (s->e->f % 51 == 50)
			m_add_bullet(p, s);
	}
	else
		s->tex = p->static_tex.enemy_2[0];
}

void	enemy_m(t_prog *p, t_sprite *s)
{
	int	new_state;

	set_info(p, s);
	if (s->is_die)
		new_state = DIE;
	else if (s->health < 0)
		new_state = DIEING;
	else if (s->dist > 13.0)
		new_state = STANDING;
	else if (s->dist > 7 && (s->state != ATTACKING || s->dist > 11))
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
