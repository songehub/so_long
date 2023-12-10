/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:47:05 by ccrecent          #+#    #+#             */
/*   Updated: 2022/10/07 16:31:07 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	str_len;
	size_t	max_len;

	str_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (len > str_len)
		max_len = str_len;
	else
		max_len = len;
	ptr = (char *)malloc(sizeof(char) * (max_len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (start < str_len && i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
