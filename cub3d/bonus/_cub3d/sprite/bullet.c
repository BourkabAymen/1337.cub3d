/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:26:09 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 15:15:01 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	*create_bullet(t_prog *prog, double x, double y, int type)
{
	t_sprite	*s;

	if (prog->s_len >= prog->s_max)
		return (NULL);
	s = ft_malloc(sizeof(t_sprite));
	s->tex = prog->static_tex.bullet[type - 1];
	s->state = type;
	s->k = 'b';
	s->x = x;
	s->y = y;
	s->count = 80;
	prog->sprites[prog->s_len] = s;
	prog->sprites[prog->s_len + 1] = NULL;
	prog->s_len++;
	return (s);
}

void	add_bullet(t_sprite *s, double dir_x, double dir_y)
{
	if (!s)
		return ;
	s->x += dir_x * 0.5;
	s->y += dir_y * 0.5;
	s->vx = dir_x * 0.2;
	s->vy = dir_y * 0.2;
	if (s->state == 3)
	{
		s->vx = dir_x * 0.2;
		s->vy = dir_y * 0.2;
	}
}

void	remove_bullet(t_sprite **sprites, t_sprite *s)
{
	int	i;

	i = 0;
	while (sprites[i] != s)
		i++;
	while (sprites[i + 1])
	{
		sprites[i] = sprites[i + 1];
		i++;
	}
	sprites[i] = NULL;
	free(s);
}

static void	hit_enemy(t_sprite **sprites, int len, t_sprite *s)
{
	int	i;

	i = len - 1;
	while (--i >= 0)
	{
		if (sprites[i]->k != 'e' && sprites[i]->k != 'm')
			continue ;
		if (sprites[i]->is_die)
			continue ;
		if ((int)sprites[i]->x == (int)s->x && (int)sprites[i]->y == (int)s->y)
		{
			sprites[i]->health -= 20;
			sprites[i]->hit = 40;
			s->state = 0;
			break ;
		}
	}
}

void	bullet_sprite(t_prog *p, t_sprite *s)
{
	if (s->count < 0)
		s->state = 0;
	sprite_move(s, p->player.map);
	if ((s->state == 2 || s->state == 3) && (int)p->player.x == (int)s->x
		&& (int)p->player.y == (int)s->y)
	{
		p->player.hit = 15;
		if (s->state == 2)
			p->player.health -= E_DAM;
		else
			p->player.health -= M_DAM;
		s->state = 0;
	}
	else if (s->state == 1)
	{
		hit_enemy(p->sprites, p->s_len, s);
	}
	if (!s->state)
	{
		remove_bullet(p->sprites, s);
		p->s_len--;
	}
	s->count--;
}
