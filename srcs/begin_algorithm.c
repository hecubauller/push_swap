/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 05:13:38 by huller            #+#    #+#             */
/*   Updated: 2019/08/27 08:11:24 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int 	ft_alg_five_hundred(t_instr *in, t_stack **a, t_stack **b)
{
	return (SUCCESS);
}

void 	ft_how_long(t_instr *in, t_stack **a, t_stack **b, t_alg **q)
{
	(*q)->ra_f = 0;
	(*q)->ra_s = 0;
	(*q)->rra_f = 0;
	(*q)->res = 0;
	(*q)->rra_s = 0;
	if ((*q)->place[0] <= ((*in).size_a / 2) && (*q)->place[1] <= ((*in).size_a / 2)) // 'ra' is faster
	{
		if ((*q)->place[0] > (*q)->place[1]) //if hold_first is faster
			(*q)->res = 1;
		else
			(*q)->res = 2;

	}
	else if ((*q)->place[0] > ((*in).size_a / 2)) // 'rra' is faster
	{

	}
	else if ((*q)->place[1] > ((*in).size_a / 2)) // 'rra' is faster
	{

	}









	if ((*q)->ra_f)
	{
		while ((*a)->nb != q->hold_first)
			ft_ra(a, in);
	}
	else if (!q->ra_f)
	{
		while ((*a)->nb != q->hold_first)
			ft_rra(a, in);
	}

}

int		ft_alg_hundred(t_instr *in, t_stack **a, t_stack **b)
{
	t_alg	*q;
	int 	i;
	int 	k;

	i = 0;
	k = -1;
	if (!(q = (t_alg)malloc(sizeof(t_alg))))
		return (ERROR);
	q->chunks = (*in).size_a / 20 + 1;
	q->cnt = -1;
	q->hold_first = 0;
	q->hold_second = 0;
	q->place[0] = -1;
	q->place[1] = -1;
	if (q->chunks >= 1)
	{
		while ((*a) && (*a)->next && k != 1)
			{
				if ((*a)->nb < 20)
				{
					q->place[++k] = i; //exit from cycle
					if (k == 0)
						q->hold_first = (*a)->nb;
					if (k == 1)
						q->hold_second = (*a)->nb;
				}
				else
				{
					(*a) = (*a)->next;
					++i; //list cnt
				}

			}
		while ((*a)->prev)
			(*a) = (*a)->prev;
		ft_how_long(in, a, b, &q);
		ft_pb(a, b, in);

	}
	return (SUCCESS);
}

int 	ft_alg_three(t_instr *in, t_stack **a, t_stack **b)
{
	if ((*a)->nb > (*a)->next->nb && (*a)->next->next->nb > (*a)->next->nb &&
		(*a)->nb < (*a)->next->next->nb)
		ft_sa(a, in);
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb)
	{
		ft_sa(a, in);
		ft_rra(a, in);
	}
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb < (*a)->next->next->nb)
		ft_ra(a, in);
	else if ((*a)->nb < (*a)->next->nb && (*a)->next->next->nb < (*a)->next->nb)
	{
		ft_sa(a, in);
		ft_rra(a, in);
	}
	return (SUCCESS);
}

int 	ft_algorithm(t_instr *in, t_stack **a, t_stack **b)
{
	if ((*in).size_a == 3)
	{
		ft_alg_three(in, a, b);
		return (SUCCESS);
	}
	else if ((*in).size_a <= 100)
		ft_alg_hundred(in, a, b);
	else if ((*in).size_a <= 500)
		ft_alg_five_hundred(in, a, b);
	return (ERROR);
}