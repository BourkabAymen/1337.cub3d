/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:02:37 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 13:59:37 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	search_tex_index(t_queue *texs, char *str)
{
	t_node	*node;
	char	*tex;
	int		i;

	i = 0;
	node = texs->first;
	while (node)
	{
		tex = node->p;
		if (ft_strcmp(str, tex))
			return (i);
		node = node->next;
		i++;
	}
	return (-1);
}

static int	load_floor_ceil(t_prog *prog, char *str, t_queue *texs)
{
	char	**split;

	if (prog->floor[0] != -1)
		return (0);
	split = ft_split(str, ' ');
	if (ft_arrlen(split) != 2)
		return (0);
	prog->floor[0] = search_tex_index(texs, split[0]);
	prog->floor[1] = search_tex_index(texs, split[1]);
	if (prog->floor[0] == -1 || prog->floor[1] == -1)
		return (0);
	return (1);
}

static int	type_msk_split(char c)
{
	static short	counter;

	if (!c)
	{
		counter = 0;
		return (0);
	}
	if (c != ' ')
		counter++;
	if (c != ' ' && counter < 3)
		return (0);
	if (c == ' ' && counter < 3)
		return (1);
	return (0);
}

static t_m_key	*load_key(t_m_key *key, char *str, t_queue *texs)
{
	char	**split;
	int		i;

	split = msk_split(str, type_msk_split);
	if (ft_arrlen(split) != 3)
		return (0);
	key->type = split[0][0];
	key->key = split[1][0] - 33;
	split = ft_split(split[2], ' ');
	i = ft_arrlen(split);
	if (ft_in(key->key + 33, "NSWE0") || is_sprite_key(key->key + 33)
		|| key->key < 0 || key->key >= KEYS_MAX || (key->type == 'W' && i != 4)
		|| (key->type == 'D' && i != 2) || (key->type == 'S' && i != 1)
		|| (key->type == 'Q' && i != 1))
		return (0);
	key->tex_index = ft_malloc(sizeof(int) * (ft_arrlen(split) + 1));
	i = -1;
	while (split[++i])
	{
		key->tex_index[i] = search_tex_index(texs, split[i]);
		if (key->tex_index[i] == -1)
			return (0);
	}
	key->tex_index[i] = -1;
	return (key);
}

//len(types) >= 2 checked by get_file_data
int	load_types(t_prog *prog, t_queue *texs, t_queue *types)
{
	t_node	*node;
	char	*str;
	t_m_key	*key;

	node = types->first;
	while (node)
	{
		str = node->p;
		if (*str == 'F' && !load_floor_ceil(prog, str + 1, texs))
			return (0);
		else if (*str != 'F')
		{
			if (!ft_in(*str, "WDSQ"))
				return (0);
			key = ft_malloc(sizeof(t_m_key));
			if (load_key(key, str, texs) && !prog->map_keys[(int)key->key])
				prog->map_keys[(int)key->key] = key;
			else
				return (0);
		}
		node = node->next;
	}
	return (1);
}
