/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:41:33 by ldubos            #+#    #+#             */
/*   Updated: 2015/11/26 12:51:13 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char				*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t			index_d;
	size_t			index_s;

	index_d = ft_strlen(dest);
	index_s = 0;
	while (index_s < n)
	{
		dest[index_d] = src[index_s];
		++index_d;
		++index_s;
	}
	dest[index_d] = '\0';
	return (dest);
}
