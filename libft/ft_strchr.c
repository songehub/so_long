/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:13:08 by ccrecent          #+#    #+#             */
/*   Updated: 2022/09/26 11:49:22 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ch;
	char	cast;

	cast = (char) c;
	ch = (char *)s;
	i = 0;
	while (s[i] != cast && s[i] != '\0')
		i++;
	if (s[i] == cast)
		return (&(ch[i]));
	return (NULL);
}
