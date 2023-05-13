/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:41:51 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 17:54:57 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	msk_type_split(char c)
{
	static int	flag;

	if (c == 0)
	{
		flag = 0;
		return (0);
	}
	if (c == ' ' && !flag)
		flag = 1;
	else if (c != ' ' && flag)
		flag = 2;
	if (flag == 2 || !flag)
		return (0);
	return (1);
}

static int	to_queue(t_file_data *data, int i, char *line)
{
	char	**split;

	if (i < 6)
	{
		split = msk_split(line, msk_type_split);
		if (ft_arrlen(split) != 2)
			return (0);
		q_enqueue(data->types, split);
	}
	else
		q_enqueue(data->map, line);
	return (1);
}

static t_file_data	*get_file_data_fd(t_file_data *data, int fd)
{
	char		*line;
	int			i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (i < 6)
			line = ft_strtrim(line, " \n");
		else
			line = ft_strtrim(line, "\n");
		if (!line[0] || (line[0] == '\n' && !line[1]))
			continue ;
		if (!to_queue(data, i, line))
			return (NULL);
		i++;
	}
	if (i < 6)
		return (NULL);
	return (data);
}

t_file_data	*read_file(char *file)
{
	t_file_data	*data;
	int			fd;

	fd = open(file, O_RDONLY);
	data = s_malloc(sizeof(t_file_data));
	data->types = q_init();
	data->map = q_init();
	data = get_file_data_fd(data, fd);
	close(fd);
	return (data);
}
