/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_act.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 03:37:19 by huller            #+#    #+#             */
/*   Updated: 2019/09/25 10:38:40 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		add_nbrs(int tmp, t_stack **a, char **argv, t_instr *in)
{
	t_stack		*tmp2;
	char		*tmp_str;

	tmp_str = NULL;
	newlist_ch(a);
	while (argv[tmp])
	{
		tmp_str = argv[tmp];
		(*a)->nb = ft_atoi(argv[tmp]);
		if (int_checker(tmp_str, (*a)->nb) == ERROR)
			return (ERROR);
		in->size_a++;
		tmp2 = (*a);
		if (argv[tmp + 1])
			add_nbrs_if(a, tmp2);
		else
			(*a)->next = NULL;
		++tmp;
	}
	if (in->size_a == 1)
		return (ERROR);
	turn_begin(a);
	return (SUCCESS);
}

void	add_nbrs_if(t_stack **a, t_stack *tmp2)
{
	if (!((*a)->next = (t_stack *)malloc(sizeof(t_stack))))
		exit(FAIL);
	(*a) = (*a)->next;
	(*a)->prev = tmp2;
	(*a)->nb = 0;
	(*a)->next = NULL;
}

int		int_checker(char *tmp, int nb)
{
	int		i;
	int		neg;
	int		pos;
	char	*res_nb;
	char	*cmp_str;

	i = 0;
	pos = 0;
	neg = 0;
	res_nb = ft_itoa(nb);
	if (!(cmp_str = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + 1))))
		exit(ERROR);
	if (ft_strcmp(tmp, res_nb))
	{
		sign_nb(tmp, i, &neg, &pos);
		if (pos && ((tmp[++i] == '-') || tmp[i] == '+'))
			return (ret_fr(res_nb, cmp_str));
		cycles_int(tmp, &i, cmp_str, neg);
		if (ft_strcmp(res_nb, cmp_str))
			return (ret_fr(res_nb, cmp_str));
	}
	free(res_nb);
	free(cmp_str);
	return (SUCCESS);
}

int		get_input(t_instr *in, t_stack **a, t_stack **b)
{
	char	*line;

	(*in).viz ? vizualize_init(a, b, in) : 0;
	while (get_next_line(0, &line))
	{
		if ((check_valid_instr(&line, in)) == ERROR)
		{
			(line) ? free(line) : 0;
			return (ERROR);
		}
		appl_instr(in, a, b);
		(line) ? free(line) : 0;
	}
	(line) ? free(line) : 0;
	return (SUCCESS);
}
