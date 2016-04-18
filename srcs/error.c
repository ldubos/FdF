/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 13:32:13 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/20 18:17:53 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				arg_error(int argc)
{
	if (argc < 2)
	{
		ft_putendl_fd("\a\033[1;31;40mToo few arguments.\033[0m", 2);
		exit(1);
	}
}

void				open_error()
{
	ft_putendl_fd("\a\033[1;31;40mOpen file error.\033[0m", 2);
	exit(1);
}

int					gnl_error(int err)
{
	if (err < 0)
	{
		ft_putendl_fd("\a\033[1;31;40mRead file error.\033[0m", 2);
		exit(1);
	}
	return (err);
}

void				malloc_error()
{
	ft_putendl_fd("\a\033[1;31;40mMemory error.\033[0m", 2);
	exit(1);
}
