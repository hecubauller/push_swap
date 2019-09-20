/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 09:12:59 by huller            #+#    #+#             */
/*   Updated: 2019/09/20 00:59:20 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int 	alg_three(t_instr *in, t_stack **a)
{
	if ((*a)->nb < (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb &&
			(*a)->next->next->nb < (*a)->nb)
		rra(a, in);
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->next->nb > (*a)->next->nb
	&& (*a)->nb < (*a)->next->next->nb)
		sa(a, in);
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb)
	{
		sa(a, in);
		rra(a, in);
	}
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb < (*a)->next->next->nb)
		ra(a, in);
	else if ((*a)->nb < (*a)->next->nb && (*a)->next->next->nb < (*a)->next->nb)
	{
		sa(a, in);
		ra(a, in);
	}
	return (SUCCESS);
}

void	alg_two(t_instr *in, t_stack **a)
{
	if ((*a)->nb > (*a)->next->nb)
		sa(a, in);
}

int 	is_sorted(t_stack **a)
{
	while ((*a) && (*a)->next && (*a)->nb < (*a)->next->nb)
		(*a) = (*a)->next;
	if ((*a)->prev && (*a)->nb > (*a)->prev->nb && !(*a)->next)
	{
		turn_begin(a);
		return (SUCCESS);
	}
	else
	{
		turn_begin(a);
		return (FAIL);
	}
}

int 	alg_five(t_instr *in, t_stack **a, t_stack **b)
{
	int tmp;

	tmp = 0;
	pb(a, b, in);
	pb(a, b, in);
	alg_three(in, a);
	while ((*b))
	{
		if ((*b)->nb < (*a)->nb)
			pa(a, b, in);
		else if ((*b)->nb > (*a)->next->next->nb && (!(*a)->next->next->next ||
			(*b)->nb > (*a)->next->next->next->nb ))
		{
			tmp = (*a)->nb;
			pa(a, b, in);
			if ((*b) && (*b)->nb < (*a)->nb && (((*b)->nb >
				(*a)->next->next->next->nb)))
			{
				pa(a, b, in);
				ra(a, in);
			}
			while ((*a)->nb != tmp)
				ra(a, in);
		}
		else if ((*b)->nb > (*a)->nb && (*b)->nb < (*a)->next->nb)
		{
			ra(a, in);
			pa(a, b, in);
			rra(a, in);
		}
		else if ((*b)->nb > (*a)->nb && (*b)->nb > (*a)->next->nb)
		{
			tmp = (*a)->nb;
			if ((*b)->nb > (*a)->next->next->nb)
			{
				rra(a, in);
				pa(a, b, in);
				ra(a, in);
				ra(a, in);
			}
			else
			{
				ra(a, in);
				ra(a, in);
				pa(a, b, in);
			}
			if ((*b) && (*b)->nb < (*a)->nb && (*b)->nb <
				(*a)->next->next->next->nb)
			{
				rra(a, in);
				pa(a, b, in);
			}
			else if ((*b) && (*b)->nb > (*a)->nb &&
				(*b)->nb < (*a)->next->next->next->nb &&
				(*b)->nb > (*a)->next->nb && (*b)->nb > (*a)->next->next->nb)
			{
				rra(a, in);
				pa(a, b, in);
				ra(a, in);
				ra(a, in);
			}
			else if ((*b) && (*b)->nb < (*a)->nb && (*b)->nb > (*a)->next->next->next->nb
				&& (*b)->nb > (*a)->next->next->nb && (*b)->nb > (*a)->next->nb)
				pa(a, b, in);
			while ((*a)->nb != tmp)
				rra(a, in);
		}
		else if ((*b)->nb > (*a)->nb)
		{
			tmp = (*a)->nb;
			while ((*b)->nb > (*a)->nb)
				(*a) = (*a)->next;
			if ((*a)->next)
			pa(a, b, in);
			while ((*a)->nb != tmp)
				ra(a, in);
		}
	}
	return (SUCCESS);
}

int 	algorithm(t_instr *in, t_stack **a, t_stack **b)
{
	if (is_sorted(a))
		return (SUCCESS);
	if ((*in).size_a == 2)
	{
		alg_two(in, a);
		return (SUCCESS);
	}
	else if ((*in).size_a == 3)
	{
		alg_three(in, a);
		return (SUCCESS);
	}
	else if ((*in).size_a == 5)
	{
		alg_five(in, a, b);
		return (SUCCESS);
	}
	else
		push_to_a(a, b, in);
	return (SUCCESS);
}
