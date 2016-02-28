/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:44:33 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/08 21:05:46 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				*ft_strmap(const char *s, char (*f)(char))
{
	size_t			i;
	char			*ret;

	i = 0;
	ret = ft_strnew(ft_strlen(s));
	if (!ret)
		return (NULL);
	while (s[i])
	{
		ret[i] = f(s[i]);
		++i;
	}
	return (ret);
}
