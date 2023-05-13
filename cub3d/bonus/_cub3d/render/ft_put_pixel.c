/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:17:45 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 14:00:47 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel(int x, int y, int color)
{
	static t_prog	*prog;
	char			*dst;

	if (!prog)
		prog = get_prog();
	if (y < 30 && x < 200)
		color = 255 << 24;
	if (y >= prog->img.img_h || x >= prog->img.img_w || y < 0 || x < 0)
		return ;
	dst = prog->img.addr + (y * prog->img.line_length \
		+ x * (prog->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_put_pixel_in(int x, int y, int color)
{
	static t_prog	*prog;
	char			*dst;
	float			p;

	if (!prog)
		prog = get_prog();
	if (y >= prog->img.img_h || x >= prog->img.img_w || y < 0 || x < 0)
		return ;
	dst = prog->img.addr + (y * prog->img.line_length \
		+ x * (prog->img.bits_per_pixel / 8));
	if (y < 30 && x < 200)
	{
		*(unsigned int *)dst = 255 << 24;
		return ;
	}
	p = ((float)((color >> 24) & 255) / 255);
	*(unsigned int *)dst = ((int)((((*(unsigned int *)dst) >> 16) & 255)
				* (1 - p) + (((color) >> 16) & 255) * (p)) << 16)
		| ((int)((((*(unsigned int *)dst) >> 8) & 255)
				* (1 - p) + (((color) >> 8) & 255) * (p)) << 8)
		| ((int)(((*(unsigned int *)dst) & 255) * (1 - p)
				+ ((color) & 255) * (p)));
}
