/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   307_left_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:46:11 by ccrecent          #+#    #+#             */
/*   Updated: 2023/12/02 15:37:18 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_left_moving(t_structure *e)
{
	e->player.x = (e->player.x - 1);
	if (e->flag == 1)
		mlx_image_to_window(e->mlx, e->img.p_left_2,
			e->player.x * PX, e->player.y * PX);
	if (e->flag == 0)
		mlx_image_to_window(e->mlx, e->img.p_left,
			e->player.x * PX, e->player.y * PX);
	mlx_image_to_window(e->mlx, e->img.empty,
		(e->player.x + 1) * PX, e->player.y * PX);
	if (e->matrix[e->player.y][e->player.x + 1] != 'E')
		e->matrix[e->player.y][e->player.x + 1] = '0';
}

void	ft_left_moving_c(t_structure *e)
{
	e->collected++;
	e->flag = 1;
	ft_left_moving(e);
	if (e->collected >= e->coll_n)
	{
		e->collected = e->coll_n;
		ft_e_draw(e);
	}
}

void	ft_left_moving_e(t_structure *e)
{
	ft_left_moving(e);
	printf("congratulation\n Game Over\n");
	mlx_close_window(e->mlx);
}

void	ft_left_moving_x(t_structure *e)
{
	ft_left_moving(e);
	printf("fatality\n Game Over\n");
	mlx_close_window(e->mlx);
}
