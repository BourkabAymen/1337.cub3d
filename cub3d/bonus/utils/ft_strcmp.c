/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:38:06 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 08:39:23 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

int	ft_strcmp(char *str1, char *str2)
{
	size_t	len;

	len = ft_strlen(str1);
	if (len != ft_strlen(str2))
		return (0);
	return (!ft_strncmp(str1, str2, ft_strlen(str1)));
}
