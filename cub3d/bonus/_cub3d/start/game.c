/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:02:20 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 15:20:43 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	wall_tex(t_prog *prog, int x, int y, int side)
{
	t_m_info	**map_info;

	map_info = prog->player.map_info;
	if (side == SO && map_info[y - 1][x].type == 'D')
		return (get_tex(x, y - 1)[1]);
	else if (side == NO && map_info[y + 1][x].type == 'D')
		return (get_tex(x, y + 1)[1]);
	else if (side == EA && map_info[y][x - 1].type == 'D')
		return (get_tex(x - 1, y)[1]);
	else if (side == WE && map_info[y][x + 1].type == 'D')
		return (get_tex(x + 1, y)[1]);
	return (get_tex(x, y)[side]);
}

static t_tex	*tex_line(t_prog *prog, t_ray *ray, t_point *line, double *step)
{
	int		tex_index;
	t_tex	*tex;
	int		i;

	if (prog->player.map_info[ray->map_y][ray->map_x].type == 'D')
		tex_index = get_tex(ray->map_x, ray->map_y)[0];
	else
		tex_index = wall_tex(prog, ray->map_x, ray->map_y, ray->side);
	tex = prog->texs[tex_index];
	i = HEIGHT - prog->m_y;
	line->x = -0.5 * ray->line_height + i;
	line->y = 0.5 * ray->line_height + i;
	*step = 1.0 * tex->height / ray->line_height;
	return (tex);
}

static void	draw_tex_line(t_prog *prog, int win_x, t_ray *ray)
{
	t_point	line;
	int		x;
	double	y;
	double	step;
	t_tex	*tex;

	tex = tex_line(prog, ray, &line, &step);
	y = 0;
	if (line.x < 0)
	{
		y = -line.x * step;
		line.x = 0;
	}
	line.y = min(line.y, HEIGHT);
	x = tex->width * ray->wall_x;
	if (prog->player.map_info[ray->map_y][ray->map_x].type == 'D')
		x -= prog->player.map_info[ray->map_y][ray->map_x].timer * tex->width;
	while (line.x < line.y)
	{
		ft_put_pixel(win_x, line.x,
			shade_color(get_tex_color(tex, x, y), ray->dist * 0.4));
		line.x++;
		y += step;
	}
}

void	game(t_prog *prog)
{
	t_ray		ray;
	int			x;
	double		camera_x;
	double		z_buffer[WIDTH];

	replace_image(prog, WIDTH, HEIGHT);
	x = -1;
	draw_floor(prog);
	while (++x < WIDTH)
	{
		camera_x = 2 * x / (double)WIDTH - 1.0;
		raycasting(camera_x, &ray, &prog->player);
		z_buffer[x] = ray.dist;
		draw_tex_line(prog, x, &ray);
	}
	sprite(prog, z_buffer);
	draw_gun(prog);
	health_bar(prog);
	draw_minimap(prog);
	perform_events(prog);
	mlx_put_image_to_window(prog->mlx, prog->win, prog->img.img, 0, 0);
}
