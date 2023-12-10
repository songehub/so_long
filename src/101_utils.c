/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   101_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:13:37 by ccrecent          #+#    #+#             */
/*   Updated: 2023/12/02 15:08:54 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(char **matrix)
{
	int	n;

	n = 0;
	while (matrix[n])
	{
		free(matrix[n]);
		n++;
	}
	free(matrix);
}

void	ft_start_vars(t_structure *e)
{
	e->mlx = NULL;
	e->collec = NULL;
	e->windows.x = 1;
	e->windows.y = 1;
	e->player.x = 1;
	e->player.y = 1;
	e->exit.x = 1;
	e->exit.y = 1;
	e->error = 0;
	e->len_map = 0;
	e->num_lines = 0;
	e->len_line = 0;
	e->start_i = 0;
	e->start_j = 0;
	e->coll_n = 0;
	e->collected = 0;
	e->move_count = 0;
	e->img.moving = 0;
	e->map = NULL;
}

int	ft_if_ber(int len, char *name)
{
	if (name[len - 4] != '.')
		return (1);
	if (name[len - 3] != 'b')
		return (1);
	if (name[len - 2] != 'e')
		return (1);
	if (name[len - 1] != 'r')
		return (1);
	return (0);
}

int	ft_check_argv(int argc, char **argv, t_structure *e)
{
	int	len_argv;

	if (argc != 2)
		exit (ft_printf("Error arguments\n"));
	len_argv = strlen(argv[1]);
	if (len_argv <= 4)
		exit (ft_printf("Error map name\n"));
	e->error = ft_if_ber(len_argv, argv[1]);
	if (e->error == 1)
		exit (ft_printf("Error Incorrect map name\n"));
	return (0);
}
