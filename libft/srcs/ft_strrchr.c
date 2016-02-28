/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:05:53 by ldubos            #+#    #+#             */
/*   Updated: 2015/11/30 14:07:09 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *s, int c)
{
	size_t			i;

	i = ft_strlen(s) + 1;
	while (i--)
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
	return ((char *)NULL);
}
