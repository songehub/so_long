/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:47:49 by ccrecent          #+#    #+#             */
/*   Updated: 2022/11/12 15:59:54 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*actual;
	t_list	*siguiente;

	if (*lst != NULL && lst != NULL)
	{
		actual = *lst;
		while (actual->next != NULL)
		{
			siguiente = actual->next;
			ft_lstdelone(actual, del);
			actual = siguiente;
		}
		ft_lstdelone(actual, del);
		*lst = NULL;
	}
}
