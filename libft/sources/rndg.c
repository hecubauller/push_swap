/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rndg.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 12:25:34 by shunt             #+#    #+#             */
/*   Updated: 2019/09/16 00:14:12 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rndg(char **s, int i)
{
	char	*t;
	int		l;

	if ((*s)[i] < '5' || ((*s)[i] == '5' && !((*s)[i - 1] % 2)))
		(*s)[i] = '\0';
	else if ((*s)[i] > '5' || ((*s)[i] == '5' && (*s)[i - 1] % 2))
	{
		(*s)[i] = '\0';
		l = ft_strlen(*s);
		t = (char *)malloc(sizeof(char) * (l + 1));
		ft_memset(t, '0', l);
		t[l] = '\0';
		t[l - 1] = '1';
		str_ad(s, t);
		free(t);
	}
}
