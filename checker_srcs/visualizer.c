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

void	ft_vizualize_init(t_stack **a, t_stack **b, t_instr *instr)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;

	tmp_a = NULL;
	tmp_b = NULL;
	ft_printf(CLR GRN"      INITIALIZATION\n"RESET);
	ft_printf(CLR RED"STACK A:"RESET);
	ft_printf(CLR YEL"%23s", "STACK B:" RESET);
	ft_printf(MAG"\n- - - - - - - - - - - - - -"RESET);
	while ((*a) || (*b))
	{
		(*a) ? ft_printf(CLR RED"\n %11d "RESET, (*a)->nb) :
			ft_printf("\n             ");
		ft_printf(MAG "| " RESET);
		(*b) ? ft_printf(CLR YEL" %11d"RESET, (*b)->nb) : ft_printf(" ");
		if (*a)
			(*a) = (*a)->next ? ((*a)->next) : (tmp_a = (*a));
		if (*b)
			(*b) = (*b)->next ? ((*b)->next) : (tmp_b = (*b));
		tmp_a ? (*a) = NULL : 0;
		tmp_b ? (*b) = NULL : 0;
	}
	!(*a) ? (*a) = tmp_a : 0;
	!(*b) ? (*b) = tmp_b : 0;
	while ((*a) && (*a)->prev)
		(*a) = (*a)->prev;
	while ((*b) && (*b)->prev)
		(*b) = (*b)->prev;
	ft_printf("\n");
	ft_printf(MAG"- - - - - - - - - - - - - -\n"RESET);
	ft_printf( RED"SIZE: %d"RESET, instr->size_a);
	ft_printf(YEL"%18s %d\n"RESET, "SIZE:", instr->size_b);
}

void	ft_vizualize_check(t_stack **a, t_stack **b, t_instr *instr)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;

	tmp_a = NULL;
	tmp_b = NULL;
	ft_printf(CLR RED"STACK A:"RESET);
	ft_printf(CLR YEL"%23s", "STACK B:" RESET);
	ft_printf(MAG"\n- - - - - - - - - - - - - -"RESET);
	while ((*a) || (*b))
	{
			(*a) ? ft_printf(CLR RED"\n %11d "RESET, (*a)->nb) :
				ft_printf("\n             ");
			ft_printf(MAG "| " RESET);
			(*b) ? ft_printf(CLR YEL" %11d"RESET, (*b)->nb) : ft_printf(" ");
			if (*a)
				(*a) = (*a)->next ? ((*a)->next) : (tmp_a = (*a));
			if (*b)
				(*b) = (*b)->next ? ((*b)->next) : (tmp_b = (*b));
			tmp_a ? (*a) = NULL : 0;
			tmp_b ? (*b) = NULL : 0;
	}
	!(*a) ? (*a) = tmp_a : 0;
	!(*b) ? (*b) = tmp_b : 0;
	while ((*a) && (*a)->prev)
		(*a) = (*a)->prev;
	while ((*b) && (*b)->prev)
		(*b) = (*b)->prev;
	ft_printf("\n");
	ft_printf(MAG"- - - - - - - - - - - - - -\n"RESET);
	ft_printf( RED"SIZE: %d"RESET, instr->size_a);
	ft_printf(YEL"%18s %d\n"RESET, "SIZE:", instr->size_b);
}