/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   301_up_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:56:18 by ccrecent          #+#    #+#             */
/*   Updated: 2023/12/02 15:44:24 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_up_moving(t_structure *e)
{
	e->player.y = (e->player.y - 1);
	if (e->flag == 1)
		mlx_image_to_window(e->mlx, e->img.p_up_2,
			e->player.x * PX, e->player.y * PX);
	if (e->flag == 0)
		mlx_image_to_window(e->mlx, e->img.p_up,
			e->player.x * PX, e->player.y * PX);
	mlx_image_to_window(e->mlx, e->img.empty,
		e->player.x * PX, (e->player.y + 1) * PX);
	if (e->matrix[e->player.y + 1][e->player.x] != 'E')
		e->matrix[e->player.y + 1][e->player.x] = '0';
}

void	ft_up_moving_c(t_structure *e)
{
	e->collected++;
	e->flag = 1;
	ft_up_moving(e);
	if (e->collected >= e->coll_n)
	{
		e->collected = e->coll_n;
		ft_e_draw(e);
	}
}

void	ft_up_moving_e(t_structure *e)
{
	ft_up_moving(e);
	printf("congratulation\n Game Over\n");
	mlx_close_window(e->mlx);
}

void	ft_up_moving_x(t_structure *e)
{
	ft_up_moving(e);
	printf("fatality\n Game Over\n");
	mlx_close_window(e->mlx);
}
