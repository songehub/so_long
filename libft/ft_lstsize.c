/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:52:12 by ccrecent          #+#    #+#             */
/*   Updated: 2022/11/10 15:06:32 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*actual;
	size_t	count;

	actual = lst;
	count = 0;
	while (actual != NULL)
	{
		actual = actual->next;
		count++;
	}
	return (count);
}
