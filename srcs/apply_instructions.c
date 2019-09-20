/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:52:42 by huller            #+#    #+#             */
/*   Updated: 2019/09/20 19:53:48 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rb(t_stack **x, t_instr *instr)
{
	t_stack		*tmp_s;

	instr->inst = 0;
	if ((*x) && (*x)->next)
	{
		tmp_s = (*x);
		(*x)->next->prev = NULL;
		while ((*x)->next)
			(*x) = (*x)->next;
		(*x)->next = tmp_s;
		(*x)->next->next = NULL;
		(*x)->next->prev = (*x);
		while ((*x) && (*x)->prev)
			(*x) = (*x)->prev;
		while ((*x) && (*x)->prev)
			(*x) = (*x)->prev;
	}
	instr->push_swap ? ft_putstr("rb\n") : 0;
}

void	ss(t_stack **a, t_stack **b, t_instr *instr)
{
	int		tmp;

	tmp = 0;
	instr->inst = 0;
	if (*a && *b && (*a)->next && (*b)->next)
	{
		if ((*a) && (*a)->next)
		{
			tmp = (*a)->nb;
			(*a)->nb = (*a)->next->nb;
			(*a)->next->nb = tmp;
		}
		if ((*b) && (*b)->next)
		{
			tmp = (*b)->nb;
			(*b)->nb = (*b)->next->nb;
			(*b)->next->nb = tmp;
		}
		while ((*a)->prev)
			(*a) = (*a)->prev;
		while ((*b) && (*b)->prev)
			(*b) = (*b)->prev;
	}
	instr->push_swap ? ft_putstr("ss\n") : 0;
}

void	sb(t_stack **x, t_instr *instr)
{
	t_stack		*tmp_s;
	t_stack		*tmp_s2;

	instr->inst = 0;
	if ((*x) && (*x)->next)
	{
		tmp_s = (*x);
		tmp_s2 = (*x)->next->next;
		(*x) = (*x)->next;
		(*x)->next = tmp_s;
		(*x)->prev = tmp_s->prev;
		tmp_s->prev = (*x);
		tmp_s->next = tmp_s2;
		tmp_s->next ? tmp_s->next->prev = tmp_s : 0;
	}
	while ((*x) && (*x)->prev)
		(*x) = (*x)->prev;
	instr->push_swap ? ft_putstr("sb\n") : 0;
}

void	sa(t_stack **x, t_instr *instr)
{
	t_stack		*tmp_s;
	t_stack		*tmp_s2;

	instr->inst = 0;
	if ((*x) && (*x)->next)
	{
		tmp_s = (*x);
		tmp_s2 = (*x)->next->next;
		(*x) = (*x)->next;
		(*x)->next = tmp_s;
		(*x)->prev = tmp_s->prev;
		tmp_s->prev = (*x);
		tmp_s->next = tmp_s2;
		tmp_s->next ? tmp_s->next->prev = tmp_s : 0;
	}
	while ((*x) && (*x)->prev)
		(*x) = (*x)->prev;
	instr->push_swap ? ft_putstr("sa\n") : 0;
}

void	appl_instr(t_instr *in, t_stack **a, t_stack **b)
{
	if (in->inst & SA)
		sa(a, in);
	else if (in->inst & SB)
		sb(b, in);
	else if (in->inst & SS)
		ss(a, b, in);
	else if (in->inst & RA)
		ra(a, in);
	else if (in->inst & RB)
		rb(b, in);
	else if (in->inst & RR)
		rr(a, b, in);
	else if (in->inst & RRA)
		rra(a, in);
	else if (in->inst & RRB)
		rrb(b, in);
	else if (in->inst & RRR)
		rrr(a, b, in);
	else if (in->inst & PA)
		pa(a, b, in);
	else if (in->inst & PB)
		pb(a, b, in);
	(*in).viz ? vizualize_check(a, b, in) : 0;
}
