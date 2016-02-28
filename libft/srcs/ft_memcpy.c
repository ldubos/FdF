/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:48:13 by ldubos            #+#    #+#             */
/*   Updated: 2015/11/30 10:11:15 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	void			*ret;

	ret = dest;
	while (n--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (ret);
}
