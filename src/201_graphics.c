/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   201_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:51:31 by ccrecent          #+#    #+#             */
/*   Updated: 2023/11/04 15:51:31 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_load_texture(t_structure *e)
{
	e->texture.ball = mlx_load_png("./textures/ball.png");
	e->texture.wall = mlx_load_png("./textures/wall.png");
	e->texture.exit = mlx_load_png("./textures/exit.png");
	e->texture.empty = mlx_load_png("./textures/empty.png");
	e->texture.pacman_right = mlx_load_png("./textures/pacman_right.png");
	e->texture.pacman_left = mlx_load_png("./textures/pacman_left.png");
	e->texture.pacman_down = mlx_load_png("./textures/pacman_down.png");
	e->texture.pacman_up = mlx_load_png("./textures/pacman_up.png");
	e->texture.p_right_2 = mlx_load_png("./textures/pacman_right_2.png");
	e->texture.p_left_2 = mlx_load_png("./textures/pacman_left_2.png");
	e->texture.p_down_2 = mlx_load_png("./textures/pacman_down_2.png");
	e->texture.p_up_2 = mlx_load_png("./textures/pacman_up_2.png");
	e->texture.enemy_blue = mlx_load_png("./textures/enemy_blue.png");
	e->texture.enemy_red = mlx_load_png("./textures/enemy_red.png");
	e->texture.enemy_orange = mlx_load_png("./textures/enemy_orange.png");
	e->texture.enemy_pink = mlx_load_png("./textures/enemy_pink.png");
}

void	ft_texture_to_image(t_structure *e)
{
	e->img.ball = mlx_texture_to_image(e->mlx, e->texture.ball);
	e->img.wall = mlx_texture_to_image(e->mlx, e->texture.wall);
	e->img.exit = mlx_texture_to_image(e->mlx, e->texture.exit);
	e->img.empty = mlx_texture_to_image(e->mlx, e->texture.empty);
	e->img.p_right = mlx_texture_to_image(e->mlx, e->texture.pacman_right);
	e->img.p_left = mlx_texture_to_image(e->mlx, e->texture.pacman_left);
	e->img.p_down = mlx_texture_to_image(e->mlx, e->texture.pacman_down);
	e->img.p_up = mlx_texture_to_image(e->mlx, e->texture.pacman_up);
	e->img.p_right_2 = mlx_texture_to_image(e->mlx, e->texture.p_right_2);
	e->img.p_left_2 = mlx_texture_to_image(e->mlx, e->texture.p_left_2);
	e->img.p_down_2 = mlx_texture_to_image(e->mlx, e->texture.p_down_2);
	e->img.p_up_2 = mlx_texture_to_image(e->mlx, e->texture.p_up_2);
	e->img.enemy_blue = mlx_texture_to_image(e->mlx, e->texture.enemy_blue);
	e->img.enemy_red = mlx_texture_to_image(e->mlx, e->texture.enemy_red);
	e->img.enemy_orange = mlx_texture_to_image(e->mlx, e->texture.enemy_orange);
	e->img.enemy_pink = mlx_texture_to_image(e->mlx, e->texture.enemy_pink);
}

void	ft_delete(t_structure *e)
{
	mlx_delete_texture(e->texture.ball);
	mlx_delete_texture(e->texture.wall);
	mlx_delete_texture(e->texture.exit);
	mlx_delete_texture(e->texture.empty);
	mlx_delete_texture(e->texture.pacman_right);
	mlx_delete_texture(e->texture.pacman_left);
	mlx_delete_texture(e->texture.pacman_down);
	mlx_delete_texture(e->texture.pacman_up);
	mlx_delete_texture(e->texture.p_right_2);
	mlx_delete_texture(e->texture.p_left_2);
	mlx_delete_texture(e->texture.p_down_2);
	mlx_delete_texture(e->texture.p_up_2);
	mlx_delete_texture(e->texture.enemy_blue);
	mlx_delete_texture(e->texture.enemy_red);
	mlx_delete_texture(e->texture.enemy_orange);
	mlx_delete_texture(e->texture.enemy_pink);
}

int32_t	ft_window(t_structure *e)
{
	e->mlx = mlx_init(e->len_line * PX, e->num_lines * PX, "Pac_Man", false);
	if (!e->mlx)
		return (EXIT_FAILURE);
	ft_load_texture(e);
	ft_texture_to_image(e);
	ft_draw_map(e);
	mlx_key_hook(e->mlx, &ft_hook, e);
	mlx_loop(e->mlx);
	ft_delete(e);
	mlx_terminate(e->mlx);
	return (EXIT_SUCCESS);
}
