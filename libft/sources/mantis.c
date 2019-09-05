/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mantis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:26:21 by shunt             #+#    #+#             */
/*   Updated: 2019/09/05 14:40:49 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*mantis(t_flts l)
{
	char	*man;
	int		i;
	int		j;
	int		a;

	if (!(man = (char *)malloc(sizeof(char) * 65)))
		return (NULL);
	man[64] = '\0';
	j = 4;
	a = -1;
	while (--j > -1)
	{
		i = 0;
		while (i < 16)
		{
			man[++a] = (l.y[j] & (0x8000 >> i)) ? '1' : '0';
			i++;
		}
	}
	return (man);
}
