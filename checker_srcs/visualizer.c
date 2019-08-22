/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 04:35:18 by huller            #+#    #+#             */
/*   Updated: 2019/08/22 06:18:24 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_includes/checker.h"

void	ft_vizualize_check(t_stack **a, t_stack **b, t_instr *instr)
{
	ft_printf(CLR RED"STACK A:\n"RESET);
	if ((*a))
	{
		while ((*a) && (*a)->next)
		{
			ft_printf(CLR RED"\n%d"RESET, (*a)->nb);
			(*a) = (*a)->next;
		}
		ft_printf(CLR RED"\n%d"RESET, (*a)->nb);
		while ((*a) && (*a)->prev)
			(*a) = (*a)->prev;
		ft_printf("\n");
	}
	ft_printf(CLR YEL"\nSTACK B:\n"RESET);
	if ((*b))
	{
		while ((*b) && (*b)->next)
		{
			ft_printf(CLR YEL"\n%d"RESET, (*b)->nb);
			(*b) = (*b)->next;
		}
		ft_printf(CLR YEL"\n%d"RESET, (*b)->nb);
		while ((*b) && (*b)->prev)
			(*b) = (*b)->prev;
		ft_printf("\n");
	}
}