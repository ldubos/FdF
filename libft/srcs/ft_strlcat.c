/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:42:32 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/01 22:56:43 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t			i;
	size_t			ret;

	i = ft_strlen(dest);
	if (n < i)
		ret = n + ft_strlen(src);
	else
		ret = i + ft_strlen(src);
	while (*src && i + 1 < n)
	{
		*((char *)dest + i) = *src++;
		++i;
	}
	*((char *)dest + i) = '\0';
	return (ret);
}
