/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:55:24 by huller            #+#    #+#             */
/*   Updated: 2019/09/20 20:07:14 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	apply_cmnds(t_stack **a, t_stack **b, t_instr *in, t_sort **p)
{
	turn_begin(a);
	turn_begin(b);
	while (((*p)->p_ra || (*p)->p_rr || (*p)->p_rb ||
			(*p)->p_rra || (*p)->p_rrr || (*p)->p_rrb))
	{
		if ((*p)->p_ra)
		{
			(*p)->p_ra--;
			ra(a, in);
		}
		if ((*p)->p_rra)
		{
			(*p)->p_rra--;
			rra(a, in);
		}
		if ((*p)->p_rr)
		{
			(*p)->p_rr--;
			rr(a, b, in);
		}
		apply_cmnds2(a, b, in, p);
	}
	pa(a, b, in);
}

void	apply_cmnds2(t_stack **a, t_stack **b, t_instr *in, t_sort **p)
{
	if ((*p)->p_rrb)
	{
		(*p)->p_rrb--;
		rrb(b, in);
	}
	if ((*p)->p_rb)
	{
		(*p)->p_rb--;
		rb(b, in);
	}
	if ((*p)->p_rrr)
	{
		(*p)->p_rrr--;
		rrr(a, b, in);
	}
}

t_stack	*turn_end(t_stack **x)
{
	while ((*x) && (*x)->next)
		(*x) = (*x)->next;
	return (*x);
}

t_stack	*turn_begin(t_stack **x)
{
	while ((*x) && (*x)->prev)
		(*x) = (*x)->prev;
	return (*x);
}

void	pb_two(t_stack **a, t_stack **b)
{
	t_stack		*tmp_s;

	tmp_s = NULL;
	(*b)->prev = (*a);
	tmp_s = (*a)->next;
	(*b)->prev->next = (*b);
	(*b) = (*b)->prev;
	(*a) = tmp_s;
	(*a) ? (*a)->prev = NULL : 0;
}
