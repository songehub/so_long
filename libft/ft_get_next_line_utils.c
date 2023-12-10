/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:25:36 by ccrecent          #+#    #+#             */
/*   Updated: 2023/12/02 15:51:00 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_get(char *str_len)
{
	int	len;

	len = 0;
	if (!str_len)
		return (0);
	while (str_len[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr_start_get(char *str_start)
{
	char	*ptr_start;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (!str_start)
		return (NULL);
	while (str_start[len] != '\n' && str_start[len] != '\0')
		len++;
	if (str_start[len] == '\n')
		len++;
	ptr_start = ft_calloc_get(len + 1, sizeof(*ptr_start));
	if (!ptr_start)
		return (NULL);
	while (i < len)
	{
		ptr_start[i] = str_start[i];
		i++;
	}
	if (i == 0)
		return (free(ptr_start), NULL);
	return (ptr_start);
}

char	*ft_substr_end_get(char *str_end)
{
	char	*ptr_end;
	int		pos;
	int		len;
	int		i;

	i = 0;
	pos = 0;
	if (!str_end)
		return (NULL);
	while (str_end[pos] != '\n' && str_end[pos])
		pos++;
	if (str_end[pos] == '\n')
		pos += 1;
	len = ft_strlen_get(str_end) - pos + 1;
	ptr_end = ft_calloc_get((len + 1), sizeof(*ptr_end));
	if (!ptr_end)
		return (NULL);
	while (i < len)
	{
		ptr_end[i] = str_end[pos];
		i++;
		pos++;
	}
	return (free(str_end), ptr_end);
}

char	*ft_strjoin_get(char *s1, char *s2)
{
	char	*str_join;
	int		i;
	int		j;

	j = -1;
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen_get(s1) + ft_strlen_get(s2);
	str_join = ft_calloc_get(i + 1, sizeof (*str_join));
	if (!str_join)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			str_join[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (s2[++j] != '\0')
		str_join[i++] = s2[j];
	return (str_join);
}
