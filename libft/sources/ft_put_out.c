/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 01:31:37 by shunt             #+#    #+#             */
/*   Updated: 2019/08/20 04:41:36 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_out(t_rd **read, t_out **output)
{
	unsigned long	strlen;
	char			*tmp;

	if ((*read)->mod)
	{
		strlen = ft_strlen((*read)->mod) + (*read)->zero;
		tmp = (*output)->buf;
		(*output)->buf = ft_bufjoin((*output)->buf, (*read)->mod,
									(*output)->cnt, strlen);
		(*output)->cnt += strlen;
		free((void *)tmp);
	}
	return (SUCCESS);
}
