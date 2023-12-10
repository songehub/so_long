/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:31:53 by ccrecent          #+#    #+#             */
/*   Updated: 2023/12/02 14:45:05 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ultimo;

	ultimo = *lst;
	if (ultimo == NULL)
	{
		*lst = new;
	}
	else
	{
		while (ultimo->next != NULL)
			ultimo = ultimo->next;
		ultimo->next = new;
	}
}
