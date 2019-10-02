/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:21:30 by huller            #+#    #+#             */
/*   Updated: 2019/09/25 09:44:41 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

bool	get_boolean_two(t_stack **a, t_stack **b, t_sort **p)
{
	return (!(*a)->prev && (*a)->nb == (*p)->max && (*b)->nb > (*p)->max)
	|| ((*a)->nb < (*b)->nb && (*a)->nb == (*p)->max);
}

bool	get_boolean(t_stack **a, t_stack **b, t_sort **p)
{
	return ((*a)->prev && (*a)->nb > (*b)->nb && (*a)->prev->nb < (*b)->nb)
	|| ((*a)->nb > (*b)->nb && !(*a)->prev && (*p)->end < (*b)->nb)
	|| ((*a)->nb > (*b)->nb && (*a)->nb == (*p)->start);
}

int		else_cmd(t_stack **a)
{
	turn_begin(a);
	return (0);
}

void	if_cmnd_a(t_stack **a, t_instr *in, t_sort **p, int cnt)
{
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
