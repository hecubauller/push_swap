/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 09:12:59 by huller            #+#    #+#             */
/*   Updated: 2019/09/17 20:52:26 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void 	check_b(t_stack **a, t_stack **b, t_instr *in, t_alg **q)
{
	int 	tmp;
	t_stack	*tmp_s;
	int 	cnt;
	int 	tmp2;
	int 	act;
	int 	cycle;

	cnt = 10;
	tmp = 0;
	tmp2 = 0;
	cycle = 1;
	act = 0;
	tmp_s = NULL;
	if (!(*b)) //if 'b' is empty
		pb(a, b, in);
	else if ((*b) && !(*b)->next) //if there is only one list
	{
		if ((*a) && (*b) && (*b)->nb > (*a)->nb) //number in 'b' is bigger
		{
			pb(a, b, in);
			sb(b, in);
		}
		else //number in 'b' is smaller
			pb(a, b, in);
	}
	else //more than 1 list in stack 'b'
	{
		while ((*b) && (*a) && (*b)->next && (*a)->nb < (*b)->nb)
		{
			(*b) = (*b)->next;
			tmp_s = (*b);
		}
		turn_begin(b);
		if (tmp_s && tmp_s->next == NULL && tmp_s->nb > (*a)->nb) //если a->nb ньше всех в стеке b
		{
			pb(a, b, in);
			rb(b, in);
		}
		else
		{
			if ((*a) && (*b) && (*b)->nb > (*a)->nb &&
					((*b)->next && (((*b)->next->nb < (*b)->nb &&
					(*a)->nb < (*b)->next->nb))))
			{
				tmp = (*b)->nb; //beginning
				while ((*a)->nb < (*b)->nb)
					(*b) = (*b)->next;
				tmp2 = (*b)->nb; //push to
				turn_begin(b);
				while ((*b)->nb != tmp2)
					rb(b, in);
				pb(a, b, in);
				while ((*b)->nb != tmp)
					rrb(b, in);
			}
			else if ((*a) && (*b) && (*b)->nb > (*a)->nb &&
				(!(*b)->next || (((*b)->next->nb < (*b)->nb &&
				(*a)->nb > (*b)->next->nb))))
			{
				rb(b, in);
				pb(a, b, in);
				rrb(b, in);
			}
			else if ((*a) && (*b) && (*a)->nb > (*b)->nb)
				pb(a, b, in);
		}
	}
}

void	push_up(t_stack **a, t_stack **b, t_instr *in, t_alg **q)
{
	if ((*q)->res == NTHNG)
		;
	else if ((*a) && ((*q)->res == F_RA || (*q)->res == F_RRA))
	{
		while (((*q)->res == F_RA) && (*a)->nb != (*q)->hold_first) //infinite loop
			ra(a, in);
		while (((*q)->res == F_RRA) && (*a)->nb != (*q)->hold_first)
			rra(a, in);
	}
	else if ((*a) && ((*q)->res == S_RA || (*q)->res == S_RRA))
	{
		while (((*q)->res == S_RA) && (*a)->nb != (*q)->hold_second)
			ra(a, in);
		while (((*q)->res == S_RRA) && (*a)->nb != (*q)->hold_second)
			rra(a, in);
	}
	(*q)->res = 0;
}

void	push_a(t_stack **a, t_stack **b, t_instr *in)
{
	turn_begin(b);
	while ((*b))
		pa(a, b, in);
	free_lsts(a);
	exit(0);
}

void	create_maxmin(t_stack **a, t_instr **in, t_alg **q)
{
	(*q)->max = 0;
	(*q)->min = (*a)->nb;
	(*q)->chunks = ((*in)->size_a % 10) ? (*in)->size_a / 10 + 1 :
				   (*in)->size_a / 10; //количество чанков
	(*q)->cnt_up = *a; //счетчик сверху
	(*q)->cnt_dwn = turn_end(a); //счетчик низу
	turn_begin(a);
	while ((*a) && (*a)->next) //поиск максимума
	{
		((*a)->nb > (*q)->max) ? ((*q)->max = (*a)->nb) : 0;
		((*a) = (*a)->next);
	}
	((*a)->nb > (*q)->max) ? ((*q)->max = (*a)->nb) : 0;
	turn_begin(a);
	while ((*a) && (*a)->next)// поиск минимума
	{
		((*a)->nb < (*q)->min) ? ((*q)->min = (*a)->nb) : 0;
		(*a) = (*a)->next;
	}
	((*a)->nb < (*q)->min) ? ((*q)->min = (*a)->nb) : 0;
}

void	check_size(t_stack **a, t_stack **b, t_instr **in, t_alg **q)
{
	int 	i;
	int 	x;
	int 	y;
	int 	cnt;
	int 	minimum;

	i = 0;
	x = 0;
	y = 0;
	cnt = 9;
	minimum = 0;
	create_maxmin(a, in, q); //поиск максимума и минимума
	create_maxs(q, a, in); //создание max's чанков
	minimum = (*q)->min; //start from the smallest nb
	while ((*a)) //пока стек А не будет пустым
	{
		x = 0;
		y = 0;
		turn_begin(a);
		(*q)->cnt_up = (*a); //счетчик сверху
		(*q)->cnt_dwn = turn_end(a); //счетчик низу
		turn_begin(a);
		while ((*q)->cnt_up != (*q)->cnt_dwn && (!x || !y)) // пока счетчики не пересекутся
		{
			if ((*q)->cnt_up->nb >= minimum && (*q)->cnt_up->nb <=
				(*q)->ar_of_mx[i])
			{
				x = 1;
				(*q)->hold_first = (*q)->cnt_up->nb;
			}
			else
				(*q)->cnt_up = (*q)->cnt_up->next;
			if ((*q)->cnt_dwn->nb >= minimum && (*q)->cnt_dwn->nb <=
				(*q)->ar_of_mx[i])
			{
				y = 1;
				(*q)->hold_second = (*q)->cnt_dwn->nb;
			}
			else
				(*q)->cnt_dwn = (*q)->cnt_dwn->prev;
		}
		if ((*a) && (((*a)->prev || (*a)->next)))
		{
			cnt_place(a, in, q);
			how_long(*in, q); //какое значение оптимальнее двигать вверх
			turn_begin(a);
		}
		push_up(a, b, *in, q);
		pb(a, b, *in);
		//ft_check_b(a, b, in, q); //push to b
		if (cnt)
			--cnt;
		else
		{
			minimum = (*q)->ar_of_mx[i]; //неправильное условие
			++i;
			cnt = 9;
		}
	}
	push_back(a, b, in, q);
	//ft_push_a(a, b, *in);
}

int		alg_hundred(t_instr *in, t_stack **a, t_stack **b)
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
	check_size(a, b, &in, &q);
	return (SUCCESS);
}

int 	alg_three(t_instr *in, t_stack **a)
{
	if ((*a)->nb < (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb &&
			(*a)->next->next->nb < (*a)->nb)
		rra(a, in);
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->next->nb > (*a)->next->nb &&
		(*a)->nb < (*a)->next->next->nb)
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

int 	ft_is_sorted(t_instr *in, t_stack **a, t_stack **b)
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
	int tmp2;

	tmp = 0;
	pb(a, b, in);
	pb(a, b, in);
	alg_three(in, a);
	while ((*b))
	{
		if ((*b)->nb < (*a)->nb) // 'b' is smaller than all nbrs in 'a'
			pa(a, b, in);
		else if ((*b)->nb > (*a)->next->next->nb && (!(*a)->next->next->next || (*b)->nb > (*a)->next->next->next->nb )) //'b->nb' is bigger than all nbrs in 'a'
		{
			tmp = (*a)->nb;
			pa(a, b, in);
			if ((*b) && (*b)->nb < (*a)->nb && (((*b)->nb > (*a)->next->next->next->nb)))
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
			if ((*b) && (*b)->nb < (*a)->nb && (*b)->nb < (*a)->next->next->next->nb)
			{
				rra(a, in);
				pa(a, b, in);
			}
			else if ((*b) && (*b)->nb > (*a)->nb && (*b)->nb < (*a)->next->next->next->nb
				&& (*b)->nb > (*a)->next->nb && (*b)->nb > (*a)->next->next->nb)
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
		else if ((*b)->nb > (*a)->nb) //'b' is bigger than few nbrs
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
		push_to_a(a, b, in);
		//ft_alg_hundred(in, a, b);
	return (SUCCESS);
}
