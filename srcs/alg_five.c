/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_five.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:44:56 by huller            #+#    #+#             */
/*   Updated: 2019/09/21 04:05:54 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		check_output(t_stack **a, t_instr *in)
{
	if (!(in->size_b))
	{
		turn_begin(a);
		while ((*a) && (*a)->next)
		{
			if ((*a)->nb < (*a)->next->nb)
				(*a)->next ? (*a) = (*a)->next : 0;
			else
				return (KO);
		}
		return (OK);
	}
	return (KO);
}

void	five_four(t_instr *in, t_stack **a, t_stack **b)
{
	int tmp;

	tmp = five_two(in, a, b);
	if ((*b) && (*b)->nb < (*a)->nb && (*b)->nb < (*a)->next->next->next->nb)
	{
		rra(a, in);
		pa(a, b, in);
	}
	else if ((*b) && (*b)->nb > (*a)->nb && (*b)->nb <
	(*a)->next->next->next->nb && (*b)->nb > (*a)->next->nb && (*b)->nb >
	(*a)->next->next->nb)
	{
		rra(a, in);
		pa(a, b, in);
		ra(a, in);
		ra(a, in);
	}
	else if ((*b) && (*b)->nb < (*a)->nb && (*b)->nb >
	(*a)->next->next->next->nb && (*b)->nb > (*a)->next->next->nb &&
	(*b)->nb > (*a)->next->nb)
		pa(a, b, in);
	while ((*a)->nb != tmp)
		rra(a, in);
}

void	five_three(t_instr *in, t_stack **a, t_stack **b)
{
	int	tmp;

	tmp = (*a)->nb;
	while ((*b)->nb > (*a)->nb)
		(*a) = (*a)->next;
	if ((*a)->next)
		pa(a, b, in);
	while ((*a)->nb != tmp)
		ra(a, in);
}

int		five_two(t_instr *in, t_stack **a, t_stack **b)
{
	int	tmp;

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
	return (tmp);
}

void	five_one(t_instr *in, t_stack **a, t_stack **b)
{
	int tmp;

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
