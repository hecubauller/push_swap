/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:24:52 by huller            #+#    #+#             */
/*   Updated: 2019/09/16 01:45:48 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void 	apply_cmnds(t_stack **a, t_stack **b, t_instr *in, t_sort **p)
{
	turn_begin(a);
	turn_begin(b);
	while ((*b) && (*b)->nb != (*p)->prev_nb)
	{
		if ((*p)->p_rb)
		{
			rb(b, in);
			(*p)->p_rb--;
		}
		if ((*p)->p_rrb)
		{
			rrb(b, in);
			(*p)->p_rrb--;
		}
		if ((*p)->p_rrr)
		{
			rrr(a, b, in);
			(*p)->p_rrr--;
		}
		//сколько каких действий?
	}
	while ((*a) && )
	pa(a, b, in);

}

void	total_cmnds(t_sort **p)
{
	(*p)->rr = 0;
	(*p)->rrr = 0;
	(*p)->prev_cmnds = (*p)->tot_cmnds;
	(*p)->tot_cmnds = 0;
	if ((*p)->rb && (*p)->ra)
	{
		(*p)->rrr = 0;
		(*p)->rra = 0;
		(*p)->rrb = 0;
		if ((*p)->cmnd_a >= (*p)->cmnd_b)
		{
			(*p)->rb = 0;
			(*p)->rr = (*p)->cmnd_b;
			(*p)->ra = (*p)->cmnd_a - (*p)->cmnd_b;
			(*p)->tot_cmnds = (*p)->cmnd_a;
		}
		else if ((*p)->cmnd_a < (*p)->cmnd_b)
		{
			(*p)->ra = 0;
			(*p)->rr = (*p)->cmnd_b;
			(*p)->rb = (*p)->cmnd_b - (*p)->cmnd_a;
			(*p)->tot_cmnds = (*p)->cmnd_b;
		}
	}
	else if ((*p)->rrb && (*p)->rra)
	{
		(*p)->rr = 0;
		(*p)->ra = 0;
		(*p)->rb = 0;
		if ((*p)->cmnd_a >= (*p)->cmnd_b)
		{
			(*p)->rrb = 0;
			(*p)->rrr = (*p)->cmnd_b;
			(*p)->rra = (*p)->cmnd_a - (*p)->cmnd_b;
			(*p)->tot_cmnds = (*p)->cmnd_a;
		}
		else if ((*p)->cmnd_a < (*p)->cmnd_b)
		{
			(*p)->rra = 0;
			(*p)->rrr = (*p)->cmnd_b;
			(*p)->rrb = (*p)->cmnd_b - (*p)->cmnd_a;
			(*p)->tot_cmnds = (*p)->cmnd_b;
		}
	}
	else if (((*p)->rb && (*p)->rra) || ((*p)->rrb && (*p)->ra))
		(*p)->tot_cmnds = (*p)->cmnd_a + (*p)->cmnd_b;

	if (((*p)->prev_cmnds == -1 && (*p)->p_ra == -1) ||
		(*p)->tot_cmnds < (*p)->prev_cmnds)
	{
		(*p)->prev_cmnds = (*p)->tot_cmnds;
		(*p)->prev_nb = (*p)->nb;
		(*p)->p_ra = (*p)->ra;
		(*p)->p_rra = (*p)->rra;
		(*p)->p_rb = (*p)->rb;
		(*p)->p_rrb = (*p)->rrb;
		(*p)->p_rr = (*p)->rr;
		(*p)->p_rrr = (*p)->rrr;
	}
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
	turn_end(a);
	(*a) ? (end = (*a)->nb) : 0;
	turn_begin(a);
	while ((*a) && (*a)->next) //поиск начала стека
	{
		if (((*a)->prev && (*a)->nb < (*a)->prev->nb) || (!(*a)->prev && end > (*a)->nb))
		{
			start = (*a)->nb;
			break;
		}
		(*a) = (*a)->next;
		cnt++;
	}
	while ((*a)) //куда вставить число
	{
		if (((*a)->nb > (*b)->nb && (*a)->prev->nb < (*b)->nb) ||
			((*a)->nb > (*b)->nb && !(*a)->prev && end < (*b)->nb))
		{
			break;
		}
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
	turn_begin(a);
}

void 	cnt_cmnds_b(t_stack **b, t_instr *in, t_sort **p)
{
	int 	tmp;
	int 	cnt;

	cnt = 0;
	(*b) ? tmp = (*b)->nb : 0;
	(*b) ? (*p)->nb = (*b)->nb : 0;
	turn_begin(b);
	(*p)->rb = 0;
	(*p)->rrb = 0;
	while ((*b) && (*b)->nb != tmp)
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
}

void	new_algo(t_stack **a, t_stack **b, t_instr *in, t_sort **p)
{
	(*p)->tot_cmnds = -1;
	(*p)->p_rr = -1;
	(*p)->p_rrr = -1;
	(*p)->p_ra = -1;
	(*p)->p_rb = -1;
	(*p)->p_rrb = -1;
	(*p)->p_rra = -1;
	(*p)->prev_nb = (*b)->nb;
	while ((*b) && (*b)->next)
	{
		cnt_cmnds_b(b, in, p);
		cnt_cmnds_a(a, b, in, p);
		total_cmnds(p);
		(*b) = (*b)->next;
	}
	(*b) = (*b)->next;
	cnt_cmnds_b(b, in, p);
	cnt_cmnds_a(a, b, in, p);
	total_cmnds(p);
	apply_cmnds(a, b, in, p);
}

void 	create_min(t_stack **a, t_sort **p)
{
	(*a) ? (*p)->min = (*a)->nb : 0;
	while ((*a) && (*a)->next)
	{
		((*a)->nb < (*p)->min) ? ((*p)->min = (*a)->nb) : 0;
		(*a) = (*a)->next;
	}
	(((*a) && (*a)->nb) < (*p)->min) ? ((*p)->min = (*a)->nb) : 0;
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
		rra(a, in);
		return ;
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
}

void 	push_to_a(t_stack **a, t_stack **b, t_instr *in)
{
	t_sort		*p;

	if (!(p = (t_sort *)malloc(sizeof(t_sort))))
		return ;
	while ((*in).size_a != 3) //push everything except 3 nbrs to 'b'
		pb(a, b, in);
	alg_three(in, a); //sort three numbers
	new_algo(a, b, in, &p);
	finish_stack(a, in, &p);
}