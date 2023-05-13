/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_address.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:56:10 by aben-ham          #+#    #+#             */
/*   Updated: 2022/03/29 13:10:00 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_add_node	*create_node(void *new)
{
	t_add_node	*new_node;

	new_node = malloc(sizeof(t_add_node));
	if (!new_node)
		malloc_error();
	new_node->p = new;
	new_node->next = NULL;
	return (new_node);
}

t_add_node	*add_address(void *new, int get)
{
	static t_add_node	*adds;
	t_add_node			*node;

	if (get == 1)
		return (adds);
	else if (get == 2)
	{
		adds = NULL;
		return (NULL);
	}
	if (!adds)
		adds = create_node(new);
	else
	{
		node = adds;
		while (node)
		{
			if (!node->next)
				break ;
			node = node->next;
		}
		node->next = create_node(new);
	}
	return (adds);
}
