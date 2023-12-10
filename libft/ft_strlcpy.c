/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:48:12 by ccrecent          #+#    #+#             */
/*   Updated: 2023/12/02 14:46:35 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	char	*org;

	org = (char *) src;
	i = 0;
	src_len = ft_strlen(src);
	if (size != 0)
	{
		while (i < (size - 1) && org[i] != '\0')
		{
			dst[i] = org[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
