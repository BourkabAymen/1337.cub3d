/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:38:46 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 18:23:25 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	prog_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

static int	start_cub3d(char *file)
{
	t_prog	*prog;

	prog = get_prog();
	if (!prog)
		return (prog_error());
	if (!init_mlx(prog))
		return (prog_error());
	if (!setup(prog, file))
		return (prog_error());
	start_game(prog);
	mlx_hook(prog->win, ON_KEYDOWN, 1, on_key_down, prog);
	mlx_hook(prog->win, ON_KEYUP, 1L << 1, on_key_up, prog);
	mlx_hook(prog->win, ON_DESTROY, 0, exit_cube3d, prog);
	mlx_loop(prog->mlx);
	return (1);
}

int	main(int ac, char **av)
{
	if (check_arg(ac, av))
	{
		if (start_cub3d(av[1]))
			return (0);
		return (1);
	}
	return (1);
}
