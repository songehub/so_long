/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   105_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:05:04 by ccrecent          #+#    #+#             */
/*   Updated: 2023/12/02 15:09:24 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_count_p(t_structure *e)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (e->map[i] != '\0')
	{
		if (e->map[i] == 'P')
			n++;
		i++;
	}
	if (n != 1)
		return (5);
	return (e->error);
}

int	ft_count_c(t_structure *e)
{
	int	i;

	e->collections = 0;
	i = 0;
	while (e->map[i] != '\0')
	{
		if (e->map[i] == 'C')
			e->collections++;
		i++;
	}
	if (e->collections < 1)
		return (6);
	return (e->error);
}

int	ft_count_e(t_structure *e)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (e->map[i] != '\0')
	{
		if (e->map[i] == 'E')
			n++;
		i++;
	}
	if (n != 1)
		return (7);
	return (e->error);
}

int	ft_count_x(t_structure *e)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (e->map[i] != '\0')
	{
		if (e->map[i] == 'X')
			n++;
		i++;
	}
	if (n != 1)
		return (8);
	return (e->error);
}

int	ft_char_valid(t_structure *e)
{
	int	i;

	i = 0;
	while (e->map[i] != '\0')
	{
		if (e->map[i] != '\n' && e->map[i] != '0'
			&& e->map[i] != '1' && e->map[i] != 'P'
			&& e->map[i] != 'X'
			&& e->map[i] != 'C' && e->map[i] != 'E')
			return (1);
		i++;
	}
	e->error = ft_count_p(e);
	e->error = ft_count_c(e);
	e->error = ft_count_e(e);
	return (e->error);
}
