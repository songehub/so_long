/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   107_flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:46:17 by ccrecent          #+#    #+#             */
/*   Updated: 2023/12/02 15:10:33 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**ft_copy_map(t_structure *e)
{
	int		i;
	char	**matrix_copy;

	i = 0;
	matrix_copy = ft_calloc((e->num_lines + 1), sizeof(char *));
	while (i < e->num_lines)
	{
		matrix_copy[i] = ft_strdup(e->matrix[i]);
		i++;
	}
	return (matrix_copy);
}

int	ft_check_flood_fill(t_structure *e, char **matrix_copy)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (j < e->num_lines)
	{
		i = 0;
		while (i < e->len_line)
		{
			if (matrix_copy[j][i] != '1' && matrix_copy[j][i] != '9')
				return (4);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_flood_fill(char **matrix_copy, int j, int i)
{
	matrix_copy[j][i] = '9';
	if (matrix_copy[j + 1][i] != '1' && matrix_copy[j + 1][i] != '9')
		ft_flood_fill(matrix_copy, j + 1, i);
	if (matrix_copy[j - 1][i] != '1' && matrix_copy[j - 1][i] != '9')
		ft_flood_fill(matrix_copy, j - 1, i);
	if (matrix_copy[j][i + 1] != '1' && matrix_copy[j][i + 1] != '9')
		ft_flood_fill(matrix_copy, j, i + 1);
	if (matrix_copy[j][i - 1] != '1' && matrix_copy[j][i - 1] != '9')
		ft_flood_fill(matrix_copy, j, i - 1);
	return (0);
}

int	ft_pre_flood_fill(t_structure *e)
{
	char	**matrix_copy;

	matrix_copy = ft_copy_map(e);
	e->collec = malloc(e->collections * sizeof (e->collec));
	if (!e->collec)
		return (0);
	ft_start_maps(e);
	free(e->map);
	e->map = NULL;
	e->error = ft_flood_fill(matrix_copy, e->player.y, e->player.x);
	e->error = ft_check_flood_fill(e, matrix_copy);
	ft_free(matrix_copy);
	matrix_copy = NULL;
	return (e->error);
}
