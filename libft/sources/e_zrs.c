/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_zrs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 06:02:07 by shunt             #+#    #+#             */
/*   Updated: 2019/09/05 14:40:49 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	e_zrs(char **s, int a, int i)
{
	char	*t;
	char	*cl;
	int		k;

	if (a)
	{
		t = (char *)malloc(sizeof(char) * (a + i + 1));
		t[a + i] = '\0';
		k = -1;
		while ((*s)[++k])
			t[k] = (*s)[k];
		while (k < i + a)
			t[k++] = '0';
		cl = *s;
		*s = t;
		free(cl);
	}
	else
		(*s)[i - 1] = '\0';
}
