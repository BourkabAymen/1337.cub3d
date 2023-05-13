/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 09:24:02 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 18:26:21 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define PNG 0
#define XPM 1

static int	tex_extension(char *str)
{
	char	*ext;

	ext = ft_strrchr(str, '.');
	if (ft_strcmp(ext, ".png"))
		return (PNG);
	else if (ft_strcmp(ext, ".xpm"))
		return (XPM);
	return (-1);
}

static int	format_tex_queue(t_queue *tex)
{
	t_node	*node;
	char	**split;

	if ((int)tex->len >= TEX_BUFFER_SIZE)
		return (0);
	node = tex->first;
	while (node)
	{
		split = ft_split(node->p, ' ');
		if (!split || ft_arrlen(split) != 2)
			return (0);
		node->p = split;
		node = node->next;
	}
	return (1);
}

t_tex	*get_texture(t_prog *prog, char *path)
{
	t_tex	*img;
	int		ext;

	ext = tex_extension(path);
	if (ext == -1)
		return (NULL);
	img = ft_malloc(sizeof(t_tex));
	if (ext == XPM)
		img->tex
			= mlx_xpm_file_to_image(prog->mlx, path, &img->width, &img->height);
	else
		img->tex
			= mlx_png_file_to_image(prog->mlx, path, &img->width, &img->height);
	if (!(img->tex))
		return (NULL);
	img->ptr
		= mlx_get_data_addr(img->tex, &img->bpp, &img->size_line, &img->endian);
	if (!(img->ptr))
		return (NULL);
	return (img);
}

int	load_textures(t_prog *prog, t_queue *tex)
{
	int		i;
	t_node	*node;

	if (!format_tex_queue(tex))
		return (0);
	i = 0;
	node = tex->first;
	while (node)
	{
		prog->texs[i] = get_texture(prog, ((char **)(node->p))[1]);
		node->p = ((char **)(node->p))[0];
		if (!prog->texs[i])
		{
			while (--i >= 0)
			{
				mlx_destroy_image(prog->mlx, prog->texs[i]->tex);
				free(prog->texs[i]);
			}	
			return (0);
		}
		i++;
		node = node->next;
	}
	return (1);
}
