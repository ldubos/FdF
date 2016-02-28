/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:09:17 by ldubos            #+#    #+#             */
/*   Updated: 2015/11/30 14:50:23 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char				*ft_strncpy(char *dest, const char *src, size_t n)
{
	char			*ret;
	size_t			i;

	ret = (char *)dest;
	i = n;
	while (*src && n--)
		*dest++ = *src++;
	if (n < i)
		ft_bzero(dest, n);
	return (ret);
}
