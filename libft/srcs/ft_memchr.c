/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:42:03 by ldubos            #+#    #+#             */
/*   Updated: 2015/11/30 10:20:46 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
		if (*(unsigned char *)s != (unsigned char)c)
			++s;
		else
			return ((void *)s);
	return (NULL);
}
