/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:16:00 by shunt             #+#    #+#             */
/*   Updated: 2019/09/17 20:52:26 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	chck_c(t_rd **read, va_list **ap)
{
	(*read)->mod_smb = 'c';
	(*read)->mod = ft_c(va_arg(**ap, int), 0, read);
}
