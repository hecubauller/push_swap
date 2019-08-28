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

t_stack	*ft_turn_end(t_stack **x)
{
	while ((*x) && (*x)->next)
		(*x) = (*x)->next;
	return (*x);
}

t_stack	*ft_turn_begin(t_stack **x)
{
	while ((*x) && (*x)->prev)
		(*x) = (*x)->prev;
	return (*x);
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

void	ft_create_maxs(t_alg **q, int **arofch)
{
	int		cnt;
	int 	cnt_ar;

	cnt = -1;
	cnt_ar = 0;
	while (++cnt <= (*q)->chunks)
	{
		if ()
	}
}

void	ft_check_size(t_stack **a, t_stack **b, t_instr **in, t_alg **q)
{
	int 	cnt_chunk;
	int 	*arofch;

	(*q)->max = 0;
	(*q)->min = (*q)->max;
	(*q)->chunks = ((*in)->size_a % 10) ? (*in)->size_a / 10 + 1 : (*in)->size_a / 10; //количество чанков
	if (!(arofch = (int *)malloc(sizeof(int) * (*q)->chunks)))
		return ;
	(*q)->cnt_up = *a; //счетчик сверху
	(*q)->cnt_dwn = ft_turn_end(a); //счетчик низу
	cnt_chunk = 10;
	while ((*a) && (*a)->next) //поиск максимума
	{
		((*a)->nb > (*q)->max) ? ((*q)->max = (*a)->nb) : 0;
		((*a) = (*a)->next);
	}
	ft_turn_begin(a);
	while ((*a) && (*a)->next)// поиск минимума
	{
		((*a)->nb < (*q)->min) ? ((*q)->min = (*a)->nb) : 0;
		(*a) = (*a)->next;
	}
	ft_create_maxs(q, &arofch);
	ft_turn_begin(a);
	while ((*in)->size_a) //пока стек А не будет пустым
	{
		cnt_chunk = 10;
		(*q)->cnt_up = (*a); //счетчик сверху
		(*q)->cnt_dwn = ft_turn_end(a); //счетчик низу
		while ((*q)->cnt_up != (*q)->cnt_dwn && cnt_chunk) // пока счетчики не пересекутся
		{
			if ((*q)->cnt_up->nb => (*q)->min && (*q)->cnt_dwn->nb <= (*q)->max)
		}
	}
}

int		ft_alg_hundred(t_instr *in, t_stack **a, t_stack **b)
{
	t_alg	*q;
	int 	x;
	int 	i;
	int 	k;
	int 	cnt;
	int 	max;

	cnt = 0;
	max = 0;
	if (!(q = (t_alg *)malloc(sizeof(t_alg))))
		return (ERROR);
	q->hold_first = 0;
	q->hold_second = 0;
	q->place[0] = -1;
	q->place[1] = -1;

	ft_check_size(a, b, in, &q);


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
	else
		ft_alg_hundred(in, a, b);
	return (ERROR);
}