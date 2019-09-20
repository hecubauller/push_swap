/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mexp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:28:39 by shunt             #+#    #+#             */
/*   Updated: 2019/09/20 00:59:20 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mexp(t_flts l)
{
	int	a;
	int	e;
	int	i;

	a = 14;
	e = -16383;
	i = 0;
	while (++i < 16)
	{
		e += (l.y[4] & (0x8000 >> i)) ? pw(2, a) : 0;
		a--;
	}
	return (e);
}
