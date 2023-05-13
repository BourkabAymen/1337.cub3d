/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:00:50 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 17:30:23 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_player *player)
{
	player->x = 0.0;
	player->y = 0.0;
	player->dir_x = -1.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.66;
	player->map = NULL;
}

t_prog	*get_prog(void)
{
	static t_prog	*prog;

	if (!prog)
	{
		prog = ft_malloc(sizeof(t_prog));
		prog->img.img = NULL;
		prog->img.addr = NULL;
		prog->pressed_key[0] = -1;
		prog->pressed_key[1] = -1;
		prog->pressed_key[2] = -1;
		prog->floor[0] = -1;
		prog->floor[1] = -1;
		prog->tex[0] = NULL;
		prog->tex[1] = NULL;
		prog->tex[2] = NULL;
		prog->tex[3] = NULL;
		init_player(&prog->player);
	}
	return (prog);
}
