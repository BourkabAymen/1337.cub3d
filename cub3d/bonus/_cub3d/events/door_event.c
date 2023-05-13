/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:18:52 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 13:08:52 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	switch_d(t_prog *prog, t_m_info **map, int x, int y)
{
	map[y][x].timer += TIMER_CONST * map[y][x].on;
	if (map[y][x].on < 0)
		prog->player.map[y][x] = '1';
	if (map[y][x].timer >= 1.0f)
	{
		prog->player.map[y][x] = '0';
		map[y][x].timer = 1.0;
	}
	if (map[y][x].timer <= 0.0f)
		map[y][x].timer = 0;
	if (map[y][x].timer >= 1.0f || map[y][x].timer <= 0.0f)
		map[y][x].on = 0;
}

void	door_events(t_prog *prog)
{
	t_m_info	**map;
	int			x;
	int			y;

	map = prog->player.map_info;
	y = -1;
	while (prog->player.map[++y])
	{
		x = -1;
		while (prog->player.map[y][++x])
		{
			if (!map[y][x].on)
				continue ;
			switch_d(prog, map, x, y);
		}
	}
}
