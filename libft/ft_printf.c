/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:22:25 by ccrecent          #+#    #+#             */
/*   Updated: 2023/01/28 13:24:40 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_type(va_list arg, char const *str, int i, int *count)
{
	if (str[i + 1] == '%')
		ft_putchar('%', count);
	if (str[i + 1] == 'c')
		ft_putchar(va_arg(arg, int), count);
	if (str[i + 1] == 's')
		ft_putstr(va_arg(arg, char *), count);
	if (str[i + 1] == 'p')
		ft_putptr(arg, count);
	if (str[i + 1] == 'i' || str[i + 1] == 'd')
		ft_putnbr(va_arg(arg, int), count);
	if (str[i + 1] == 'u')
		ft_unsigned(va_arg(arg, unsigned int), count);
	if (str[i + 1] == 'x')
		ft_putnbr_base_x(va_arg(arg, unsigned int), "0123456789abcdef", count);
	if (str[i + 1] == 'X')
		ft_putnbr_base_x(va_arg(arg, unsigned int), "0123456789ABCDEF", count);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start(arg, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_type(arg, str, i, &count);
			i++;
		}
		else
			ft_putchar(str[i], &count);
		i++;
	}
	va_end(arg);
	return (count);
}
