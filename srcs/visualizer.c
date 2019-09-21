/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 04:39:47 by huller            #+#    #+#             */
/*   Updated: 2019/09/21 21:01:39 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		cycle_cmnd_a(t_stack **a, t_stack **b, t_sort **p)
{
	int		cnt;

	cnt = 0;
	while ((*a))
	{
		if (get_boolean(a, b, p)
			break ;
		else if (get_boolean_two(a, b, p))
		{
			cnt++;
			break ;
		}
		cnt++;
		if ((*a)->next)
			(*a) = (*a)->next;
		else if ((*b)->nb > (*a)->nb && !(*a)->next)
		{
			cnt = 0;
			break ;
		}
		else
			cnt = else_cmd(a);
	}
	return (cnt);
}

void	vizua_2(t_stack **a, t_stack **b, t_stack **tmp_a, t_stack **tmp_b)
{
	if ((*a) && (*a)->next)
		(*a) = (*a)->next;
	else if ((*a) && !(*a)->next)
		(*tmp_a) = (*a);
	if ((*b) && (*b)->next)
		(*b) = (*b)->next;
	else if ((*b) && !(*b)->next)
		(*tmp_b) = (*b);
	(*tmp_a) ? (*a) = NULL : 0;
	(*tmp_b) ? (*b) = NULL : 0;
}

void	vizualize_1(t_stack **a, t_stack **b, t_instr *instr)
{
	while ((*a) && (*a)->prev)
		(*a) = (*a)->prev;
	while ((*b) && (*b)->prev)
		(*b) = (*b)->prev;
	ft_printf("\n");
	ft_printf(MAG"- - - - - - - - - - - - - -\n"RESET);
	ft_printf(RED"SIZE: %d"RESET, instr->size_a);
	ft_printf(YEL"%18s %d\n\n"RESET, "SIZE:", instr->size_b);
}

void	vizualize_init(t_stack **a, t_stack **b, t_instr *instr)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;

	tmp_a = NULL;
	tmp_b = NULL;
	ft_printf(CYN"\n      INITIALIZATION\n"RESET);
	ft_printf(RED"STACK A:"RESET);
	ft_printf(YEL"%23s", "STACK B:" RESET);
	ft_printf(MAG"\n- - - - - - - - - - - - - -"RESET);
	while ((*a) || (*b))
	{
		(*a) ? ft_printf(RED"\n %11d "RESET, (*a)->nb) :
		ft_printf("\n             ");
		ft_printf(MAG "| " RESET);
		(*b) ? ft_printf(YEL" %11d"RESET, (*b)->nb) : ft_printf(" ");
		vizua_2(a, b, &tmp_a, &tmp_b);
	}
	!(*a) ? (*a) = tmp_a : 0;
	!(*b) ? (*b) = tmp_b : 0;
	vizualize_1(a, b, instr);
}

void	vizualize_check(t_stack **a, t_stack **b, t_instr *instr)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;

	tmp_a = NULL;
	tmp_b = NULL;
	ft_printf(RED"\nSTACK A:"RESET);
	ft_printf(YEL"%23s", "STACK B:" RESET);
	ft_printf(MAG"\n- - - - - - - - - - - - - -"RESET);
	while ((*a) || (*b))
	{
		(*a) ? ft_printf(RED"\n %11d "RESET, (*a)->nb) :
			ft_printf("\n             ");
		ft_printf(MAG "| " RESET);
		(*b) ? ft_printf(YEL" %11d"RESET, (*b)->nb) : ft_printf(" ");
		vizua_2(a, b, &tmp_a, &tmp_b);
	}
	!(*a) ? (*a) = tmp_a : 0;
	!(*b) ? (*b) = tmp_b : 0;
	vizualize_1(a, b, instr);
}
