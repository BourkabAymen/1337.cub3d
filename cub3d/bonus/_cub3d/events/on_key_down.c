/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:48:34 by aben-ham          #+#    #+#             */
/*   Updated: 2022/05/26 15:11:12 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_key_down(int keycode, t_prog *prog)
{
	if (keycode == KEY_L || keycode == KEY_R)
		prog->pressed_key[0] = keycode;
	else if (keycode == KEY_S || keycode == KEY_W)
		prog->pressed_key[1] = keycode;
	else if (keycode == KEY_A || keycode == KEY_D)
		prog->pressed_key[2] = keycode;
	return (0);
}
