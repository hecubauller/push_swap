/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:55:14 by huller            #+#    #+#             */
/*   Updated: 2019/08/20 04:41:36 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	long	i;

	if (nb == 0)
		return (0);
	i = 1;
	while (i * i < (long)nb)
	{
		i++;
	}
	if ((nb % i) == 0)
		return ((int)i);
	else
		return (0);
}
