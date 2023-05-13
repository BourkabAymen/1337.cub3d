/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:45:54 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 14:01:10 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	gun_center(void)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			ft_put_pixel(x + WIDTH / 2 - 2, y + HEIGHT / 2 - 2, 0xff0000);
			x++;
		}
		y++;
	}
}

static t_tex	*get_gun_tex(t_prog *prog)
{
	if (prog->player.gun_counter >= 5)
		return (prog->static_tex.gun[0]);
	if (prog->player.gun_counter == 4)
		add_bullet(create_bullet(prog, prog->player.x,
				prog->player.y, 1), prog->player.dir_x, prog->player.dir_y);
	return (prog->static_tex.gun[prog->player.gun_counter++]);
}

void	draw_gun(t_prog *prog)
{
	int			x;
	int			y;
	int			c;
	t_tex		*tex;

	tex = get_gun_tex(prog);
	y = 0;
	while (y < HEIGHT)
	{
		x = WIDTH * 0.18;
		while (x < WIDTH * 0.82)
		{
			c = get_tex_color(tex,
					(x - WIDTH * 0.18) * tex->width / (WIDTH * 0.64),
					(y) * tex->height / (HEIGHT));
			if (c != -16777216)
				ft_put_pixel(x + WIDTH * 0.0875, y, c);
			x++;
		}
		y++;
	}
	gun_center();
}

void	health_bar(t_prog *prog)
{
	int	x;
	int	y;
	int	w;
	int	h;

	y = 0;
	w = (int)PLAYER_HEALTH;
	h = HEIGHT / 50;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (y == 0 || y == h - 1 || x == 0 || x == w - 1)
				ft_put_pixel(x + (WIDTH - w) / 2, y + (HEIGHT - h) - 3, 0);
			else if (x < prog->player.health)
				ft_put_pixel(x + (WIDTH - w) / 2, y + (HEIGHT - h) - 3,
					0x00ff00);
			x++;
		}
		y++;
	}
}
