/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:35:59 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 08:20:12 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	switch_door(t_prog *prog)
{
	t_player	*p;
	t_ray		ray;

	p = &prog->player;
	raycasting(0.0, &ray, p);
	if (ray.hit_door && ray.door_dist <= 1.4 && ray.door_dist >= 0.2
		&& !prog->player.map_info[ray.door_y][ray.door_x].on)
	{
		if (prog->player.map_info[ray.door_y][ray.door_x].timer == 0)
			prog->player.map_info[ray.door_y][ray.door_x].on = 1;
		else
			prog->player.map_info[ray.door_y][ray.door_x].on = -1;
	}
}

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
		else if (keycode == KEY_SPACE)
		{
			prog->player.timer += 1;
			switch_door(prog);
		}
	}
	if (prog->player.health <= 0)
	{
		prog->player.health = PLAYER_HEALTH;
		prog->nb_die++;
	}
	return (0);
}
