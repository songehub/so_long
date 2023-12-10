/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:14:55 by ccrecent          #+#    #+#             */
/*   Updated: 2022/10/07 15:20:57 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*str;

	dest = (unsigned char *)dst;
	str = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		i = len;
		while (i)
		{
			dest[i - 1] = str[i - 1];
			i--;
		}
	}
	return (dst);
}
