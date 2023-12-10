/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrecent <ccrecent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:03:49 by ccrecent          #+#    #+#             */
/*   Updated: 2022/09/26 11:45:21 by ccrecent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		result;
	char	*ch;
	char	cast;

	cast = (char) c;
	ch = (char *)s;
	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cast)
			result = i + 1;
		i++;
	}
	if (result)
		return (&(ch[result - 1]));
	else if (s[i] == cast)
		return (&(ch[i]));
	return (NULL);
}
