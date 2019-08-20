/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 05:41:06 by huller            #+#    #+#             */
/*   Updated: 2019/08/20 10:17:10 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_includes/checker.h"

void	ft_rr(t_stack **a, t_stack **b)
{
	int 		tmp;
	t_stack		*tmp_s;
	t_stack		*tmp_s2;

	tmp = 0;
	if ((*a) && (*a)->next)
	{
		tmp_s = (*a);
		(*a)->next->prev = NULL;
		tmp_s2 = (*a)->next;
		while ((*a)->next)
			(*a) = (*a)->next;
		(*a)->next = tmp_s;
		(*a)->next->next = NULL;
		(*a)->next->prev = tmp_s2;
		while ((*a)->prev)
			(*a) = (*a)->prev;
		while ((*a)->next)
		{
			ft_printf("%d ", (*a)->nb);
			(*a) = (*a)->next;
		}
		ft_printf("%d ", (*a)->nb);
		while ((*a)->prev)
			(*a) = (*a)->prev;
	}
	if ((*b) && (*b)->next)
	{
		tmp_s = (*b);
		(*b)->next->prev = NULL;
		tmp_s2 = (*b)->next;
		while ((*b)->next)
			(*b) = (*b)->next;
		(*b)->next = tmp_s;
		(*b)->next->next = NULL;
		(*b)->next->prev = tmp_s2;
		while ((*b)->prev)
			(*b) = (*b)->prev;
		while ((*b)->next)
		{
			ft_printf("%d ", (*b)->nb);
			(*b) = (*b)->next;
		}
		ft_printf("%d ", (*b)->nb);
		while ((*b)->prev)
			(*b) = (*b)->prev;
	}
}

void	ft_ra(t_stack **x)
{
	int 		tmp;
	t_stack		*tmp_s;
	t_stack		*tmp_s2;

	tmp = 0;
	if ((*x) && (*x)->next)
	{
		tmp_s = (*x);
		(*x)->next->prev = NULL;
		tmp_s2 = (*x)->next;
		while ((*x)->next)
			(*x) = (*x)->next;
		(*x)->next = tmp_s;
		(*x)->next->next = NULL;
		(*x)->next->prev = tmp_s2;
		while ((*x)->prev)
			(*x) = (*x)->prev;
		while ((*x)->next)
		{
			ft_printf("%d ", (*x)->nb);
			(*x) = (*x)->next;
		}
		ft_printf("%d ", (*x)->nb);
		while ((*x)->prev)
			(*x) = (*x)->prev;
	}

}

void	ft_ss(t_stack **a, t_stack **b)
{
	int 		tmp;

	tmp = 0;
	if (*a && *b && (*a)->next && (*b)->next)
	{
		if ((*a) && (*a)->next)
		{
			tmp = (*a)->nb;
			(*a)->nb = (*a)->next->nb;
			(*a)->next->nb = tmp;
		}
		if ((*b) && (*b)->next)
		{
			tmp = (*b)->nb;
			(*b)->nb = (*b)->next->nb;
			(*b)->next->nb = tmp;
		}
		while ((*a)->next)
		{
			ft_printf("%d ", (*a)->nb);
			(*a) = (*a)->next;
		}
		ft_printf("%d ", (*a)->nb);
		while ((*a)->prev)
			(*a) = (*a)->prev;
	}
}

void	ft_sa(t_stack **x)
{
	int 		tmp;

	tmp = 0;
	if ((*x) && (*x)->next)
	{
		tmp = (*x)->nb;
		(*x)->nb = (*x)->next->nb;
		(*x)->next->nb = tmp;
	}
	while ((*x)->next)
	{
		ft_printf("%d ", (*x)->nb);
		(*x) = (*x)->next;
	}
	ft_printf("%d ", (*x)->nb);
	while ((*x)->prev)
		(*x) = (*x)->prev;
}

void	ft_appl_instr(char **line, t_instr *in, t_stack **a, t_stack **b)
{
	if (in->inst & SA)
		ft_sa(a);
	if (in->inst & SB)
		ft_sa(b);
	if (in->inst & SS)
		ft_ss(a, b);
	if (in->inst & RA)
		ft_ra(a);
	if (in->inst & RB)
		ft_ra(b);
	if (in->inst & RR)
		ft_rr(a, b);
	if (in->inst & RRA)
		ft_rra(a);
	if (in->inst & RRB)
		ft_rra(b);
	if (in->inst & RRR)
		ft_rrr(a, b);
	if (in->inst & PA)
		ft_pa(a, b);
	if (in->inst & PB)
		ft_pb(a, b);
}