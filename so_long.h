/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:02:01 by ccrecent          #+#    #+#             */
/*   Updated: 2023/12/02 15:27:25 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft/libft.h"
# define PX 128
# define CLOCK 50000

typedef struct s_xy
{
	int	x;
	int	y;
}			t_xy;

typedef struct s_texture
{
	mlx_texture_t	*ball;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit;
	mlx_texture_t	*empty;
	mlx_texture_t	*pacman_right;
	mlx_texture_t	*pacman_left;
	mlx_texture_t	*pacman_down;
	mlx_texture_t	*pacman_up;
	mlx_texture_t	*p_right_2;
	mlx_texture_t	*p_left_2;
	mlx_texture_t	*p_down_2;
	mlx_texture_t	*p_up_2;
	mlx_texture_t	*enemy_blue;
	mlx_texture_t	*enemy_orange;
	mlx_texture_t	*enemy_red;
	mlx_texture_t	*enemy_pink;
}					t_texture;

typedef struct s_image
{
	mlx_image_t	*ball;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
	mlx_image_t	*empty;
	mlx_image_t	*p_right;
	mlx_image_t	*p_left;
	mlx_image_t	*p_down;
	mlx_image_t	*p_up;
	mlx_image_t	*p_right_2;
	mlx_image_t	*p_left_2;
	mlx_image_t	*p_down_2;
	mlx_image_t	*p_up_2;
	mlx_image_t	*enemy_blue;
	mlx_image_t	*enemy_orange;
	mlx_image_t	*enemy_red;
	mlx_image_t	*enemy_pink;
	mlx_image_t	*moving;
}				t_image;

typedef struct s_structure
{
	int			len_map;
	int			num_lines;
	int			len_line;
	int			error;
	int			collections;
	int			coll_n;
	int			collected;
	int			start_j;
	int			start_i;
	int			move_count;
	int			timer;
	int			flag;
	char		*map;
	char		**matrix;
	mlx_t		*mlx;
	t_texture	texture;
	t_image		img;
	t_xy		windows;
	t_xy		player;
	t_xy		exit;
	t_xy		enemy;
	t_xy		*collec;
}	t_structure;

int		ft_check_argv(int argc, char **argv, t_structure *e);
void	ft_open(t_structure *e, char **argv);
void	ft_free_man(char **matrix, int j);
void	ft_free(char **matrix);
void	ft_start_vars(t_structure *e);
int		ft_if_ber(int len, char *name);
int		ft_check_maps(t_structure *e);
void	ft_clear_maps(t_structure *e);
int		ft_equal_lines(t_structure *e);
int		ft_fin(t_structure *e);
int		ft_wall(t_structure *e);
int		ft_wall_first(t_structure *e);
int		ft_char_valid(t_structure *e);
int		ft_count_p(t_structure *e);
int		ft_count_c(t_structure *e);
int		ft_count_e(t_structure *e);
int		ft_count_x(t_structure *e);
void	ft_start_maps(t_structure *e);
void	ft_p_start(t_structure *e);
void	ft_x_start(t_structure *e);
void	ft_x_start(t_structure *e);
void	ft_c_start(t_structure *e);
char	**ft_copy_map(t_structure *e);
int		ft_pre_flood_fill(t_structure *e);
int		ft_flood_fill(char **matrix_copy, int j, int i);
int		ft_check_flood_fill(t_structure *e, char **matrix_copy);
int32_t	ft_window(t_structure *e);
void	ft_t_textureo_image(t_structure *e);
void	ft_load_texture(t_structure *e);
void	ft_delete(t_structure *e);
int32_t	ft_draw_map(t_structure *e);
int32_t	ft_p_draw(t_structure *e);
int32_t	ft_e_draw(t_structure *e);
int32_t	ft_x_draw(t_structure *e);
int32_t	ft_wall_draw(t_structure *e);
int32_t	ft_c_draw(t_structure *e);
void	ft_hook(mlx_key_data_t keydata, void *param);
void	ft_up(t_structure *e);
void	ft_down(t_structure *e);
void	ft_right(t_structure *e);
void	ft_left(t_structure *e);
void	ft_print_moves(t_structure *e);
void	ft_up_moving_c(t_structure *e);
void	ft_up_moving(t_structure *e);
void	ft_up_moving_e(t_structure *e);
void	ft_up_moving_x(t_structure *e);
void	ft_right_moving_c(t_structure *e);
void	ft_right_moving(t_structure *e);
void	ft_right_moving_e(t_structure *e);
void	ft_right_moving_x(t_structure *e);
void	ft_down_moving_c(t_structure *e);
void	ft_down_moving(t_structure *e);
void	ft_down_moving_e(t_structure *e);
void	ft_down_moving_x(t_structure *e);
void	ft_left_moving_c(t_structure *e);
void	ft_left_moving(t_structure *e);
void	ft_left_moving_e(t_structure *e);
void	ft_left_moving_x(t_structure *e);
void	ft_timer(t_structure *e);

#endif
