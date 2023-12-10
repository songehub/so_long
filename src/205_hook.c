/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   205_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:24:09 by ccrecent          #+#    #+#             */
/*   Updated: 2023/11/19 15:24:09 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_up(t_structure *e)
{
	if (e->matrix[e->player.y - 1][e->player.x] == '1')
		return ;
	else if (e->matrix[e->player.y - 1][e->player.x] == 'C')
		ft_up_moving_c(e);
	else if (e->matrix[e->player.y - 1][e->player.x] == 'X')
		ft_up_moving_x(e);
	else if ((e->matrix[e->player.y - 1][e->player.x] == 'E')
			&& (e->collected >= e->coll_n))
		ft_up_moving_e(e);
	else
		ft_up_moving(e);
	e->move_count += 1;
	printf("Moving = %i\n", e->move_count);
	ft_print_moves(e);
}

void	ft_right(t_structure *e)
{
	if (e->matrix[e->player.y][e->player.x + 1] == '1')
		return ;
	else if (e->matrix[e->player.y][e->player.x + 1] == 'C')
		ft_right_moving_c(e);
	else if (e->matrix[e->player.y][e->player.x + 1] == 'X')
		ft_right_moving_x(e);
	else if ((e->matrix[e->player.y][e->player.x + 1] == 'E')
		&& (e->collected >= e->coll_n))
		ft_right_moving_e(e);
	else
		ft_right_moving(e);
	e->move_count += 1;
	printf("Moving = %i\n", e->move_count);
	ft_print_moves(e);
}

void	ft_down(t_structure *e)
{
	if (e->matrix[e->player.y + 1][e->player.x] == '1')
		return ;
	else if (e->matrix[e->player.y + 1][e->player.x] == 'C')
		ft_down_moving_c(e);
	else if (e->matrix[e->player.y + 1][e->player.x] == 'X')
		ft_down_moving_x(e);
	else if ((e->matrix[e->player.y + 1][e->player.x] == 'E')
		&& (e->collected >= e->coll_n))
		ft_down_moving_e(e);
	else
		ft_down_moving(e);
	e->move_count += 1;
	printf("Moving = %i\n", e->move_count);
	ft_print_moves(e);
}

void	ft_left(t_structure *e)
{
	if (e->matrix[e->player.y][e->player.x - 1] == '1')
		return ;
	else if (e->matrix[e->player.y][e->player.x - 1] == 'C')
		ft_left_moving_c(e);
	else if (e->matrix[e->player.y][e->player.x - 1] == 'X')
		ft_left_moving_x(e);
	else if ((e->matrix[e->player.y][e->player.x - 1] == 'E')
		&& (e->collected >= e->coll_n))
		ft_left_moving_e(e);
	else
		ft_left_moving(e);
	e->move_count += 1;
	printf("Moving = %i\n", e->move_count);
	ft_print_moves(e);
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_structure	*e;

	e = param;
	ft_timer(e);
	if (mlx_is_key_down(e->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(e->mlx);
	if (e->matrix[e->player.y][e->player.x] != 'Z')
	{
		if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
			ft_up(e);
		if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
			ft_down(e);
		if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
			ft_left(e);
		if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
			ft_right(e);
	}
}
