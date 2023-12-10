/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:13:41 by ccrecent          #+#    #+#             */
/*   Updated: 2022/10/29 18:25:01 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int n, int base)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*ptr;

	len = ft_numlen(n, 10);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	ptr[len] = 0;
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
		ptr[0] = '-';
	while (n)
	{
		if (n > 0)
			ptr[--len] = ((n % 10) + 48);
		else
			ptr[--len] = (((n % 10) * -1) + 48);
		n /= 10;
	}
	return (ptr);
}
