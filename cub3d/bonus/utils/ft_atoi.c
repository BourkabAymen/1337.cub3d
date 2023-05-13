/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:15:15 by aben-ham          #+#    #+#             */
/*   Updated: 2022/03/28 14:29:27 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

#define M 9223372036854775808U

static int	is_blank(char c)
{
	if (c == ' ' || c == '\f'
		|| c == '\v' || c == '\t' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
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
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (res >= M && (*str - '0') > 5)
		{
			if (signe < 0)
				return (0);
			if (signe > 0)
				return (-1);
		}
		res = res * 10;
		res = res + (*str - '0');
		str++;
	}
	return (res * signe);
}
