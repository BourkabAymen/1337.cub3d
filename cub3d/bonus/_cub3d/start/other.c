/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 12:49:46 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 11:01:45 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_sprite_key(char c)
{
	return (ft_in(c, "emhb"));
}

int	ft_rand(void)
{
	static int	x;

	x = (1103515245 * x + 12345) % 0x7fffffff;
	return (x & 0x7fffffff);
}
