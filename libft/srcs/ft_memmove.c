/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:07:20 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/08 20:59:49 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	void			*tmp;

	i = n;
	tmp = (void *)malloc(n);
	while (i--)
		*((unsigned char *)tmp + i) = *((unsigned char *)src + i);
	i = n;
	while (i--)
		*((unsigned char *)dest + i) = *((unsigned char *)tmp + i);
	free(tmp);
	return (dest);
}
