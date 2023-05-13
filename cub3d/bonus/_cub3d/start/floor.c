/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:06:43 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 13:02:18 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_f(t_prog *prog, t_floor *f, int d)
{
	f->y = f->m_p - 1;
	while (++f->y < HEIGHT)
	{
		f->dist = (HEIGHT * 0.5) / (f->y - f->m_p);
		f->floor_x = prog->player.x + f->dist * f->dir_x;
		f->floor_y = prog->player.y + f->dist * f->dir_y;
		f->step_x = f->dist * (2 * prog->player.plane_x) / WIDTH;
		f->step_y = f->dist * (2 * prog->player.plane_y) / WIDTH;
		f->x = -1;
		while (++f->x < WIDTH)
		{
			f->tx = (int)(f->tex->width * (f->floor_x
						- (int)f->floor_x)) & (f->tex->width -1);
			f->ty = (int)(f->tex->height * (f->floor_y
						- (int)f->floor_y)) & (f->tex->height -1);
			f->color = get_tex_color(f->tex, f->tx, f->ty);
			f->color = (f->color >> 1) & 8355711;
			if (d)
				ft_put_pixel(f->x, HEIGHT - f->y, f->color);
			else
				ft_put_pixel(f->x, f->y, f->color);
			f->floor_x += f->step_x;
			f->floor_y += f->step_y;
		}
	}
}

void	draw_floor(t_prog *prog)
{
	t_floor	f;

	f.dir_x = (prog->player.dir_x - prog->player.plane_x);
	f.dir_y = (prog->player.dir_y - prog->player.plane_y);
	f.tex = prog->texs[prog->floor[0]];
	f.m_p = prog->m_y;
	draw_f(prog, &f, 1);
	f.tex = prog->texs[prog->floor[1]];
	f.m_p = HEIGHT - prog->m_y;
	draw_f(prog, &f, 0);
}
