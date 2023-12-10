/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:01:54 by ccrecent          #+#    #+#             */
/*   Updated: 2023/08/19 13:01:54 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_open(t_structure *e, char **argv)
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		e->error = 91;
		ft_fin(e);
	}
	str = ft_get_next_line(fd);
	if (str == NULL)
	{
		e->error = 91;
		ft_fin(e);
	}
	while (str != NULL)
	{
		e->map = ft_strjoin_get(e->map, str);
		e->num_lines++;
		free(str);
		str = ft_get_next_line(fd);
	}
	close(fd);
}

int	ft_fin(t_structure *e)
{
	if (e->error == 91)
		ft_printf("Error in Open\n");
	if (e->error == 1)
		ft_printf("Error invalid characters\n");
	if (e->error == 2)
		ft_printf("Error the map is not a rectangle\n");
	if (e->error == 3)
		ft_printf("Error map is not surrounded by walls\n");
	if (e->error == 4)
		ft_printf("Error the map does not have a valid path\n");
	if (e->error == 5)
		ft_printf("Error the map does not have a player\n");
	if (e->error == 6)
		ft_printf("Error the map does not have any collectibles\n");
	if (e->error == 7)
		ft_printf("Error the map does not have an exit\n");
	if (e->error == 8)
		ft_printf("Error the map has no enemies\n");
	exit(EXIT_FAILURE);
}

void	ft_leaks(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_structure	e;

	atexit(ft_leaks);
	ft_start_vars(&e);
	ft_check_argv(argc, argv, &e);
	ft_open(&e, argv);
	e.error = ft_check_maps(&e);
	if (e.error != 0)
		return (ft_fin(&e));
	e.error = ft_pre_flood_fill(&e);
	if (e.error != 0)
		return (ft_fin(&e));
	ft_window(&e);
	free(e.collec);
	e.collec = NULL;
	ft_free(e.matrix);
	e.matrix = NULL;
	return (0);
}
