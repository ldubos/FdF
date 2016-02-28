/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:12:31 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/09 11:16:48 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int					ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (ft_strncmp(s1, s2, n))
		return (0);
	else
		return (1);
}
