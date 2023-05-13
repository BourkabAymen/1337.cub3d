/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_dequeue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:33:05 by aben-ham          #+#    #+#             */
/*   Updated: 2022/03/05 14:25:59 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	*q_dequeue(t_queue *queue)
{
	t_node	*node;
	void	*p;

	node = queue->first;
	if (!node)
		return (NULL);
	if (node == queue->last)
		queue->last = NULL;
	queue->first = node->next;
	p = node->p;
	queue->len--;
	return (p);
}
