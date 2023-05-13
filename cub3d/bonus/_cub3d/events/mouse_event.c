/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:52:46 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 08:16:50 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_mouse_up(int button, int x, int y, t_prog *prog)
{
	x = 0;
	y = 0;
	if (button == 1)
		prog->player.gun_counter = 0;
	return (0);
}
