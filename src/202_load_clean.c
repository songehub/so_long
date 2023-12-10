/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   202_load_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:06:59 by ccrecent          #+#    #+#             */
/*   Updated: 2023/12/02 15:42:00 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int32_t	ft_draw_map(t_structure *e)
{
	e->start_j = 0;
	while (e->start_j < e->num_lines)
	{
		e->start_i = 0;
		while (e->start_i < e->len_line)
		{
			if (mlx_image_to_window(e->mlx, e->img.empty,
					e->start_i * PX, e->start_j * PX) == -1)
			{
				mlx_close_window(e->mlx);
				return (EXIT_FAILURE);
			}
			ft_wall_draw(e);
			e->start_i++;
		}
		e->start_j++;
	}
	ft_c_draw(e);
	ft_x_draw(e);
	ft_p_draw(e);
	return (EXIT_SUCCESS);
}

void	ft_timer(t_structure *e)
{
	e->flag = 0;
	e->timer = 0;
	while (e->timer < CLOCK)
		e->timer++;
	if (e->timer == CLOCK)
		e->flag = 1;
	e->timer = 0;
	while (e->timer < CLOCK)
		e->timer++;
	e->flag = 0;
}

void	ft_print_moves(t_structure *e)
{
	char	*move;

	move = ft_itoa(e->move_count);
	if (!move)
		return ;
	mlx_delete_image(e->mlx, e->img.moving);
	e->img.moving = mlx_put_string(e->mlx, move, 10, 27);
	free (move);
}
