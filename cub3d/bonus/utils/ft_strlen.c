/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:50:11 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/22 10:20:21 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// strlen count the number of characters in a given string
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
