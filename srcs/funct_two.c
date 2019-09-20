/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:08:24 by huller            #+#    #+#             */
/*   Updated: 2019/09/20 20:13:09 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	initialize(t_stack **b, t_sort **p)
{
	(*p)->tot_cmnds = -1;
	(*p)->p_rr = -1;
	(*p)->p_rrr = -1;
	(*p)->p_ra = -1;
	(*p)->p_rb = -1;
	(*p)->p_rrb = -1;
	(*p)->p_rra = -1;
	(*p)->prev_nb = (*b)->nb;
}

void	compare_comands(t_sort **p)
{
	if ((*p)->tot_cmnds < (*p)->prev_cmnds)
	{
		(*p)->p_rra = (*p)->rra;
		(*p)->p_ra = (*p)->ra;
		(*p)->p_rrb = (*p)->rrb;
		(*p)->p_rb = (*p)->rb;
		(*p)->p_rr = (*p)->rr;
		(*p)->p_rrr = (*p)->rrr;
		(*p)->prev_nb = (*p)->nb;
		(*p)->prev_cmnds = (*p)->tot_cmnds;
	}
}

void	cmnds_two(t_sort **p)
{
	if ((*p)->ra == (*p)->rb)
	{
		(*p)->tot_cmnds = (*p)->ra;
		(*p)->rr = (*p)->ra;
		(*p)->ra = 0;
		(*p)->rb = 0;
	}
	else if ((*p)->ra > (*p)->rb)
	{
		(*p)->rr = (*p)->rb;
		(*p)->ra = (*p)->ra - (*p)->rb;
		(*p)->tot_cmnds = (*p)->cmnd_a;
		(*p)->rb = 0;
	}
	else if ((*p)->ra < (*p)->rb)
	{
		(*p)->rr = (*p)->ra;
		(*p)->rb = (*p)->rb - (*p)->ra;
		(*p)->ra = 0;
		(*p)->tot_cmnds = (*p)->cmnd_b;
	}
}

void	cmnd_three(t_sort **p)
{
	if ((*p)->rra == (*p)->rrb)
	{
		(*p)->tot_cmnds = (*p)->rra;
		(*p)->rrr = (*p)->rra;
		(*p)->rra = 0;
		(*p)->rrb = 0;
	}
	else if ((*p)->rra > (*p)->rrb)
	{
		(*p)->rrr = (*p)->rrb;
		(*p)->rra = (*p)->rra - (*p)->rrb;
		(*p)->rrb = 0;
		(*p)->tot_cmnds = (*p)->cmnd_a;
	}
	else if ((*p)->rra < (*p)->rrb)
	{
		(*p)->rrr = (*p)->rra;
		(*p)->rrb = (*p)->rrb - (*p)->rra;
		(*p)->rra = 0;
		(*p)->tot_cmnds = (*p)->cmnd_b;
	}
}

void	total_cmnds(t_sort **p)
{
	(*p)->tot_cmnds = 0;
	if ((*p)->rb && (*p)->ra)
		cmnds_two(p);
	else if ((*p)->rrb && (*p)->rra)
		cmnd_three(p);
	else if (((*p)->rb && (*p)->rra) || ((*p)->rrb || (*p)->ra ||
	(*p)->ra || (*p)->rra || (*p)->rb || (*p)->rrb))
		(*p)->tot_cmnds = (*p)->cmnd_a + (*p)->cmnd_b;
	if ((*p)->p_ra == -1)
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
