/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   103_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:15:55 by ccrecent          #+#    #+#             */
/*   Updated: 2023/10/08 12:15:55 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_clear_maps(t_structure *e)
{
	char	*str;

	str = ft_calloc (2, sizeof(char));
	if (str == NULL)
		return ;
	str[0] = '\n';
	e->map = ft_strjoin_get(e->map, str);
	free(str);
}

int	ft_equal_lines(t_structure *e)
{
	int	i;
	int	p;
	int	n;

	n = 0;
	p = 0;
	i = 0;
	while (e->map[n] != '\n')
		n++;
	while (e->map[i] != '\0')
	{
		while (e->map[i] != '\n')
		{
			p++;
			i++;
		}
		if (p != n)
			return (2);
		p = 0;
		i++;
	}
	return (0);
}

int	ft_wall_first(t_structure *e)
{
	int	i;

	i = 0;
	e->len_line = ft_strlen_get(e->matrix[0]);
	while (i < e->num_lines)
	{
		if (e->matrix[i][0] != '1')
			return (3);
		i++;
	}
	i = 0;
	while (i < e->num_lines)
	{
		if (e->matrix[i][e->len_line - 1] != '1')
			return (3);
		i++;
	}
	return (e->error);
}

int	ft_wall(t_structure *e)
{
	int	i;

	i = 0;
	while (e->matrix[0][i] != '\0')
	{
		if (e->matrix[0][i] != '1')
			return (3);
		i++;
	}
	i = 0;
	while (e->matrix[e->num_lines - 1][i] != '\0')
	{
		if (e->matrix[e->num_lines - 1][i] != '1')
			return (3);
		i++;
	}
	e->error = ft_wall_first(e);
	return (e->error);
}

int	ft_check_maps(t_structure *e)
{
	e->len_map = ft_strlen_get(e->map);
	ft_clear_maps(e);
	e->error = ft_char_valid(e);
	if (e->error != 0)
		return (e->error);
	e->error = ft_equal_lines(e);
	if (e->error != 0)
		return (e->error);
	e->matrix = ft_split(e->map, '\n');
	e->error = ft_wall(e);
	return (e->error);
}
