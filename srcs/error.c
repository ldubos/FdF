/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 13:32:13 by ldubos            #+#    #+#             */
/*   Updated: 2016/04/26 09:02:52 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				arg_error(int ac)
{
	if (ac < 2)
	{
		ft_putendl_fd("\a\033[1;31;40mToo few arguments.\033[0m", 2);
		exit(1);
	}
}

void				open_error(void)
{
	ft_putendl_fd("\a\033[1;31;40mOpen file error.\033[0m", 2);
	exit(1);
}

void				gnl_error(int err)
{
	if (err < 0)
	{
		ft_putendl_fd("\a\033[1;31;40mRead file error.\033[0m", 2);
		exit(1);
	}
}

void				malloc_error(void)
{
	ft_putendl_fd("\a\033[1;31;40mMemory error.\033[0m", 2);
	exit(1);
}
