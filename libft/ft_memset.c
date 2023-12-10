/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:57:07 by ccrecent          #+#    #+#             */
/*   Updated: 2022/09/24 18:46:42 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*b, int c, size_t	len)
{
	unsigned char	*str;

	str = (unsigned char *) b;
	while (len > 0)
	{
		*str = c;
		str++;
		len--;
	}
	return (b);
}
