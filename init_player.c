/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:56:49 by aben-ham          #+#    #+#             */
/*   Updated: 2022/05/28 14:36:05 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player_direction(char direction, t_player *p)
{
	double	angle;
	double	old_dir_x;
	double	old_plane_x;

	p->dir_x = -1.0;
	p->dir_y = 0.0;
	p->plane_x = 0.0;
	p->plane_y = 0.66;
	if (direction == 'E')
		angle = M_PI;
	else if (direction == 'N')
		angle = M_PI_2;
	else if (direction == 'S')
		angle = M_PI * 1.5;
	else
		return ;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
	p->dir_y = old_dir_x * sin(angle) + p->dir_y * cos(angle);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(angle) - p->plane_y * sin(angle);
	p->plane_y = old_plane_x * sin(angle) + p->plane_y * cos(angle);
}

void	init_player_pos(t_player *player)
{
	int		x;
	int		y;
	char	**map;

	map = player->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_in(map[y][x], "NSEW"))
			{
				player->x = (double)x + 0.2;
				player->y = (double)y + 0.2;
				init_player_direction(map[y][x], player);
				return ;
			}
			x++;
		}
		y++;
	}
}
