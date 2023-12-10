/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:15:46 by ccrecent          #+#    #+#             */
/*   Updated: 2023/12/02 14:44:36 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 99999
#endif

int	ft_barra_n_get(char *str_n)
{
	int		i;

	i = 0;
	if (!str_n)
		return (0);
	while (str_n[i] != '\n' && str_n[i] != '\0')
		i++;
	if (str_n[i] == '\n')
		return (1);
	return (0);
}

char	*ft_calloc_get(int len, int size)
{
	int		i;
	char	*ptr;

	ptr = malloc(len * sizeof(size));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_read_get(char *static_read, int fd)
{
	char	*ptr_read;
	int		count;

	count = 1;
	ptr_read = ft_calloc_get((BUFFER_SIZE + 1), sizeof(*ptr_read));
	if (ptr_read == NULL)
		return (NULL);
	while (count > 0 && ft_barra_n_get(static_read) == 0)
	{
		count = read(fd, ptr_read, BUFFER_SIZE);
		if (count < 0)
			return (free(ptr_read), free(static_read), NULL);
		ptr_read[count] = '\0';
		static_read = ft_strjoin_get(static_read, ptr_read);
	}
	free(ptr_read);
	return (static_read);
}

char	*ft_get_next_line(int fd)
{
	char		*result;
	static char	*static_str;

	if (!static_str)
		static_str = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	static_str = ft_read_get(static_str, fd);
	result = ft_substr_start_get(static_str);
	if (!result)
	{
		free(static_str);
		static_str = NULL;
		return (NULL);
	}
	static_str = ft_substr_end_get(static_str);
	return (result);
}
