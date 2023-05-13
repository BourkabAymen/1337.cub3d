/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:35:58 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 16:04:56 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_minimap(t_prog *prog, t_mini_map *m)
{
	m->map = prog->player.map;
	m->map_width = prog->player.map_longest_len * TILE_SIZE;
	m->map_height = prog->player.map_len * TILE_SIZE;
	m->p_x = prog->player.x * TILE_SIZE;
	m->p_y = prog->player.y * TILE_SIZE;
	m->x_start = max(0, min(m->p_x - MINIMAP_W / 2, m->map_width - MINIMAP_W));
	m->x_end = min(m->map_width, m->x_start + MINIMAP_W);
	m->y_start = max(0, min(m->p_y - MINIMAP_H / 2, m->map_height - MINIMAP_H));
	m->y_end = min(m->map_height, m->y_start + MINIMAP_H);
	m->shift_x = (TILE_SIZE * 0.5) + WIDTH - m->x_end - 5;
	m->shift_y = (TILE_SIZE * 0.5) + HEIGHT - m->y_end - 5;
	m->player_map_x = prog->player.x;
	m->player_map_y = prog->player.y;
}

static void	draw_dir(float angle, float length, t_mini_map *m, float color)
{
	float	r;
	float	x;
	float	y;
	int		offset_x;
	int		offset_y;

	offset_x = (m->player_map_x + 0.5) * TILE_SIZE + m->shift_x;
	offset_y = (m->player_map_y + 0.5) * TILE_SIZE + m->shift_y;
	r = 0.f;
	length = fmin(length, MAX_LINE);
	while (r < length)
	{
		x = r * cosf(angle);
		y = r * sinf(angle);
		ft_put_pixel(x + offset_x, y + offset_y, color);
		ft_put_pixel(x + offset_x, y + offset_y + 1, color);
		ft_put_pixel(x + offset_x + 1, y + offset_y, color);
		ft_put_pixel(x + offset_x + 1, y + offset_y + 1, color);
		r += 0.1f;
	}
}

int	is_sprite(t_prog *p, int x, int y)
{
	int	i;

	i = 0;
	while (p->sprites[i])
	{
		if (p->sprites[i]->health > 0 && x == (int)(p->sprites[i]->x)
			&& y == (int)(p->sprites[i]->y))
			return (1);
		i++;
	}
	return (0);
}

void	draw_minimap(t_prog *prog)
{
	t_mini_map	m;
	int			x;
	int			y;

	init_minimap(prog, &m);
	y = m.y_start - 1;
	while (++y < m.y_end)
	{
		x = m.x_start - 1;
		m.map_y = y / TILE_SIZE;
		while (++x < m.x_end && x / TILE_SIZE < (int)ft_strlen(m.map[m.map_y]))
		{
			m.map_x = x / TILE_SIZE;
			if (m.map[m.map_y][m.map_x] == '1')
				ft_put_pixel(x + m.shift_x, y + m.shift_y, 0xffffff);
			else if (ft_in(m.map[m.map_y][m.map_x], "WSEN0emh"))
				ft_put_pixel_in(x + m.shift_x, y + m.shift_y, 100 << 24);
			if (m.map_x == m.player_map_x && m.map_y == m.player_map_y)
				ft_put_pixel(x + m.shift_x, y + m.shift_y, 0xffd700);
			if (m.map[m.map_y][m.map_x] == 'h')
				ft_put_pixel(x + m.shift_x, y + m.shift_y, 0xff00ff);
		}
	}
	draw_dir(atan2(prog->player.dir_y, prog->player.dir_x), 20, &m, 0xffd700);
}
