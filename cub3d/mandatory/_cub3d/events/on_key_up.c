/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:35:59 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 16:29:42 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_key_up(int keycode, t_prog *prog)
{
	if (keycode == KEY_ESC)
		return (exit_cube3d(prog));
	else
	{
		if (keycode == KEY_L || keycode == KEY_R)
			prog->pressed_key[0] = -1;
		else if (keycode == KEY_S || keycode == KEY_W)
			prog->pressed_key[1] = -1;
		else if (keycode == KEY_A || keycode == KEY_D)
			prog->pressed_key[2] = -1;
	}
	return (0);
}
