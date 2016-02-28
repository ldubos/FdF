/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:25:22 by ldubos            #+#    #+#             */
/*   Updated: 2015/11/26 12:40:43 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strcat(char *dest, const char *src)
{
	unsigned int	index_d;
	unsigned int	index_s;

	index_d = ft_strlen(dest);
	index_s = 0;
	while (src[index_s] != '\0')
	{
		dest[index_d] = src[index_s];
		++index_d;
		++index_s;
	}
	dest[index_d] = '\0';
	return (dest);
}
