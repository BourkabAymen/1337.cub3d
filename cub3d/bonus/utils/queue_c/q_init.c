/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:24:01 by aben-ham          #+#    #+#             */
/*   Updated: 2022/03/29 13:07:10 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	*q_init(void)
{
	t_queue	*new_queue;

	new_queue = s_malloc(sizeof(t_queue));
	new_queue->first = NULL;
	new_queue->last = NULL;
	new_queue->len = 0;
	return (new_queue);
}
