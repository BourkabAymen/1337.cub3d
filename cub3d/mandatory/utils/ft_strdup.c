/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:18:05 by aben-ham          #+#    #+#             */
/*   Updated: 2022/03/29 13:05:42 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utilities.h>

/*
* The strdup() function allocates sufficient memory 
	for a copy of the string s1,does the copy, and 
	returns a pointer to it.
*/

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	s1_len;

	s1_len = ft_strlen((char *)s1);
	s2 = s_malloc(s1_len + 1);
	ft_strlcpy(s2, s1, s1_len + 1);
	return (s2);
}
