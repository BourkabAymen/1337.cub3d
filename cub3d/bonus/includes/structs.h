/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:48:02 by aben-ham          #+#    #+#             */
/*   Updated: 2022/06/03 15:23:59 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "queue.h"
# include <unistd.h>
# include <pthread.h>

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

typedef struct s_m_info
{
	char	key;
	char	type;
	float	timer;
	int		on;
}	t_m_info;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	char		**map;
	t_m_info	**map_info;
	int			map_len;
	int			map_longest_len;
	double		timer;
	float		health;
	int			hit;
	int			gun_counter;
}	t_player;

typedef struct m_key
{
	char	key;
	char	type;
	int		*tex_index;
}	t_m_key;

typedef struct s_static
{
	t_tex	*gun[5];
	t_tex	*game_over[2];
	t_tex	*enemy_1[12];
	t_tex	*enemy_2[10];
	t_tex	*heal[1];
	t_tex	*bullet[3];
	t_data	img[2];
}	t_static;

typedef struct t_enemy
{
	int		f;
	double	dir_x;
	double	dir_y;
}	t_enemy;

typedef struct s_sprite
{
	char	k;
	double	x;
	double	y;
	double	vx;
	double	vy;
	int		state;
	float	health;
	int		count;
	double	dist;
	int		hit;
	int		is_die;
	t_enemy	*e;
	t_tex	*tex;

}	t_sprite;

typedef struct s_prog
{
	void		*mlx;
	void		*win;
	int			floor[2];
	t_tex		*texs[TEX_BUFFER_SIZE];
	t_static	static_tex;
	t_m_key		*map_keys[KEYS_MAX];
	t_player	player;
	t_sprite	**sprites;
	int			s_len;
	int			s_max;
	t_data		img;
	int			pressed_key[3];
	int			m_x;
	int			m_y;
	int			old_m_x;
	int			old_m_y;
	int			frame;
	int			nb_die;
}	t_prog;

typedef struct t_file_data
{
	t_queue	*texs;
	t_queue	*types;
	t_queue	*map;
}	t_file_data;

typedef struct s_mini_map
{
	char	**map;
	int		map_width;
	int		map_height;
	int		x_start;
	int		x_end;
	int		y_start;
	int		y_end;
	int		p_x;
	int		p_y;
	int		player_map_x;
	int		player_map_y;
	int		shift_x;
	int		shift_y;
	int		map_x;
	int		map_y;
}	t_mini_map;

typedef struct t_floor
{
	double	dist;
	double	floor_x;
	double	floor_y;
	double	step_x;
	double	step_y;
	double	dir_x;
	double	dir_y;
	int		tx;
	int		ty;
	int		m_p;
	int		color;
	int		x;
	int		y;
	t_tex	*tex;
}	t_floor;

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
	int		hit_door;
	int		door_x;
	int		door_y;
	double	door_dist;
	double	door_wall_x;
	int		door_side;
}	t_ray;

#endif
