/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:16:00 by shunt             #+#    #+#             */
/*   Updated: 2019/08/20 04:41:36 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	chck_p(t_rd **read, va_list **ap)
{
	(*read)->mod_smb = 'p';
	(*read)->mod = ft_p(va_arg(**ap, unsigned long long));
}
