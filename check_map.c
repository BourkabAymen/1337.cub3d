/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:09:54 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 18:22:36 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_char(char **map)
{
	int	y;
	int	x;
	int	p;

	y = 0;
	p = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_in(map[y][x], "WSNE01"))
				return (0);
			if (ft_in(map[y][x], "WSEN"))
				p++;
			x++;
		}
		y++;
	}
	if (p != 1)
		printf("Error: One player\n");
	return (1 && p == 1);
}

static int	one_rec(char **map, char **copy, int x, int y)
{
	if (copy[y][x] == 1 || map[y][x] == '1')
		return (1);
	if (x == 0 || y == 0 || !map[y + 1] || !map[y][x + 1] || map[y][x] == ' ')
		return (0);
	copy[y][x] = 1;
	if (!one_rec(map, copy, x - 1, y) || !one_rec(map, copy, x + 1, y)
		|| !one_rec(map, copy, x, y + 1) || !one_rec(map, copy, x, y - 1))
		return (0);
	return (1);
}

static int	check_surrounded_by_one(char **map)
{
	char	**copy;
	int		i;
	int		j;

	copy = s_malloc(sizeof(char *) * (ft_arrlen(map)));
	j = -1;
	while (map[++j])
	{
		copy[j] = s_malloc(ft_strlen(map[j]));
		ft_memset(copy[j], 0, ft_strlen(map[j]));
	}
	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
			if (map[j][i] != '1' && map[j][i] != ' '
				&& !copy[j][i] && !one_rec(map, copy, i, j))
				return (0);
	}
	return (1);
}

int	check_map(char **map)
{
	int	i;

	printf("check surrounded by ones\n");
	if (!check_surrounded_by_one(map))
		return (0);
	i = -1;
	while (map[++i])
		ft_str_replace(map[i], ' ', '0');
	printf("check chars\n");
	if (!check_char(map))
		return (0);
	return (1);
}
