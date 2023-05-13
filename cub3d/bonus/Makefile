# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 09:30:37 by aben-ham          #+#    #+#              #
#    Updated: 2022/06/03 18:28:16 by aben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UTIL_FILES = \
	utils/ft_arrlen.c \
	utils/ft_substr.c \
	utils/ft_atoi.c \
	utils/ft_memcpy.c \
	utils/ft_memset.c \
	utils/ft_split.c \
	utils/int_check.c \
	utils/msk_split.c \
	utils/ft_strchr.c \
	utils/ft_strdup.c \
	utils/ft_strjoin.c \
	utils/ft_strlcpy.c \
	utils/ft_strlen.c \
	utils/ft_strncmp.c \
	utils/ft_strrchr.c \
	utils/ft_error.c \
	utils/ft_strtrim.c \
	utils/ft_itoa.c \
	utils/ft_str_replace.c \
	utils/ft_error_exit.c \
	utils/ft_strcmp.c \
	utils/ft_in.c \
	utils/min.c \
	utils/max.c \
	utils/ft_malloc/add_address.c \
	utils/ft_malloc/free_all.c \
	utils/ft_malloc/ft_addrs_exclude.c \
	utils/ft_malloc/malloc.c \
	utils/ft_malloc/malloc_error.c \
	utils/queue_c/q_clear.c \
	utils/queue_c/q_dequeue.c \
	utils/queue_c/q_enqueue.c \
	utils/get_next_line/get_next_line_utils.c \
	utils/get_next_line/get_next_line.c \
	utils/queue_c/q_init.c 

MainFiles = \
	_cub3d/events/door_event.c \
	_cub3d/events/exit_cube3d.c \
	_cub3d/events/mouse_event.c \
	_cub3d/events/on_key_up.c \
	_cub3d/events/mouse_move.c \
	_cub3d/events/on_key_down.c \
	_cub3d/events/perform_events.c \
	_cub3d/utils/color.c \
	_cub3d/utils/frames.c \
	_cub3d/init/check_args.c \
	_cub3d/init/get_prog.c \
	_cub3d/init/init_mlx.c \
	_cub3d/mini_map/mini_map.c \
	_cub3d/ray_casting/ray_casting.c \
	_cub3d/setup/check_map.c \
	_cub3d/setup/init_player.c \
	_cub3d/setup/load_map.c \
	_cub3d/setup/load_sprites.c \
	_cub3d/setup/load_static.c \
	_cub3d/setup/load_texture.c \
	_cub3d/setup/load_types.c \
	_cub3d/setup/map_utils.c \
	_cub3d/setup/read_file.c \
	_cub3d/setup/setup.c \
	_cub3d/sprite/bullet.c \
	_cub3d/sprite/enemy_e.c \
	_cub3d/sprite/enemy_m.c \
	_cub3d/sprite/sort_sprite.c \
	_cub3d/sprite/sprite_move.c \
	_cub3d/sprite/sprite_tex.c \
	_cub3d/sprite/sprite.c \
	_cub3d/render/ft_put_pixel.c \
	_cub3d/render/replace_image.c \
	_cub3d/start/floor.c \
	_cub3d/start/other.c \
	_cub3d/start/game.c \
	_cub3d/start/player.c \
	_cub3d/start/start_game.c \

FILES = \
	$(UTIL_FILES) \
	$(MainFiles) \
	main.c

# -I /Users/aben-ham/goinfre/brew/opt/glfw/include/GLFW -L /Users/aben-ham/goinfre/brew/opt/glfw/lib
#-Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror -g -I includes/
FLAGS = -framework opengl -framework Appkit

#CFLAGS = -g -I includes/ -I/usr/include -Imlx_linux
#FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -fsanitize=address

# -fsanitize=address
DEPFLAGS = -MMD -MF $(@:.o=.d)

NAME = cub3d
MLX_LIB_NAME = libmlx.dylib
MLX_DIR = minilibx

OBJ_DIR = _OUT/

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

deps = $(OBJ:.o=.d)

all : $(NAME)

$(MLX_LIB_NAME) :
	make -C $(MLX_DIR)
	mv $(MLX_DIR)/$(MLX_LIB_NAME) .

$(NAME) : $(OBJ) $(MLX_LIB_NAME)
	gcc $(MLX_LIB_NAME) $(OBJ) $(FLAGS) -o $(NAME)

$(OBJ) : $(OBJ_DIR)%.o : %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $(@:_OUT/%.o=%.c) $(DEPFLAGS) -o $@

-include $(deps)

clean :
	make -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(MLX_LIB_NAME)
	rm -f $(NAME)

re : fclean all
