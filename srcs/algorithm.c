 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:24:52 by huller            #+#    #+#             */
/*   Updated: 2019/09/17 20:52:26 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

 void 	create_max(t_stack **a, t_sort **p)
 {
	 (*p)->max = (*a)->nb;
	 while ((*a) && (*a)->next)
	 {
		 ((*a)->nb > (*p)->max) ? ((*p)->max = (*a)->nb) : 0;
		 ((*a) = (*a)->next);
	 }
	 ((*a)->nb > (*p)->max) ? ((*p)->max = (*a)->nb) : 0;
	 turn_begin(a);
 }

int		search_beginning(t_stack **a, int end)
 {
	int 	start;

	start = 0;
	 while ((*a) && (*a)->next)
	 {
		 if (((*a)->prev && (*a)->nb < (*a)->prev->nb) ||
			 (!(*a)->prev && end > (*a)->nb))
		 {
			 start = (*a)->nb;
			 break;
		 }
		 (*a) = (*a)->next;
	 }
	 start = (*a)->nb;
	 return (start);
 }

 void	cnt_cmnds_a(t_stack **a, t_stack **b, t_instr *in, t_sort **p)
{
	int 	end;
	int 	start;
	int 	cnt;

	cnt = 0;
	end = 0;
	innn(a, p, &end, &start);
	while ((*a))
	{
		if (((*a)->prev && (*a)->nb > (*b)->nb && (*a)->prev->nb < (*b)->nb)
			|| ((*a)->nb > (*b)->nb && !(*a)->prev && end < (*b)->nb)
			|| ((*a)->nb > (*b)->nb && (*a)->nb == start))
			break;
		else if ((!(*a)->prev && (*a)->nb == (*p)->max && (*b)->nb > (*p)->max))
		{
			cnt++;
			break;
		}
		else if ((*a)->nb < (*b)->nb && (*a)->nb == (*p)->max)
		{
			cnt++;
			break;
		}
		cnt++;
		if ((*a)->next)
			(*a) = (*a)->next;
		else if ((*b)->nb > (*a)->nb && !(*a)->next)
		{
			cnt = 0;
			break;
		}
		else
		{
			turn_begin(a);
			cnt = 0;
		}
	}
	if (cnt && cnt <= ((*in).size_a / 2))
	{
		(*p)->cmnd_a = cnt;
		(*p)->ra = cnt;
	}
	else if (cnt > ((*in).size_a / 2))
	{
		(*p)->cmnd_a = ((*in).size_a - cnt);
		(*p)->rra = ((*in).size_a - cnt);
	}
	turn_begin(a);
}

void	cnt_cmnds_b(t_stack **b, t_instr *in, t_sort **p)
{
	int 	tmp;
	int 	cnt;

	cnt = 0;
	(*p)->rr = 0;
	(*p)->ra = 0;
	(*p)->rb = 0;
	(*p)->rrr = 0;
	(*p)->rra = 0;
	(*p)->rrb = 0;
	(*b) ? tmp = (*b)->nb : 0;
	(*b) ? (*p)->nb = (*b)->nb : 0;
	turn_begin(b);
	(*p)->rb = 0;
	(*p)->cmnd_b = 0;
	(*p)->rrb = 0;
	(*p)->cmnd_b = 0;
	while ((*b) && (*b)->nb != tmp)
	{
		(*b) = (*b)->next;
		++cnt;
	}
	if (cnt && cnt <= ((*in).size_b / 2))
	{
		(*p)->cmnd_b = cnt;
		(*p)->rb = cnt;
	}
	else if (cnt > ((*in).size_b / 2))
	{
		(*p)->cmnd_b = ((*in).size_b - cnt);
		(*p)->rrb = ((*in).size_b - cnt);
	}
}


void	algo_loop(t_stack **a, t_stack **b, t_instr *in, t_sort **p)
{
	while ((*b) && (*b)->next)
	{
		cnt_cmnds_b(b, in, p);
		cnt_cmnds_a(a, b, in, p);
		total_cmnds(p);
		compare_comands(p);
		(*b) = (*b)->next;
	}
}

void	new_algo(t_stack **a, t_stack **b, t_instr *in, t_sort **p)
{
	while ((*b))
	{
		initialize(b, p);
		algo_loop(a, b, in, p);
		cnt_cmnds_b(b, in, p);
		cnt_cmnds_a(a, b, in, p);
		total_cmnds(p);
		compare_comands(p);
		apply_cmnds(a, b, in, p);
		turn_begin(a);
		turn_begin(b);
	}
}

void	create_min(t_stack **a, t_sort **p)
{
	(*a) ? (*p)->min = (*a)->nb : 0;
	while ((*a) && (*a)->next)
	{
		((*a)->nb < (*p)->min) ? ((*p)->min = (*a)->nb) : 0;
		(*a) = (*a)->next;
	}
	if ((*a)->nb < (*p)->min)
		(*p)->min = (*a)->nb;
}

void	finish_stack(t_stack **a, t_instr *in, t_sort **p)
{
	int		cnt;

	cnt = 0;
	create_min(a, p);
	turn_begin(a);
	while ((*a) && (*a)->next && (*a)->nb != (*p)->min)
	{
		(*a) = (*a)->next;
		cnt++;
	}
	turn_begin(a);
	if (cnt && cnt <= ((*in).size_a / 2))
	{
		while ((*a)->nb != (*p)->min)
			ra(a, in);
	}
	else if (cnt > ((*in).size_a / 2))
	{
		while ((*a)->nb != (*p)->min)
			rra(a, in);
	}
	free(*p);
}

void	push_to_a(t_stack **a, t_stack **b, t_instr *in)
{
	t_sort		*p;

	if (!(p = (t_sort *)malloc(sizeof(t_sort))))
		return ;
	while ((*in).size_a != 3)
		pb(a, b, in);
	alg_three(in, a);
	new_algo(a, b, in, &p);
	finish_stack(a, in, &p);
}
