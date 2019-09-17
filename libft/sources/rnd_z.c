/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 10:04:30 by shunt             #+#    #+#             */
/*   Updated: 2019/09/17 20:52:26 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rnd_z(char **s, int i, size_t a, unsigned short f)
{
	char	*r;

	i = -1;
	while ((*s)[++i] && (*s)[i] != '.')
		;
	if ((*s)[i + 1] && (*s)[i + 1] >= '5')
	{
		(*s)[i] = '\0';
		if (!(r = (char *)malloc(sizeof(char) * (i + 1))))
			return ;
		r[i] = '\0';
		r[i - 1] = '1';
		--i;
		while (--i >= 0)
			r[i] = '0';
		str_ad(s, r);
	}
	else
		(*s)[i] = '\0';
	if (!a && f & F_OCT)
	{
		(*s)[i] = '.';
		(*s)[i + 1] = '\0';
	}
}
