/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:42:23 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 17:43:05 by aben-ham         ###   ########.fr       */
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
