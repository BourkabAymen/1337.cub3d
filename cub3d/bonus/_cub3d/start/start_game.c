/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:03:21 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 15:32:32 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	change_mouse_location(t_prog *prog)
{
	int	x;
	int	y;
	int	to_x;

	if (prog->m_y < 0 || prog->m_y > HEIGHT)
		mlx_mouse_show();
	else
		mlx_mouse_hide();
	to_x = -1;
	if (prog->m_x > WIDTH)
		to_x = 0;
	if (prog->m_x < 0)
		to_x = WIDTH;
	if (to_x == -1)
		return ;
	mlx_mouse_get_pos(prog->win, &x, &y);
	mlx_mouse_move(prog->win, to_x, y);
	prog->old_m_x = to_x;
	prog->m_x = to_x;
}

static void	write_text(t_prog *prog)
{
	static int	nb[2] = {-1};
	t_sprite	**s;
	char		*str;
	int			c;

	c = 0;
	s = prog->sprites;
	while (*s)
	{
		if (((*s)->k == 'e' | (*s)->k == 'm') && !(*s)->is_die)
			c++;
		s++;
	}
	if (nb[0] != c || nb[1] != prog->nb_die)
	{
		nb[0] = c;
		nb[1] = prog->nb_die;
		str = ft_strjoin("Enemies: ", ft_itoa(c));
		str = ft_strjoin(str, " Die: ");
		str = ft_strjoin(str, ft_itoa(prog->nb_die));
		mlx_put_image_to_window(prog->mlx, prog->win,
			prog->static_tex.img[1].img, 0, 0);
		mlx_string_put(prog->mlx, prog->win, 10, 20, 0x00ff00, str);
		free_all(NULL);
	}
}

static int	the_game(t_prog *prog)
{	
	if (prog->player.health > 0)
	{
		change_mouse_location(prog);
		write_text(prog);
		game(prog);
		if (prog->player.hit > 2)
		{
			mlx_put_image_to_window(prog->mlx, prog->win,
				prog->static_tex.img[0].img, 0, 0);
			prog->player.hit--;
		}
	}
	else
	{
		game_over(prog);
	}
	prog->frame++;
	return (0);
}

void	start_game(t_prog *prog)
{
	img_1(prog);
	img_2(prog);
	mlx_loop_hook(prog->mlx, the_game, prog);
}
