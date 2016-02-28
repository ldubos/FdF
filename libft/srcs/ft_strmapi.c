/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:57:17 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/08 21:06:43 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t			i;
	char			*ret;

	i = 0;
	ret = ft_strnew(ft_strlen(s));
	if (!ret)
		return (NULL);
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		++i;
	}
	return (ret);
}
