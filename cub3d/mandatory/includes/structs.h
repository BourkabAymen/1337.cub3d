/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:48:02 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 17:48:10 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "queue.h"
# include <unistd.h>

# define TEX_BUFFER_SIZE 100
# define KEYS_MAX 94
# define TIMER_CONST 0.06f
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
# define C 5
# define S_NUMBER 12

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_pointf
{
	double	x;
	double	y;
}	t_pointf;

typedef struct s_type
{
	char	type;
	char	id;
	char	*data;
}	t_type;

typedef struct s_file
{
	t_queue	**types;
	char	**map;
}	t_file;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_w;
	int		img_h;
}	t_data;

typedef struct s_tex
{
	void	*tex;
	char	*ptr;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_tex;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	char		**map;
}	t_player;

typedef struct s_file_data
{
	t_queue	*types;
	t_queue	*map;
}	t_file_data;

typedef struct s_prog
{
	void		*mlx;
	void		*win;
	int			floor[2];
	t_tex		*tex[4];
	t_player	player;
	t_data		img;
	int			pressed_key[3];
}	t_prog;

typedef struct s_ray
{
	double	x;
	double	y;
	double	pos_x;
	double	pos_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	dist;
	double	wall_x;
	int		side;
	int		line_height;
}	t_ray;

#endif
