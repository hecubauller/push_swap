/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 20:26:13 by huller            #+#    #+#             */
/*   Updated: 2019/08/19 01:35:21 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_includes/checker.h"

int 	ft_check_valid_instr(char **line)
{
	if (ft_strcmp(*line, "sa") && ft_strcmp(*line, "sb") &&
		ft_strcmp(*line, "ss") && ft_strcmp(*line, "ra") &&
		ft_strcmp(*line, "rb") && ft_strcmp(*line, "rr") &&
		ft_strcmp(*line, "rra") && ft_strcmp(*line, "rrb") &&
		ft_strcmp(*line, "rrr") && ft_strcmp(*line, "pa") &&
		ft_strcmp(*line, "pb"))
		return (ERROR);
}

void	ft_add_nbrs(int tmp, t_stack **a, char **argv)
{
	t_stack		*tmp2;
	t_stack		*begin;
	int 		s;

	begin = (*a);
	s = 0;
	while (argv[tmp])
	{
		(*a)->nb = ft_atoi(argv[tmp]);
		tmp2 = (*a);
		if (argv[tmp + 1])
		{
			if (!((*a)->next = (t_stack *) malloc(sizeof(t_stack))))
				exit(FAIL);
			(*a) = (*a)->next;
			(*a)->prev = tmp2;
			(*a)->nb = 0;
		}
		else
			(*a)->next = NULL;
		++tmp;
	}
	(*a) = begin;
	while (*a)
	{
		ft_printf("%d ", (*a)->nb);
		(*a) = (*a)->next;
	}
	(*a) = begin;
}

int		ft_check_dubl(char **argv, int tmp)
{
	int 	cnt;
	int 	cnst;

	cnst = tmp;
	while (argv[tmp])
	{
		cnt = cnst;
		while (argv[cnt])
		{
			cnt == tmp ? ++cnt : 0;
			if (argv[cnt])
			{
				if (!(ft_strcmp(argv[tmp], argv[cnt])))
					return (ERROR);
			}
			++cnt;
		}
		++tmp;
	}
	return (SUCCESS);
}

void	ft_newlist_ch(t_stack **a)
{
	if (!((*a) = (t_stack *)malloc(sizeof(t_stack))))
		exit(FAIL);
	if (!((*a)->next = (t_stack *)malloc(sizeof(t_stack))))
		exit (FAIL);
	(*a)->nb = 0;
	(*a)->size = 0;
	(*a)->prev = NULL;
}

int		ft_reader_argv(t_stack **a, t_instr **in, char **argv, t_stack **b)
{
	int 		i;
	int 		cnt;
	int 		tmp;
	char 		*chckr;

	i = 0;
	cnt = 0;
	tmp = 1;
	while (argv[++cnt])
	{
		i = 0;
		while (argv[cnt][i] && ((argv[cnt][i] >= '0' && argv[cnt][i] <= '9') ||
				argv[cnt][i] == '-' || argv[cnt][i] == '+'))
			++i;
		if (argv[cnt][i])
			return (ERROR);
	}
	if ((ft_check_dubl(argv, tmp) == ERROR))
		return (ERROR);
	ft_newlist_ch(a);
	ft_newlist_ch(b);
	ft_add_nbrs(tmp, a, argv);
	return (SUCCESS);
}