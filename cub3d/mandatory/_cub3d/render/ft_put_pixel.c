/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:17:45 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 16:37:46 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel(int x, int y, int color)
{
	static t_prog	*prog;
	char			*dst;

	if (!prog)
		prog = get_prog();
	if (y >= prog->img.img_h || x >= prog->img.img_w || y < 0 || x < 0)
		return ;
	dst = prog->img.addr + (y * prog->img.line_length \
		+ x * (prog->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
