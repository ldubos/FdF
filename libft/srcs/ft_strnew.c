/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:05:38 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/08 21:03:52 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char				*ft_strnew(size_t size)
{
	char			*ret;

	++size;
	ret = (char *)malloc(sizeof(char) * (size));
	if (!ret)
		return (NULL);
	while (size--)
		ret[size] = '\0';
	return (ret);
}
