/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:58:37 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/08 21:03:00 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				*ft_strdup(const char *s)
{
	size_t			i;
	char			*tmp_s;

	i = ft_strlen(s);
	tmp_s = ft_strnew(i);
	if (!tmp_s)
		return (NULL);
	tmp_s[i + 1] = '\0';
	while (i--)
		tmp_s[i] = s[i];
	return (tmp_s);
}
