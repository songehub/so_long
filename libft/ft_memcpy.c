/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:11:38 by ccrecent          #+#    #+#             */
/*   Updated: 2022/09/24 17:52:11 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	char		*spr;

	i = 0;
	dest = (char *)dst;
	spr = (char *)src;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		dest[i] = spr[i];
		i++;
	}
	return (dst);
}
