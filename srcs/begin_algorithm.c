/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 09:12:59 by huller            #+#    #+#             */
/*   Updated: 2019/09/05 17:08:23 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void 	ft_check_b(t_stack **a, t_stack **b, t_instr *in, t_alg **q)
{
	int 	tmp;
	t_stack	*tmp_s;
	int 	cnt;
	int 	tmp2;
	int 	act;
	int 	cycle;

	cnt = 11;
	tmp = 0;
	tmp2 = 0;
	cycle = 0;
	act = 0;
	tmp_s = NULL;
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
		while ((*b) && --cnt && (*b)->next && (*a)->nb < (*b)->nb)
		{
			(*b) = (*b)->next;
			tmp_s = (*b);
		}
		ft_turn_begin(b);
		if (tmp_s && tmp_s->next == NULL && tmp_s->nb > (*a)->nb)
		{
			ft_pb(a, b, in);
			ft_rb(b, in);
		}
		else
		{
			cnt = 11;
			while ((*b) && --cnt && (*a))
			{
				if ((*b)->nb > (*a)->nb &&
					(!(*b)->next || (((*b)->next->nb<(*b)->nb &&
					(*a)->nb > (*b)->next->nb))))
				{
					tmp = (*b)->nb;
					cycle <= ((*in).size_a / 2) ? (act = RA_IS)
												: (act = RRA_IS);
					ft_turn_begin(b);
					tmp2 = (*b)->nb;
					while ((*b)->nb != tmp) //подкручиваем стек
						(act == RA_IS) ? ft_rb(b, in) : ft_rrb(b, in);
					/*(act == RA_IS) ? */ft_rb(b, in)/* : ft_rrb(b, in)*/;
					ft_pb(a, b, in);
					while ((*b)->nb != tmp2)
						ft_rb(b, in);
				} else if ((*a)->nb > (*b)->nb)
					ft_pb(a, b, in);
				else {
					if ((*b)->next)
						(*b) = (*b)->next;
					else
						break;
					cycle++;
				}
			}
		}
	}
}

void	ft_push_up(t_stack **a, t_stack **b, t_instr *in, t_alg **q)
{
	if ((*q)->res == NTHNG)
		;
	else if ((*a) && ((*q)->res == F_RA || (*q)->res == F_RRA))
	{
		while (((*q)->res == F_RA) && (*a)->nb != (*q)->hold_first)
			ft_ra(a, in);
		while (((*q)->res == F_RRA) && (*a)->nb != (*q)->hold_first)
			ft_rra(a, in);
	}
	else if ((*a) && ((*q)->res == S_RA || (*q)->res == S_RRA))
	{
		while (((*q)->res == S_RA) && (*a)->nb != (*q)->hold_second)
			ft_ra(a, in);
		while (((*q)->res == S_RRA) && (*a)->nb != (*q)->hold_second)
			ft_rra(a, in);
	}
	(*q)->res = 0;
	ft_check_b(a, b, in, q); //push to b
}

void	ft_push_a(t_stack **a, t_stack **b, t_instr *in)
{
	ft_turn_begin(b);
	while ((*b))
		ft_pa(a, b, in);
	ft_free_lsts(a);
	exit(0);
}

