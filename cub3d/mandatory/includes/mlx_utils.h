/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:33:52 by aben-ham          #+#    #+#             */
/*   Updated: 2022/05/25 20:52:38 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# define KEY_L 124
# define KEY_R 123
# define KEY_A 0
# define KEY_D 2
# define KEY_W 13
# define KEY_S 1
# define KEY_SPACE 49
# define KEY_ESC 53

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	*mlx_png_file_to_image(void *mlx_ptr, char *file,
			int *width, int *height);
int		mlx_mouse_hide(void);
int		mlx_mouse_show(void);
int		mlx_mouse_move(void *win_ptr, int x, int y);
int		mlx_mouse_get_pos(void *win_ptr, int *x, int *y);

#endif
