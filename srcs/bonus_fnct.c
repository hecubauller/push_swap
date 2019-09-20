/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_fnct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:00:23 by huller            #+#    #+#             */
/*   Updated: 2019/09/20 19:53:18 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ra(t_stack **x, t_instr *instr)
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

void	rr(t_stack **a, t_stack **b, t_instr *instr)
{
	t_stack		*tmp_s;

	instr->inst = 0;
	tmp_s = NULL;
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
		rr_two(b, tmp_s);
	instr->push_swap ? ft_putstr("rr\n") : 0;
}

void	rr_two(t_stack **b, t_stack *tmp_s)
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

void	rrr_two(t_stack **b, t_stack *tmp_s, t_stack *tmp_s2)
{
	tmp_s = (*b);
	while ((*b)->next)
		(*b) = (*b)->next;
	(*b)->next = tmp_s;
	(*b)->prev->next = NULL;
	(*b)->prev = NULL;
	tmp_s2 = (*b);
	tmp_s->prev = tmp_s2;
	while ((*b) && (*b)->prev)
		(*b) = (*b)->prev;
}

void	free_lsts(t_stack **a)
{
	t_stack *tmp;

	tmp = NULL;
	turn_begin(a);
	while ((*a) && ((*a)->next))
	{
		tmp = *a;
		if ((*a)->next)
			(*a) = (*a)->next;
		tmp ? free(tmp) : 0;
	}
	(*a) ? free(*a) : 0;
}
