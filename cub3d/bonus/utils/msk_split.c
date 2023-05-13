/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msk_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:29:10 by aben-ham          #+#    #+#             */
/*   Updated: 2022/03/29 12:35:28 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

char	*get_mask(const char *str, int (*f)(char c))
{
	size_t	l;
	char	*mask;

	l = 0;
	while (str[l])
		l++;
	mask = s_malloc(l + 1);
	l = 0;
	while (str[l])
	{
		mask[l] = f(str[l]) + '0';
		l++;
	}
	mask[l] = 0;
	return (mask);
}

size_t	mask_type_len(char *mask)
{
	char	c;
	size_t	len;

	c = mask[0];
	len = 0;
	while (mask[len] == c)
		len++;
	return (len);
}

size_t	nb_place(char *mask)
{
	size_t	len;

	len = 0;
	if (!(*mask))
		return (0);
	while (1)
	{
		if (mask[0] != '1')
			len++;
		mask = mask + mask_type_len(mask);
		if (!mask[0])
			break ;
	}
	return (len);
}

void	fill_table(char **tab, size_t count, char const *s, char *mask)
{
	size_t	len;
	size_t	i;

	while (count > 0)
	{
		len = mask_type_len(mask);
		if (mask[0] != '1')
		{
			*tab = s_malloc(len + 1);
			i = (size_t)(-1);
			while (++i < len)
				(*tab)[i] = s[i];
			(*tab)[i] = 0;
			tab++;
			count--;
		}
		mask = mask + len;
		s = s + len;
	}
	*tab = NULL;
}

char	**msk_split(char const *s, int (*f)(char c))
{
	size_t	len;
	char	**tab;
	char	*mask;

	if (!s || !f)
		return (NULL);
	f(0);
	mask = get_mask(s, f);
	len = nb_place(mask);
	tab = s_malloc(sizeof(char *) * (len + 1));
	fill_table(tab, len, s, mask);
	return (tab);
}
