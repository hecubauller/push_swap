/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 05:13:38 by huller            #+#    #+#             */
/*   Updated: 2019/08/27 10:31:08 by huller           ###   ########.fr       */
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
	(*q)->act_for_f = -1; //what to do for hold_first
	(*q)->act_for_s = -1; //what to do for hold_second
	((*q)->place[0] <= ((*in).size_a / 2)) ? ((*q)->act_for_f = RA_IS) :
		((*q)->act_for_f = RRA_IS);
	((*q)->place[1] <= ((*in).size_a / 2)) ? ((*q)->act_for_s = RA_IS) :
	((*q)->act_for_s = RRA_IS);
	if ((*q)->act_for_f == RA_IS && (*q)->act_for_f == ((*q)->act_for_s)) // 'ra' is faster for both
	{
		if ((*q)->place[0] >= (*q)->place[1]) //if hold_first is faster
			(*q)->res = F_RA; //first is faster
		else
			(*q)->res = S_RA; //second is faster

	}
	else if ((*q)->act_for_f == RRA_IS && (*q)->act_for_f == ((*q)->act_for_s)) // 'rra' is faster for both
	{
		if (((*in).size_a - (*q)->place[0]) < (*in).size_a - (*q)->place[1]) //if hold_first is faster
			(*q)->res = F_RRA; //first is faster
		else
			(*q)->res = S_RRA; //second is faster
	}
	else if ((*q)->act_for_f > (*q)->act_for_s) // 'ra' for first & 'rra' for second
	{
		if ((*q)->place[0] <  (*in).size_a - (*q)->place[1]) //if hold_first is faster
			(*q)->res = F_RA; //first is faster
		else
			(*q)->res = S_RRA; //second is faster
	}
	else if ((*q)->act_for_f < (*q)->act_for_s) // 'rra' for first & 'ra' for second
	{
		if (((*in).size_a - (*q)->place[0]) < (*q)->place[1]) //if hold_first is faster
			(*q)->res = F_RRA; //first is faster
		else
			(*q)->res = S_RA; //second is faster
	}
}

int		ft_alg_hundred(t_instr *in, t_stack **a, t_stack **b)
{
	t_alg	*q;
	int 	i;
	int 	k;
	int 	cnt;

	cnt = 0;
	if (!(q = (t_alg *)malloc(sizeof(t_alg))))
		return (ERROR);
	q->chunks = (*in).size_a / 20 + 1;
	q->cnt = -1;
	q->hold_first = 0;
	q->hold_second = 0;
	q->place[0] = -1;
	q->place[1] = -1;
	while ((q->chunks >= ++cnt) && ((*in).size_a != 0))
	{
		i = 0;
		k = -1;
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
		if ((*q).res == F_RA || (*q).res == F_RRA)
		{
			while (((*q).res == F_RA) && (*a)->nb != q->hold_first)
				ft_ra(a, in);
			while (((*q).res == F_RRA) && (*a)->nb != q->hold_first)
				ft_rra(a, in);
		}
		if ((*q).res == S_RA || (*q).res == S_RRA)
		{
			while (((*q).res == S_RA) && (*a)->nb != q->hold_first)
				ft_ra(a, in);
			while (((*q).res == S_RRA) && (*a)->nb != q->hold_first)
				ft_rra(a, in);
		}
		if ((*b) && (*a) && (*b)->nb < (*a)->nb)
			ft_pb(a, b, in); //push to Stack B
		else
		{
			ft_pb(a, b, in);
			ft_sb(b, in);
		}
		while (((*a) && (*a)->next) || ((*b) && (*b)->next))
		{
			ft_putstr("\n");
			(*a) ? ft_printf("a: %d ", (*a)->nb) : ft_printf("a: ");
			(*b) ? ft_printf("\nb: %d ", (*b)->nb) : ft_printf(" ");
			(*a) = (*a)->next;
			(*b) = (*b)->next;
		}
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