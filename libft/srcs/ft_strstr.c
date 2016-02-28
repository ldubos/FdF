/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:10:09 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/02 00:39:56 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strstr(const char *s1, const char *s2)
{
	size_t			i;

	if (!ft_strlen(s2))
		return ((char *)s1);
	while (*s1 && *s2)
	{
		i = 0;
		while (*(s1 + i) == *(s2 + i) && *(s1 + i) && *(s2 + i))
		{
			++i;
			if (!*(s2 + i))
				return ((char *)s1);
		}
		++s1;
	}
	return (NULL);
}
