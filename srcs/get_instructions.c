/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 01:03:23 by huller            #+#    #+#             */
/*   Updated: 2019/08/26 05:57:24 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_free_lsts(t_stack **a)
{
	t_stack *tmp;

	while ((*a) && (*a)->next)
	{
		tmp = *a;
		(*a) = (*a)->next;
		free(tmp);
	}
	free(*a);
}

int 	ft_int_checker(char *tmp, int nb)
{
	char	*res_nb;
	int 	i;
	int 	k;
	char 	*cmp_str;
	int		pos;
	int 	neg;

	i = 0;
	k = -1;
	res_nb = ft_itoa(nb);
	if (!(cmp_str = (char *)malloc(sizeof(char) * ft_strlen(tmp))))
		exit(ERROR);
	if (ft_strcmp(tmp, res_nb))
	{
		pos = 0;
		if (tmp[i] == '+')
			pos = 1;
		if (tmp[i] == '-')
			neg = -1;
		if (pos && ((tmp[++i] == '-') || tmp[i] == '+'))
			ft_put_result(ERROR);
		while (tmp[i] == '0')
			i++;
		while (tmp[i] >= '0' && tmp[i] <= '9')
		{
			cmp_str[++k] = tmp[i];
			i++;
		}
		if (ft_strcmp(res_nb, cmp_str))
			return (ERROR);
	}
	free(res_nb);
	free(cmp_str);
	return (SUCCESS);
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

int 	ft_check_output(t_stack **a, t_instr *in)
{
	if (!(in->size_b))
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

int		ft_get_input(t_instr *in, t_stack **a, t_stack **b)
{
	char 		*line;

	(*in).viz ? ft_vizualize_init(a, b, in) : 0;
	while (get_next_line(0, &line))
	{
		if ((ft_check_valid_instr(&line, in)) == ERROR)
		{
			ft_free_lsts(a);
			ft_free_lsts(b);
			ft_put_result(ERROR);
			exit (0);
		}
		ft_appl_instr(in, a, b);
		free(line);
	}
	free(line);
	return (SUCCESS);
}