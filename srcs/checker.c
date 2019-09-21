/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:13:58 by huller            #+#    #+#             */
/*   Updated: 2019/09/21 04:30:34 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	in_check(t_instr *in, t_stack **a, t_stack **b)
{
	(*a) = NULL;
	(*b) = NULL;
	in->split = 0;
	in->inst = 0;
	in->viz = 0;
	in->push_swap = 0;
	in->size_b = 0;
}

int		geint_two(t_stack **a, t_instr *in, char **av_str)
{
	int i;

	i = -1;
	newlist_ch(a);
	(*a) ? (free_lsts(a)) : 0;
	ft_putstr("Error\n");
	while (av_str && av_str[++i])
		free(av_str[i]);
	av_str ? free(av_str) : 0;
	free(in);
	return (0);
}

int		check_res(t_stack **a, t_stack **b, t_instr *in, char **av_str)
{
	int i;

	i = -1;
	ft_putstr("Error\n");
	(*a) ? (free_lsts(a)) : 0;
	newlist_ch(b);
	(*b) ? (free_lsts(b)) : 0;
	free(in);
	while (av_str && av_str[++i])
		free(av_str[i]);
	av_str ? free(av_str) : 0;
	return (0);
}

void	freee(t_stack **a, t_stack **b, t_instr *in, char **av_str)
{
	int	i;

	i = -1;
	free_lsts(a);
	free_lsts(b);
	free(in);
	while (av_str && av_str[++i])
		free(av_str[i]);
	av_str ? free(av_str) : 0;
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_instr		*in;
	char		**av_str;

	av_str = NULL;
	if (!(in = (t_instr *)malloc(sizeof(t_instr))))
		return (ERROR);
	in_check(in, &a, &b);
	if (argc == 1)
	{
		free(in);
		return (0);
	}
	av_str = getstring(argc, argv, in);
	if ((reader_argv(&a, &in, (av_str ? av_str : argv)) == ERROR))
		return (geint_two(&a, in, av_str));
	if ((get_input(in, &a, &b) == ERROR))
		return (check_res(&a, &b, in, av_str));
	if (check_output(&a, in) == OK)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	freee(&a, &b, in, av_str);
	return (0);
}
