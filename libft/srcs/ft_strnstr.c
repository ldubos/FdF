/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:10:09 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/01 23:50:13 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	char			*j;
	char			*k;

	if (!*s2)
		return ((char *)s1);
	while (n-- && *s1)
	{
		if (*s1 == *s2)
		{
			i = n;
			j = (char *)s1 + 1;
			k = (char *)s2 + 1;
			while (i-- && *j && *k && *j == *k)
			{
				++j;
				++k;
			}
			if (!*k)
				return ((char *)s1);
		}
		++s1;
	}
	return (NULL);
}
