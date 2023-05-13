/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addrs_exclude.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:57:32 by aben-ham          #+#    #+#             */
/*   Updated: 2022/03/29 13:10:12 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_addrs_exclude(void *p)
{
	t_add_node	*node;
	t_add_node	*list;

	if (!p)
		return ;
	list = add_address(NULL, 1);
	node = list;
	while (node)
	{
		if (node->p == p)
		{
			node->p = NULL;
			break ;
		}
		node = node->next;
	}
}
