/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:46:28 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 17:53:41 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	setup(t_prog *prog, char *file)
{
	t_file_data	*data;

	data = read_file(file);
	if (!data)
		return (0);
	printf("Load types\n");
	if (!load_types(prog, data->types))
		return (0);
	printf("Load map\n");
	if (!load_map(data->map))
		return (0);
	init_player_pos(&prog->player);
	free_all(NULL);
	return (1);
}
