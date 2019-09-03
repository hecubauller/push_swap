/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 09:12:59 by huller            #+#    #+#             */
/*   Updated: 2019/09/02 13:40:57 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void 	ft_check_b(t_stack **a, t_stack **b, t_instr *in, t_alg **q)
{
	int 	tmp;
	int 	cnt;
	int 	tmp2;
	int 	act;
	int 	cycle;

	cnt = 11;
	tmp = 0;
	tmp2 = 0;
	cycle = 0;
	act = 0;
	if (!(*b)) //if 'b' is empty
		ft_pb(a, b, in);
	else if ((*b) && !(*b)->next) //if there is only one list
	{
		if ((*b)->nb > (*a)->nb) //number in 'b' is bigger
		{
			ft_pb(a, b, in);
			ft_sb(b, in);
		}
		else //number in 'b' is smaller
			ft_pb(a, b, in);
	}
	else //more than 1 list in stack 'b'
	{
		while ((*b) && --cnt)
		{
			if ((*b)->nb > (*a)->nb && (((*b)->next->nb < (*b)->nb &&
				(*a)->nb > (*b)->next->nb) || !(*b)->next))
			{
				tmp = (*b)->nb;
				cycle <= ((*in).size_a / 2) ? (act = RA_IS) : (act = RRA_IS);
				ft_turn_begin(b);
				tmp2 = (*b)->nb;
				while ((*b)->nb != tmp) //подкручиваем стек
					(act == RA_IS) ? ft_ra(b, in) : ft_rra(b, in);
				//(act == RA_IS) ? ft_ra(b, in) : ft_rra(b, in);
				ft_pb(a, b, in);
				while ((*b)->nb != tmp2)
					ft_rra(b, in);
			}
			else
			{
				if ((*b)->next)
					(*b) = (*b)->next;
				else
					break;
				cycle++;
			}
		}
	}
}

void	ft_push_up(t_stack **a, t_stack **b, t_instr *in, t_alg **q)
{
	if ((*q)->res == F_RA || (*q)->res == F_RRA)
	{
		while (((*q)->res == F_RA) && (*a)->nb != (*q)->hold_first)
			ft_ra(a, in);
		while (((*q)->res == F_RRA) && (*a)->nb != (*q)->hold_first)
			ft_rra(a, in);
	}
	else if ((*q)->res == S_RA || (*q)->res == S_RRA)
	{
		while (((*q)->res == S_RA) && (*a)->nb != (*q)->hold_second)
			ft_ra(a, in);
		while (((*q)->res == S_RRA) && (*a)->nb != (*q)->hold_second)
			ft_rra(a, in);
	}
	(*q)->res = 0;
	ft_check_b(a, b, in, q); //push to b
}

void	ft_check_size(t_stack **a, t_stack **b, t_instr **in, t_alg **q)
{
	int 	cnt_chunk;
	int 	prev_nb;
	int 	minimum;
	int 	i;
	int 	x;
	int 	y;

	i = 0;
	(*q)->max = 0;
	(*q)->min = (*a)->nb;
	minimum = (*q)->min;
	prev_nb = 0;
	x = 0;
	y = 0;
	(*q)->chunks = ((*in)->size_a % 10) ? (*in)->size_a / 10 + 1 :
				(*in)->size_a / 10; //количество чанков
	(*q)->cnt_up = *a; //счетчик сверху
	(*q)->cnt_dwn = ft_turn_end(a); //счетчик низу
	cnt_chunk = 10;
	ft_turn_begin(a);
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
	ft_create_maxs(q, a, in); //создание max's чанков
	prev_nb = (*q)->min;
	minimum = (*q)->min;
	int s = -1;
	int bj = 3;
	ft_putstr(RED "maximums: "RESET);
	while (--bj)
		ft_printf("%d ", (*q)->ar_of_mx[++s]);
	while ((*in)->size_a) //пока стек А не будет пустым
	{
		ft_turn_begin(a);
		(*q)->cnt_up = (*a); //счетчик сверху
		(*q)->cnt_dwn = ft_turn_end(a); //счетчик низу
		x = 0;
		y = 0;
		while ((*q)->cnt_up != (*q)->cnt_dwn && (!x || !y)) // пока счетчики не пересекутся
		{
			if ((*q)->cnt_up->nb >= minimum && (*q)->cnt_up->nb <= (*q)->ar_of_mx[i])
			{
				(*q)->hold_first = (*q)->cnt_up->nb;
				x = 1;
			}
			else
				(*q)->cnt_up = (*q)->cnt_up->next;
			if ((*q)->cnt_dwn->nb >= minimum && (*q)->cnt_dwn->nb <= (*q)->ar_of_mx[i])
			{
				(*q)->hold_second = (*q)->cnt_dwn->nb;
				y = 1;
			}
			else
				(*q)->cnt_dwn = (*q)->cnt_dwn->prev;
		}
		ft_how_long(*in, q); //какое значение оптимальнее двигать вверх
		ft_turn_begin(a);
		ft_push_up(a, b, *in, q);
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
	ft_check_size(a, b, &in, &q);
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
