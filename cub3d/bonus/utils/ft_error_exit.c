/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:33:47 by aben-ham          #+#    #+#             */
/*   Updated: 2022/03/29 12:36:09 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void	ft_error_exit(const char *str)
{
	free_all(NULL);
	write(2, str, ft_strlen(str));
	exit(1);
}
