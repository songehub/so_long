/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:02:35 by ccrecent          #+#    #+#             */
/*   Updated: 2022/11/02 14:03:12 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd(('-'), fd);
		ft_putchar_fd(('2'), fd);
		ft_putnbr_fd((147483648), fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd(('-'), fd);
		n = -n;
		ft_putnbr_fd((n), fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else
		ft_putchar_fd((n + 48), fd);
}
