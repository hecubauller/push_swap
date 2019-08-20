/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instructions_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 06:28:58 by huller            #+#    #+#             */
/*   Updated: 2019/08/20 10:30:04 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_includes/checker.h"

void	ft_rra(t_stack **x)
{
	int 		tmp;
	t_stack		*tmp_s;
	t_stack		*tmp_s2;

	tmp = 0;
	if ((*x) && (*x)->next)
	{
		tmp_s = (*x);
		while ((*x)->next)
			(*x) = (*x)->next;
		(*x)->next = tmp_s;
		(*x)->prev->next = NULL;
		(*x)->prev = NULL;
		tmp_s2 = (*x);
		tmp_s->prev = tmp_s2;
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

void	ft_rrr(t_stack **a, t_stack **b)
{
	int 		tmp;
	t_stack		*tmp_s;
	t_stack		*tmp_s2;

	tmp = 0;
	if ((*a) && (*a)->next) //оптимизировать: свопать нб, а не ссылки
	{
		tmp_s = (*a);
		while ((*a)->next)
			(*a) = (*a)->next;
		(*a)->next = tmp_s;
		(*a)->prev->next = NULL;
		(*a)->prev = NULL;
		tmp_s2 = (*a);
		tmp_s->prev = tmp_s2;
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
		while ((*b)->next)
			(*b) = (*b)->next;
		(*b)->next = tmp_s;
		(*b)->prev->next = NULL;
		(*b)->prev = NULL;
		tmp_s2 = (*b);
		tmp_s->prev = tmp_s2;
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

void	ft_pa(t_stack **a, t_stack **b)
{
	int 		tmp;

	tmp = 0;
	if (*b)
	{
		(*a)->prev = (*b);
		(*b)->next = (*a);
		(*b)->prev = NULL; //хуйня какая-то
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

void	ft_pb(t_stack **a, t_stack **b)
{

}