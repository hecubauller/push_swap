/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 08:04:09 by shunt             #+#    #+#             */
/*   Updated: 2019/09/16 00:14:12 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_z(char *s, int z)
{
	int		i;

	i = -1;
	while (s[++i] && s[i + 1] == '0')
		;
	while (s[++i])
	{
		i - z >= 0 ? s[i - z] = s[i] : 0;
		s[i] = '0';
	}
	return (s);
}
