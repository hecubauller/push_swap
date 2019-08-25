/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 04:39:47 by huller            #+#    #+#             */
/*   Updated: 2019/08/25 05:34:40 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_includes/checker.h"

void	ft_vizualize_check(t_stack **a, t_stack **b, t_instr *instr)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;

	tmp_a = NULL;
	tmp_b = NULL;
	ft_printf(CLR RED"STACK A:"RESET);
	ft_printf(CLR YEL"%13s", "STACK B:" RESET);
	ft_printf(MAG"\n- - - - - - - - -"RESET);
	while ((*a) || (*b))
	{
			(*a) ? ft_printf(CLR RED"\n%7d "RESET, (*a)->nb) : ft_printf(" ");
			ft_printf(MAG "| " RESET);
			(*b) ? ft_printf(CLR YEL"%d"RESET, (*b)->nb) : ft_printf(" ");
			(*a) = ((*a)->next) ? ((*a)->next) : (tmp_a = (*a));
			(*b) = ((*b)->next) ? ((*b)->next) : (tmp_b = (*b));
			tmp_a ? (*a) = NULL : 0;
			tmp_b ? (*b) = NULL : 0;


	}
	(*a) ? ft_printf(CLR RED"\n%7d "RESET, (*a)->nb) : 0;
	ft_printf(MAG "| " RESET);
	(*b) ? ft_printf(CLR YEL"%d\n"RESET, (*b)->nb) : 0;
	tmp_a ? (*a) = tmp_a : 0;
	tmp_b ? (*b) = tmp_b : 0;
	while ((*a) && (*a)->prev)
		(*a) = (*a)->prev;
	while ((*b) && (*b)->prev)
		(*b) = (*b)->prev;
	ft_printf("\n");
	ft_printf(MAG"- - - - - - - - -\n"RESET);
	ft_printf( RED"SIZE: %d"RESET, instr->size_a);
	ft_printf(YEL"%7s %d\n"RESET, "SIZE:", instr->size_b);
	ft_printf("\n");

	/*if ((*b))
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
	ft_printf(YEL"- - - - - - - - -\n"RESET);
	ft_printf(YEL"SIZE: %d\n"RESET, instr->size_b);*/
}