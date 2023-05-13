/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:20:39 by aben-ham          #+#    #+#             */
/*   Updated: 2022/03/29 13:10:27 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*s_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		malloc_error();
	add_address(p, 0);
	return (p);
}

void	*ft_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		malloc_error();
	return (p);
}
