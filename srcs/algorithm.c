/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:22:38 by huller            #+#    #+#             */
/*   Updated: 2019/09/21 21:01:04 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	cnt_cmnds_a(t_stack **a, t_stack **b, t_instr *in, t_sort **p)
{
	int		cnt;

	(*p)->end = 0;
	(*p)->start = 0;
	innn(a, p);
	cnt = cycle_cmnd_a(a, b, p);
	if_cmnd_a(a, in, p, cnt);
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
