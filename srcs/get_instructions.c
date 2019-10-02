/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 01:03:23 by huller            #+#    #+#             */
/*   Updated: 2019/09/25 09:46:25 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		ret_fr(char *res_nb, char *cmp_str)
{
	free(res_nb);
	free(cmp_str);
	return (ERROR);
}

void	cycles_int(char *tmp, int *i, char *cmp_str, int neg)
{
	int	k;

	k = -1;
	if (neg)
	{
		cmp_str[++k] = '-';
		(*i)++;
	}
	while (tmp[(*i)] == '0')
		(*i)++;
	while (tmp[(*i)] >= '0' && tmp[(*i)] <= '9')
	{
		cmp_str[++k] = tmp[(*i)];
		(*i)++;
	}
	cmp_str[++k] = '\0';
}

void	sign_nb(char *tmp, int i, int *neg, int *pos)
{
	if (tmp[i] == '+')
		(*pos) = 1;
	else if (tmp[i] == '-')
		(*neg) = 1;
}
