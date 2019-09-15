/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:24:52 by huller            #+#    #+#             */
/*   Updated: 2019/09/05 15:42:22 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void 	apply_cmnds(t_stack **a, t_stack **b, t_instr *in, t_sort **p)
{

}

void	total_cmnds(t_stack **a, t_stack **b, t_instr *in, t_sort **p)
{
	(*p)->tot_cmnds = 0;
	(*p)->rr = 0;
	(*p)->rrr = 0;
	

}

void	cnt_cmnds_a(t_stack **a, t_stack **b, t_instr *in, t_sort **p)
{
	int 	end;
	int 	start;
	int 	cnt;

	cnt = 0;
	(*p)->ra = 0;
	(*p)->rra = 0;
	start = 0;
	ft_turn_end(a);
	end = (*a)->nb;
	ft_turn_begin(a);
	while ((*a) && (*a)->next) //поиск начала стекa
	{
		if (((*a)->nb < (*a)->prev->nb) || (!(*a)->prev && end > (*a)->nb))
		{
			start = (*a)->nb;
			break;
		}
		(*a) = (*a)->next;
	}
	while ((*a)) //куда вставить число
	{
		if (((*a)->nb > (*b)->nb && (*a)->prev->nb < (*b)->nb) ||
			((*a)->nb > (*b)->nb && !(*a)->prev && end < (*b)->nb))
			break;
		(*a) = (*a)->next;
		cnt++;
	}
	if (cnt && cnt <= ((*in).size_a / 2))
	{
		(*p)->cmnd_a = cnt;
		(*p)->ra = 1;
	}
	else if (cnt > ((*in).size_a / 2))
	{
		(*p)->cmnd_a = ((*in).size_a - cnt);
		(*p)->rra = 1;
	}
	ft_turn_begin(a);
}

void 	cnt_cmnds_b(t_stack **b, t_instr *in, t_sort **p)
{
	int 	tmp;
	int 	cnt;

	cnt = 0;
	tmp = (*b)->nb;
//	(*p)->nb = (*b)->nb;
	ft_turn_begin(b);
	(*p)->rb = 0;
	(*p)->rrb = 0;
	while ((*b)->nb != tmp)
	{
		(*b) = (*b)->next;
		++cnt;
	}
	if (cnt && cnt <= ((*in).size_b / 2))
	{
		(*p)->cmnd_b = cnt;
		(*p)->rb = 1;
	}
	else if (cnt > ((*in).size_b / 2))
	{
		(*p)->cmnd_b = ((*in).size_b - cnt);
		(*p)->rrb = 1;
	}
	// куда записывать кол-во команд?
}

void	new_algo(t_stack **a, t_stack **b, t_instr *in, t_sort **p)
{
	(*p)->prev_nb = (*b)->nb;
	while ((*b) && (*b)->next)
	{
		cnt_cmnds_b(b, in, p);
		cnt_cmnds_a(a, b, in, p);
		total_cmnds(a, b, in, p);
		apply_cmnds(a, b, in, p);
		(*b) = (*b)->next;
	}
	(*b) = (*b)->next;
	cnt_cmnds_b(b, in, p);
	cnt_cmnds_a(a, b, in, p);
	total_cmnds(a, b, in, p);
	apply_cmnds(a, b, in, p);
}

void 	create_min(t_stack **a, t_sort **p)
{
	(*p)->min = (*a)->nb;
	while ((*a) && (*a)->next)
	{
		((*a)->nb < (*p)->min) ? ((*p)->min = (*a)->nb) : 0;
		(*a) = (*a)->next;
	}
	((*a)->nb < (*p)->min) ? ((*p)->min = (*a)->nb) : 0;
}

void 	finish_stack(t_stack **a, t_instr *in, t_sort **p)
{
	int		cnt;

	cnt = 0;
	create_min(a, p);
	while ((*a) && (*a)->next && (*a)->nb != (*p)->min)
	{
		(*a) = (*a)->next;
		cnt++;
	}
	if ((*a) && (*a)->nb == (*p)->min)
	{
		ft_rra(a, in);
		return ;
	}
	ft_turn_begin(a);
	if (cnt && cnt <= ((*in).size_a / 2))
	{
		while ((*a)->nb != (*p)->min)
			ft_ra(a, in);
	}
	else if (cnt > ((*in).size_a / 2))
	{
		while ((*a)->nb != (*p)->min)
			ft_rra(a, in);
	}
}

void 	push_to_a(t_stack **a, t_stack **b, t_instr *in)
{
	t_sort		*p;

	if (!(p = (t_sort *)malloc(sizeof(t_sort))))
		return ;
	while ((*in).size_a != 3) //push everything except 3 nbrs to 'b'
		ft_pb(a, b, in);
	alg_three(in, a); //sort three numbers
	new_algo(a, b, in, &p);
	finish_stack(a, in, &p);
}