/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 09:24:02 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 18:17:39 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_color(char *str)
{
	char	**colors;
	int		c;
	int		i;

	colors = ft_split(str, ',');
	i = 0;
	while (colors[i] && int_check(colors[i]))
	{
		c = ft_atoi(colors[i]);
		if (c < 0 || c > 255)
			return (0);
		i++;
	}
	if (i != 3)
		return (0);
	return (1);
}

int	get_color(char *color)
{
	char	**colors;
	int		c[3];

	colors = ft_split(color, ',');
	c[0] = ft_atoi(colors[0]);
	c[1] = ft_atoi(colors[1]);
	c[2] = ft_atoi(colors[2]);
	return (c[0] << 16 | c[1] << 8 | c[2]);
}

int	set_type(t_prog *prog, int i, char *data)
{
	if (i < 4)
	{
		if (prog->tex[i])
			return (0);
		prog->tex[i] = get_texture(prog, data);
		if (!prog->tex[i])
			return (0);
	}
	else
	{
		i -= 4;
		if (prog->floor[i] != -1 || !is_valid_color(data))
			return (0);
		prog->floor[i] = get_color(data);
	}
	return (1);
}

int	load_types(t_prog *prog, t_queue *types)
{
	char	**tab;
	int		i;

	tab = q_dequeue(types);
	while (tab)
	{
		i = -1;
		if (ft_strcmp(tab[0], "NO"))
			i = NO;
		else if (ft_strcmp(tab[0], "SO"))
			i = SO;
		else if (ft_strcmp(tab[0], "WE"))
			i = WE;
		else if (ft_strcmp(tab[0], "EA"))
			i = EA;
		else if (ft_strcmp(tab[0], "F"))
			i = F;
		else if (ft_strcmp(tab[0], "C"))
			i = C;
		if (!set_type(prog, i, tab[1]))
			return (0);
		tab = q_dequeue(types);
	}
	return (1);
}
