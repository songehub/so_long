/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   203_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:53:29 by ccrecent          #+#    #+#             */
/*   Updated: 2023/12/02 15:44:12 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int32_t	ft_wall_draw(t_structure *e)
{
	if (e->matrix[e->start_j][e->start_i] == '1')
	{
		if (mlx_image_to_window(e->mlx, e->img.wall,
				e->start_i * PX, e->start_j * PX) == -1)
		{
			mlx_close_window(e->mlx);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int32_t	ft_e_draw(t_structure *e)
{
	if (mlx_image_to_window(e->mlx, e->img.exit,
			e->exit.x * PX, e->exit.y * PX) == -1)
	{
		mlx_close_window(e->mlx);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int32_t	ft_x_draw(t_structure *e)
{
	if (mlx_image_to_window(e->mlx, e->img.enemy_blue,
			e->enemy.x * PX, e->enemy.y * PX) == -1)
	{
		mlx_close_window(e->mlx);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int32_t	ft_p_draw(t_structure *e)
{
	if (mlx_image_to_window(e->mlx, e->img.p_right,
			e->player.x * PX, e->player.y * PX) == -1)
	{
		mlx_close_window(e->mlx);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int32_t	ft_c_draw(t_structure *e)
{
	int	n;

	n = 0;
	while (n < e->coll_n)
	{
		if (mlx_image_to_window(e->mlx, e->img.ball,
				e->collec[n].x * PX, e->collec[n].y * PX) == -1)
		{
			mlx_close_window(e->mlx);
			return (EXIT_FAILURE);
		}
		n++;
	}
	return (EXIT_SUCCESS);
}
