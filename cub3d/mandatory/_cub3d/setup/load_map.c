/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:08:17 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 18:02:30 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**get_map_matrix(t_queue *map)
{
	char	**data;
	int		i;

	if (map->len < 3L)
		return (0);
	data = s_malloc(sizeof(char *) * (map->len + 1));
	i = 0;
	while (1)
	{
		data[i] = q_dequeue(map);
		if (!data[i])
			break ;
		i++;
	}
	return (data);
}

static void	exclude_map(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		ft_addrs_exclude(data[i]);
		i++;
	}
	ft_addrs_exclude(data);
}

int	load_map(t_queue *map)
{
	char	**data;

	data = get_map_matrix(map);
	if (!data)
		return (0);
	printf("check_map\n");
	if (!check_map(data))
		return (0);
	exclude_map(data);
	get_prog()->player.map = data;
	return (1);
}
