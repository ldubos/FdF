/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:58:57 by ldubos            #+#    #+#             */
/*   Updated: 2015/12/08 20:56:07 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void				*ft_memalloc(size_t size)
{
	void			*ret;

	ret = malloc(size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
