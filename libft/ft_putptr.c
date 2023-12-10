/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:39:59 by ccrecent          #+#    #+#             */
/*   Updated: 2023/01/27 19:49:31 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr(va_list arg, int *count)
{
	write(1, "0x", 2);
	*count = *count + 2;
	ft_putnbr_base_x(va_arg(arg, unsigned long long), "0123456789abcdef",
		count);
}

void	ft_putnbr_base_x(unsigned long n, char *base, int *count)
{
	if (n > 15)
	{
		ft_putnbr_base_x(n / 16, base, count);
		ft_putnbr_base_x(n % 16, base, count);
	}
	else
		ft_putchar((base[n]), count);
}
