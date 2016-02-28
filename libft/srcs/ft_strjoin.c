/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:29:54 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/08 21:09:03 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				*ft_strjoin(const char *s1, const char *s2)
{
	char			*ret;

	ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!ret)
		return (NULL);
	ft_strcat(ret, s1);
	ft_strcat(ret, s2);
	ret[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (ret);
}
