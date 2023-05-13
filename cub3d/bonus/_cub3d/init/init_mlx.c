/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:01:18 by aben-ham          #+#    #+#             */
/*   Updated: 2022/05/27 10:30:56 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*init_mlx(t_prog *prog)
{
	prog->mlx = mlx_init();
	prog->win = mlx_new_window(prog->mlx, WIDTH, HEIGHT, WIN_TITLE);
	if (!prog->mlx || !prog->win)
		return (NULL);
	return (prog);
}
