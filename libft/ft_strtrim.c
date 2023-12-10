/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:18:01 by ccrecent          #+#    #+#             */
/*   Updated: 2022/10/17 14:17:39 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	flag(char const *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*ptr;
	size_t	len;
	size_t	j;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	if (!s1)
		return (NULL);
	while (flag(set, s1[i]) && s1[i])
		i++;
	while (flag(set, s1[len - 1]) && (len - 1))
		len--;
	if (len < i)
		len = i;
	ptr = malloc(len - i + 1);
	if (!ptr)
		return (NULL);
	while (i < len)
		ptr[j++] = s1[i++];
	ptr[j] = '\0';
	return (ptr);
}
