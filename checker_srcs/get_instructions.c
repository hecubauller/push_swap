/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 01:03:23 by huller            #+#    #+#             */
/*   Updated: 2019/08/19 01:45:14 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_includes/checker.h"

void	ft_put_result(int res)
{
	if (res == SUCCESS)
		ft_printf("\nSUCCESS\n");
	if (res == ERROR)
		ft_putstr("Error");
	if (res == OK)
		ft_putstr("OK");
	if (res == KO)
		ft_putstr("KO");
}

int 	ft_check_output(t_stack **a, t_stack **b)
{
	if (!(*b)->size)
	{
		while ((*a)->prev)
			(*a) = (*a)->prev;
		while ((*a)->next)
		{
			if ((*a)->nb < (*a)->next->nb)
				(*a) = (*a)->next;
			else
				return (KO);
		}
		return (OK);
	}
	return (KO);
}

int		ft_get_input()
{
	char 		*line;

	while (get_next_line(0, &line))
	{
		if ((ft_check_valid_instr(&line)) == ERROR)
			return (ERROR);
	}
}