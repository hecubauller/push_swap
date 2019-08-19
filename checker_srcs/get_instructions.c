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

void 	ft_int_checker(char *tmp, int nb)
{
	char	*res_nb;
	int		pos;
	int 	neg;

	res_nb = ft_itoa(nb);
	if (ft_strcmp(tmp, res_nb))
	{
		pos = 0;
		if (*res_nb == '+')
			pos = 1;
		if (*res_nb == '-')
			neg = -1;
		if (pos && ((++*res_nb == '-') || *res_nb == '+'))
		{
			ft_printf("Error\n");
			exit(0);
		}
		while (*res_nb == '0')
			res_nb++;
	}
}

void	ft_put_result(int res)
{
	if (res == ERROR)
		ft_putstr("Error\n");
	if (res == OK)
		ft_putstr("OK\n");
	if (res == KO)
		ft_putstr("KO\n");
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