/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 05:13:38 by huller            #+#    #+#             */
/*   Updated: 2019/08/27 05:56:16 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int 	ft_alg_three(t_instr *in, t_stack **a, t_stack **b)
{
	if ((*a)->nb > (*a)->next->nb && (*a)->next->next->nb > (*a)->next->nb &&
		(*a)->nb < (*a)->next->next->nb)
		ft_sa(a, in);
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb)
	{
		ft_sa(a, in);
		ft_rra(a, in);
	}
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb < (*a)->next->next->nb)
		ft_ra(a, in);
	else if ((*a)->nb < (*a)->next->nb && (*a)->next->next->nb < (*a)->next->nb)
	{
		ft_sa(a, in);
		ft_rra(a, in);
	}
	return (SUCCESS);
}

int 	ft_algorithm(t_instr *in, t_stack **a, t_stack **b)
{
	if ((*in).size_a == 3)
	{
		ft_alg_three(in, a, b);
		return (SUCCESS);
	}
	else if ()
	return (ERROR);
}