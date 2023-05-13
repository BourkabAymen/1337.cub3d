/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:03:39 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 18:38:57 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

static int	num_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*res;

	count = num_len(n);
	if (n < 0)
		count++;
	res = s_malloc(count + 1);
	if (!res)
		return (NULL);
	*(res + count) = 0;
	if (n == 0)
		*res = '0';
	else
	{
		while (n != 0)
		{
			*(res + count - 1) = ft_abs(n % 10) + '0';
			count--;
			n = n / 10;
		}
		if (count == 1)
			*(res) = '-';
	}
	return (res);
}
