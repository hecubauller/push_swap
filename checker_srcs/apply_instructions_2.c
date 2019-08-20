/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instructions_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 06:28:58 by huller            #+#    #+#             */
/*   Updated: 2019/08/20 08:16:07 by huller           ###   ########.fr       */
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
		(*x)->prev = NULL;
		tmp_s2 = (*x);
		(*x)->prev = tmp_s2;
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

}

void	ft_pa(t_stack **a, t_stack **b)
{

}

void	ft_pb(t_stack **a, t_stack **b)
{

}