void	ft_check_size(t_stack **a, t_stack **b, t_instr **in, t_alg **q)
{
	int 	cnt_chunk;
	int 	prev_nb;
	int 	minimum;
	int 	i;
	int 	j;
	int 	x;
	int 	y;

	i = 0;
	(*q)->max = 0;
	(*q)->min = (*a)->nb;
	minimum = (*q)->min;
	prev_nb = 0;
	x = 0;
	y = 0;
	j = -1;
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
	((*a)->nb > (*q)->max) ? ((*q)->max = (*a)->nb) : 0;
	ft_turn_begin(a);
	while ((*a) && (*a)->next)// поиск минимума
	{
		((*a)->nb < (*q)->min) ? ((*q)->min = (*a)->nb) : 0;
		(*a) = (*a)->next;
	}
	((*a)->nb < (*q)->min) ? ((*q)->min = (*a)->nb) : 0;
	ft_create_maxs(q, a, in); //создание max's чанков
	prev_nb = (*q)->min;
	minimum = (*q)->min;
	while ((*in)->size_a) //пока стек А не будет пустым
	{
		ft_turn_begin(a);
		(*q)->cnt_up = (*a); //счетчик сверху
		(*q)->cnt_dwn = ft_turn_end(a); //счетчик низу
		ft_turn_begin(a);
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
		if ((*a) && (((*a)->prev || (*a)->next)))
		{
			cnt_place(a, in, q);
			how_long(*in, q); //какое значение оптимальнее двигать вверх
			ft_turn_begin(a);
		}
		ft_push_up(a, b, *in, q);
		//minimum = (*q)->ar_of_mx[++j];

	}
	//free (q);
	ft_push_a(a, b, *in);
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

int 	alg_three(t_instr *in, t_stack **a)
{
	if ((*a)->nb < (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb &&
			(*a)->next->next->nb < (*a)->nb)
		ft_rra(a, in);
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->next->nb > (*a)->next->nb &&
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
		ft_ra(a, in);
	}
	return (SUCCESS);
}

void	alg_two(t_instr *in, t_stack **a)
{
	if ((*a)->nb > (*a)->next->nb)
		ft_sa(a, in);
}

int 	ft_is_sorted(t_instr *in, t_stack **a, t_stack **b)
{
	while ((*a) && (*a)->next && (*a)->nb < (*a)->next->nb)
		(*a) = (*a)->next;
	if ((*a)->prev && (*a)->nb > (*a)->prev->nb && !(*a)->next)
	{
		ft_turn_begin(a);
		return (SUCCESS);
	}
	else
	{
		ft_turn_begin(a);
		return (FAIL);
	}
}

int 	alg_five(t_instr *in, t_stack **a, t_stack **b)
{
	int tmp;
	int tmp2;

	tmp = 0;
	ft_pb(a, b, in);
	ft_pb(a, b, in);
	alg_three(in, a);
	while ((*b))
	{
		if ((*b)->nb < (*a)->nb) // 'b' is smaller than all nbrs in 'a'
			ft_pa(a, b, in);
		else if ((*b)->nb > (*a)->next->next->nb && (!(*a)->next->next->next || (*b)->nb > (*a)->next->next->next->nb )) //'b->nb' is bigger than all nbrs in 'a'
		{
			tmp = (*a)->nb;
			ft_pa(a, b, in);
			if ((*b) && (*b)->nb < (*a)->nb && (((*b)->nb > (*a)->next->next->next->nb)))
			{
				ft_pa(a, b, in);
				ft_ra(a, in);
			}
			while ((*a)->nb != tmp)
				ft_ra(a, in);
		}
		else if ((*b)->nb > (*a)->nb && (*b)->nb < (*a)->next->nb)
		{
			ft_ra(a, in);
			ft_pa(a, b, in);
			ft_rra(a, in);
		}
		else if ((*b)->nb > (*a)->nb && (*b)->nb > (*a)->next->nb)
		{
			tmp = (*a)->nb;
			if ((*b)->nb > (*a)->next->next->nb)
			{
				ft_rra(a, in);
				ft_pa(a, b, in);
				ft_ra(a, in);
				ft_ra(a, in);
			}
			else
			{
				ft_ra(a, in);
				ft_ra(a, in);
				ft_pa(a, b, in);
			}
			if ((*b) && (*b)->nb < (*a)->nb && (*b)->nb < (*a)->next->next->next->nb)
			{
				ft_rra(a, in);
				ft_pa(a, b, in);
			}
			else if ((*b) && (*b)->nb > (*a)->nb && (*b)->nb < (*a)->next->next->next->nb
				&& (*b)->nb > (*a)->next->nb && (*b)->nb > (*a)->next->next->nb)
			{
				ft_rra(a, in);
				ft_pa(a, b, in);
				ft_ra(a, in);
				ft_ra(a, in);
			}
			else if ((*b) && (*b)->nb < (*a)->nb && (*b)->nb > (*a)->next->next->next->nb
				&& (*b)->nb > (*a)->next->next->nb && (*b)->nb > (*a)->next->nb)
				ft_pa(a, b, in);
			while ((*a)->nb != tmp)
				ft_rra(a, in);
		}
		else if ((*b)->nb > (*a)->nb) //'b' is bigger than few nbrs
		{
			tmp = (*a)->nb;
			while ((*b)->nb > (*a)->nb)
				(*a) = (*a)->next;
			if ((*a)->next)
			ft_pa(a, b, in);
			while ((*a)->nb != tmp)
				ft_ra(a, in);
		}
	}
	return (SUCCESS);
}

int 	ft_algorithm(t_instr *in, t_stack **a, t_stack **b)
{
	if (ft_is_sorted(in, a, b))
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
		ft_alg_hundred(in, a, b);
	return (SUCCESS);
}
