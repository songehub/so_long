/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:42:23 by ccrecent          #+#    #+#             */
/*   Updated: 2023/12/02 14:45:56 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int	*count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		*count = *count + 6;
	}
	else
	{
		while (str[i] != '\0')
		{
			ft_putchar(str[i], count);
			i++;
		}
	}
}

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putchar(('-'), count);
		ft_putchar(('2'), count);
		ft_putnbr(147483648, count);
	}
	else if (n < 0)
	{
		ft_putchar(('-'), count);
		n = -n;
		ft_putnbr((n), count);
	}
	else if (n > 9)
	{
		ft_putnbr((n / 10), count);
		ft_putnbr((n % 10), count);
	}
	else
		ft_putchar((n + 48), count);
}

void	ft_unsigned(unsigned long n, int *count)
{
	if (n > 9)
	{
		ft_putnbr((n / 10), count);
		ft_putnbr((n % 10), count);
	}
	else
		ft_putchar((n + 48), count);
}
