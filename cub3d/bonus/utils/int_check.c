/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:35:59 by aben-ham          #+#    #+#             */
/*   Updated: 2022/03/29 18:36:19 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

static int	is_blank(char c)
{
	if (c == ' ' || c == '\f'
		|| c == '\v' || c == '\t' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

int	int_check(char *str)
{
	int					signe;
	unsigned long long	res;

	while (is_blank(*str))
		str++;
	signe = 1;
	if (*str == '-')
		signe = -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10;
		res = res + (*str - '0');
		if ((res > 0x7fffffff && signe == 1)
			|| (res > 0x80000000 && signe == -1))
			return (0);
		str++;
	}
	return (*str == 0);
}
