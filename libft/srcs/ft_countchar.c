/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 07:03:10 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/15 07:06:43 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t				ft_countchar(const char *str, const char c)
{
	size_t			i;
	size_t			ret;

	i = 0;
	ret = 0;
	while (str[i])
		if (str[i++] == c)
			++ret;
	return (ret);
}
