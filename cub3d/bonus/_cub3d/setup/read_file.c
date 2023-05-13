/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:41:51 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 10:26:00 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_file_data	*init_data(void)
{
	t_file_data	*data;

	data = s_malloc(sizeof(t_file_data));
	data->texs = q_init();
	data->types = q_init();
	data->map = q_init();
	return (data);
}

static void	to_queue(t_file_data *data, int state, char *line)
{
	if (state == 1)
		q_enqueue(data->texs, line);
	else if (state == 2)
		q_enqueue(data->types, line);
	else if (state == 3)
		q_enqueue(data->map, line);
}

static t_file_data	*get_file_data_fd(t_file_data *data, int fd)
{
	char		*line;
	int			state;

	state = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (state != 3)
			line = ft_strtrim(line, " \n");
		else
			line = ft_strtrim(line, "\n");
		if (is_empty_line(line) || (is_comment(line) && state != 3))
			continue ;
		if (ft_strcmp(line, "---start---"))
			state++;
		else
			to_queue(data, state, line);
	}
	if (state != 3 || data->texs->len <= 0 || data->texs->len <= 1)
		return (NULL);
	return (data);
}

t_file_data	*read_file(char *file)
{
	t_file_data	*data;
	int			fd;

	fd = open(file, O_RDONLY);
	data = init_data();
	data = get_file_data_fd(data, fd);
	close(fd);
	return (data);
}
