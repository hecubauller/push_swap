/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 05:41:06 by huller            #+#    #+#             */
/*   Updated: 2019/08/29 09:05:01 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_rr(t_stack **a, t_stack **b, t_instr *instr)
{
	t_stack		*tmp_s;

	instr->inst = 0;
	if ((*a) && (*a)->next)
	{
		tmp_s = (*a);
		(*a)->next->prev = NULL;
		while ((*a)->next)
			(*a) = (*a)->next;
		(*a)->next = tmp_s;
		(*a)->next->next = NULL;
		(*a)->next->prev = (*a);
		while ((*a) && (*a)->prev)
			(*a) = (*a)->prev;
	}
	if ((*b) && (*b)->next)
	{
		tmp_s = (*b);
		(*b)->next->prev = NULL;
		while ((*b)->next)
			(*b) = (*b)->next;
		(*b)->next = tmp_s;
		(*b)->next->next = NULL;
		(*b)->next->prev = (*b);
		while ((*b) && (*b)->prev)
			(*b) = (*b)->prev;
	}
	instr->push_swap ? ft_putstr("rr\n") : 0;
}

void	ft_ra(t_stack **x, t_instr *instr)
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
	instr->push_swap ? ft_putstr("ra\n") : 0;
}

void	ft_rb(t_stack **x, t_instr *instr)
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

void	ft_ss(t_stack **a, t_stack **b, t_instr *instr)
{
	int 		tmp;

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

void	ft_sb(t_stack **x, t_instr *instr)
{
	int 		tmp;

	tmp = 0;
	instr->inst = 0;
	if ((*x) && (*x)->next)
	{
		tmp = (*x)->nb;
		(*x)->nb = (*x)->next->nb;
		(*x)->next->nb = tmp;
	}
	while ((*x) && (*x)->prev)
		(*x) = (*x)->prev;
	instr->push_swap ? ft_putstr("sb\n") : 0;
}

void	ft_sa(t_stack **x, t_instr *instr)
{
	t_stack		*tmp_s;
	t_stack		*tmp_s2;
	instr->inst = 0;
	if ((*x) && (*x)->next)
	{
		tmp_s = (*x);
		tmp_s2 = (*x)->next->prev; //FINISH SA & SB
		(*x) = (*x)->next;
		(*x)->prev = tmp_s->prev;
		tmp_s->prev = tmp_s2;
		(*x)->next = tmp_s;
	}
	while ((*x) && (*x)->prev)
		(*x) = (*x)->prev;
	instr->push_swap ? ft_putstr("sa\n") : 0;
}

void	ft_appl_instr(t_instr *in, t_stack **a, t_stack **b)
{
	if (in->inst & SA)
		ft_sa(a, in);
	else if (in->inst & SB)
		ft_sb(b, in);
	else if (in->inst & SS)
		ft_ss(a, b, in);
	else if (in->inst & RA)
		ft_ra(a, in);
	else if (in->inst & RB)
		ft_rb(b, in);
	else if (in->inst & RR)
		ft_rr(a, b, in);
	else if (in->inst & RRA)
		ft_rra(a, in);
	else if (in->inst & RRB)
		ft_rrb(b, in);
	else if (in->inst & RRR)
		ft_rrr(a, b, in);
	else if (in->inst & PA)
		ft_pa(a, b, in);
	else if (in->inst & PB)
		ft_pb(a, b, in);
	(*in).viz ? ft_vizualize_check(a, b, in) : 0;
}