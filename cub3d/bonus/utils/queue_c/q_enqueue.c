/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_enqueue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:25:43 by aben-ham          #+#    #+#             */
/*   Updated: 2022/03/29 13:07:04 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int	q_enqueue(t_queue *queue, void *p)
{
	t_node	*new;

	new = s_malloc(sizeof(t_node));
	new->p = p;
	new->next = NULL;
	if (!queue->first)
	{
		queue->first = new;
		queue->last = new;
	}
	else
	{
		queue->last->next = new;
		queue->last = new;
	}
	queue->len++;
	return (1);
}
