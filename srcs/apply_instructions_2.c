/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instructions_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 06:28:58 by huller            #+#    #+#             */
/*   Updated: 2019/09/17 20:52:26 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rra(t_stack **x, t_instr *instr)
{
	int 		tmp;
	t_stack		*tmp_s;
	t_stack		*tmp_s2;

	tmp = 0;
	instr->inst = 0;
	if ((*x) && (*x)->next)
	{
		tmp_s = (*x);
		while ((*x)->next)
			(*x) = (*x)->next;
		(*x)->next = tmp_s;
		(*x)->prev->next = NULL;
		(*x)->prev = NULL;
		tmp_s2 = (*x);
		tmp_s->prev = tmp_s2;
		tmp_s2->next = tmp_s;
		while ((*x)->prev)
			(*x) = (*x)->prev;
	}
	instr->push_swap ? ft_putstr("rra\n") : 0;
}

void	rrb(t_stack **x, t_instr *instr)
{
	int 		tmp;
	t_stack		*tmp_s;
	t_stack		*tmp_s2;

	tmp = 0;
	instr->inst = 0;
	if ((*x) && (*x)->next)
	{
		tmp_s = (*x);
		while ((*x)->next)
			(*x) = (*x)->next;
		(*x)->next = tmp_s;
		(*x)->prev->next = NULL;
		(*x)->prev = NULL;
		tmp_s2 = (*x);
		tmp_s->prev = tmp_s2;
		tmp_s2->next = tmp_s;
		while ((*x)->prev)
			(*x) = (*x)->prev;
	}
	instr->push_swap ? ft_putstr("rrb\n") : 0;
}

void	rrr(t_stack **a, t_stack **b, t_instr *instr)
{
	int 		tmp;
	t_stack		*tmp_s;
	t_stack		*tmp_s2;

	tmp = 0;
	instr->inst = 0;
	if ((*a) && (*a)->next)
	{
		tmp_s = (*a);
		while ((*a)->next)
			(*a) = (*a)->next;
		(*a)->next = tmp_s;
		(*a)->prev->next = NULL;
		(*a)->prev = NULL;
		tmp_s2 = (*a);
		tmp_s->prev = tmp_s2;
		while ((*a) && (*a)->prev)
			(*a) = (*a)->prev;
	}
	if ((*b) && (*b)->next)
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
	instr->push_swap ? ft_putstr("rrr\n") : 0;

}

void	pa(t_stack **a, t_stack **b, t_instr *instr)
{
	t_stack		*tmp_s;

	instr->inst = 0;
	if (*b)
	{
		if (!(*a) && (*b))
		{
			tmp_s = (*b);
			(*b) = (*b)->next;
			(*b) ? (*b)->prev = NULL : 0;
			(*a) = tmp_s;
			(*a)->next = NULL;
			(*a)->next = NULL;

		}
		else if (*a)
		{
			(*a)->prev = (*b);
			tmp_s = (*b)->next;
			(*a)->prev->next = (*a);
			(*a) = (*a)->prev;
			(*b) = tmp_s;
			(*b) ? (*b)->prev = NULL : 0;
		}
		instr->size_a++;
		instr->size_b--;
		while ((*a) && (*a)->prev)
			(*a) = (*a)->prev;
		while ((*b) && (*b)->prev)
			(*b) = (*b)->prev;
	}
	instr->push_swap ? ft_putstr("pa\n") : 0;

}

void	pb(t_stack **a, t_stack **b, t_instr *instr)
{
	t_stack		*tmp_s;

	instr->inst = 0;
	if (*a)
	{
		if (!(*b))
		{
			tmp_s = (*a);
			(*a) = (*a)->next;
			(*a)->prev = NULL;
			(*b) = tmp_s;
			(*b)->next = NULL;
			(*b)->next = NULL;

		}
		else if (*b)
		{
			(*b)->prev = (*a);
			tmp_s = (*a)->next;
			(*b)->prev->next = (*b);
			(*b) = (*b)->prev;
			(*a) = tmp_s;
			(*a) ? (*a)->prev = NULL : 0;
		}
		instr->size_b++;
		instr->size_a--;
		while ((*a) && (*a)->prev)
			(*a) = (*a)->prev;
		while ((*b) && (*b)->prev)
			(*b) = (*b)->prev;
	}
	instr->push_swap ? ft_putstr("pb\n") : 0;
}