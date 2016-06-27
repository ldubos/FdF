/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 13:32:13 by ldubos            #+#    #+#             */
/*   Updated: 2016/04/26 09:02:52 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				square_error(t_conf *conf, int current)
{
	if (conf->m_width == -1)
	{
		conf->m_width = current;
	}
	else if (conf->m_width != -1 && conf->m_width != current)
	{
		ft_putendl_fd("\a\033[1;31;40mThis is not a square map.\033[0m", 2);
		exit(1);
	}
}