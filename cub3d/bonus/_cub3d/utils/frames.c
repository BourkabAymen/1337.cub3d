/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:01:30 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 13:10:22 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_over(t_prog *prog)
{
	int		x;
	int		y;
	t_tex	*tex;

	replace_image(prog, WIDTH, HEIGHT);
	if (prog->frame % 100 > 50)
		tex = prog->static_tex.game_over[0];
	else
		tex = prog->static_tex.game_over[1];
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_put_pixel(x, y, get_tex_color(tex, x * tex->width / WIDTH,
					y * tex->height / HEIGHT));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(prog->mlx, prog->win, prog->img.img, 0, 0);
}

void	img_1(t_prog *prog)
{
	t_data	img;
	int		x;
	int		y;
	char	*dst;

	img.img_w = WIDTH;
	img.img_h = HEIGHT;
	img.img = mlx_new_image(prog->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, \
		&(img.bits_per_pixel), &(img.line_length), &(img.endian));
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			dst = img.addr + (y * img.line_length
					+ x * (img.bits_per_pixel / 8));
			if (y < 30 && x < 200)
				*(unsigned int *)dst = 0xff000000;
			else
				*(unsigned int *)dst = 0xddffffff;
		}
	}
	prog->static_tex.img[0] = img;
}

void	img_2(t_prog *prog)
{
	t_data	img;

	img.img = mlx_new_image(prog->mlx, 200, 30);
	img.addr = mlx_get_data_addr(img.img, \
		&(img.bits_per_pixel), &(img.line_length), &(img.endian));
	prog->static_tex.img[1] = img;
}
