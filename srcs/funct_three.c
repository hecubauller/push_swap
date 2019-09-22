/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:13:43 by huller            #+#    #+#             */
/*   Updated: 2019/09/21 19:38:03 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	cnt_cmnds_b(t_stack **b, t_instr *in, t_sort **p)
{
	int		tmp;
	int		cnt;

	cnt = 0;
	tmp = cmnd_b_two(b, p);
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

int		search_beginning(t_stack **a, int end)
{
	int		start;

	start = 0;
	while ((*a) && (*a)->next)
	{
		if (((*a)->prev && (*a)->nb < (*a)->prev->nb) ||
			(!(*a)->prev && end > (*a)->nb))
		{
			start = (*a)->nb;
			break ;
		}
		(*a) = (*a)->next;
	}
	start = (*a)->nb;
	return (start);
}

void	create_max(t_stack **a, t_sort **p)
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

int		cmnd_b_two(t_stack **b, t_sort **p)
{
	int tmp;

	tmp = 0;
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
	return (tmp);
}

void	innn(t_stack **a, t_sort **p)
{
	(*p)->ra = 0;
	(*p)->rra = 0;
	(*p)->cmnd_a = 0;
	create_max(a, p);
	turn_end(a);
	(*a) ? (((*p)->end) = (*a)->nb) : 0;
	turn_begin(a);
	((*p)->start) = search_beginning(a, ((*p)->end));
	turn_begin(a);
}
