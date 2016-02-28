/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:05:43 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/09 14:45:43 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] && ft_isspace(s[i]))
		++i;
	while (j && ft_isspace(s[j]))
		--j;
	if (j < i)
		return (ft_strnew(0));
	return (ft_strsub(s, i, j - i + 1));
}
