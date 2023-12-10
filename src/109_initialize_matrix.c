/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   109_initialize_matrix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:28:25 by ccrecent          #+#    #+#             */
/*   Updated: 2023/12/02 15:17:22 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_p_start(t_structure *e)
{
	if (e->matrix[e->start_j][e->start_i] == 'P')
	{
		e->player.y = e->start_j;
		e->player.x = e->start_i;
	}
}

void	ft_e_start(t_structure *e)
{
	if (e->matrix[e->start_j][e->start_i] == 'E')
	{
		e->exit.y = e->start_j;
		e->exit.x = e->start_i;
	}
}

void	ft_x_start(t_structure *e)
{
	if (e->matrix[e->start_j][e->start_i] == 'X')
	{
		e->enemy.y = e->start_j;
		e->enemy.x = e->start_i;
	}
}

void	ft_c_start(t_structure *e)
{
	if (e->matrix[e->start_j][e->start_i] == 'C')
	{
		e->collec[e->coll_n].y = e->start_j;
		e->collec[e->coll_n].x = e->start_i;
		e->coll_n++;
	}
}

void	ft_start_maps(t_structure *e)
{
	e->start_j = 0;
	while (e->start_j < e->num_lines)
	{
		e->start_i = 0;
		while (e->start_i < e->len_line)
		{
			ft_p_start(e);
			ft_e_start(e);
			ft_x_start(e);
			ft_c_start(e);
			e->start_i++;
		}
		e->start_j++;
	}
}
