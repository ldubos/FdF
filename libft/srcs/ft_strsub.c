/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:16:16 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/09 11:36:02 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char				*ft_strsub(const char *s, unsigned int start, size_t n)
{
	char			*ret;
	size_t			i;

	ret = ft_strnew(n);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < n)
		ret[i++] = s[start++];
	return (ret);
}
