/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbel-bas <mbel-bas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:03:58 by aben-ham          #+#    #+#             */
/*   Updated: 2022/03/29 13:55:01 by mbel-bas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>
# include <unistd.h>

# define ERR_MALLOC "MALLOC ERROR: not enough memory\n"

typedef struct s_add_node
{
	void				*p;
	struct s_add_node	*next;
}	t_add_node;

void		malloc_error(void);
t_add_node	*add_address(void *new, int get);
void		*s_malloc(size_t size);
void		*ft_malloc(size_t size);
void		ft_addrs_exclude(void *p);
void		*free_all(void *p);

#endif
