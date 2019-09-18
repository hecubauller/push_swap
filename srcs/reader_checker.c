/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 20:26:13 by huller            #+#    #+#             */
/*   Updated: 2019/09/17 20:52:26 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int 	check_valid_instr(char **line, t_instr *in)
{
	if (!ft_strcmp(*line, "sa"))
		in->inst |= SA;
	else if (!ft_strcmp(*line, "sb"))
		in->inst |= SB;
	else if (!ft_strcmp(*line, "ss"))
		in->inst |= SS;
	else if (!ft_strcmp(*line, "ra"))
		in->inst |= RA;
	else if (!ft_strcmp(*line, "rb"))
		in->inst |= RB;
	else if (!ft_strcmp(*line, "rr"))
		in->inst |= RR;
	else if (!ft_strcmp(*line, "rra"))
		in->inst |= RRA;
	else if (!ft_strcmp(*line, "rrb"))
		in->inst |= RRB;
	else if (!ft_strcmp(*line, "rrr"))
		in->inst |= RRR;
	else if (!ft_strcmp(*line, "pa"))
		in->inst |= PA;
	else if (!ft_strcmp(*line, "pb"))
		in->inst |= PB;
	else
		return (ERROR);
	return (SUCCESS);
}

void	add_nbrs(int tmp, t_stack **a, char **argv, t_instr *in)
{
	t_stack		*tmp2;
	t_stack		*begin;
	char 		*tmp_str;

	begin = (*a);
	while (argv[tmp])
	{
		tmp_str = argv[tmp];
		(*a)->nb = ft_atoi(argv[tmp]);
		if ((int_checker(tmp_str, (*a)->nb) == ERROR))
		{
			free_lsts(a);
			put_result(ERROR);
			exit (FAIL);
		}
		in->size_a++;
		tmp2 = (*a);
		if (argv[tmp + 1])
		{
			if (!((*a)->next = (t_stack *)malloc(sizeof(t_stack))))
				exit(FAIL);
			(*a) = (*a)->next;
			(*a)->prev = tmp2;
			(*a)->nb = 0;
		}
		else
			(*a)->next = NULL;
		++tmp;
	}
	if (in->size_a == 1)
	{
		free_lsts(a);
		put_result(ERROR);
		exit (FAIL);
	}
	(*a) = begin;
}

int		check_dubl(char **argv, int tmp)
{
	int 	cnt;
	int 	cnst;
	int 	len;

	cnst = tmp;
	len = 0;
	while (argv[tmp])
	{
		len++;
		tmp++;
	}
	tmp = cnst;
	while (argv[tmp])
	{
		cnt = cnst;
		while (cnt <= len && argv[cnt])
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

void	newlist_ch(t_stack **a)
{
	if (!((*a) = (t_stack *)malloc(sizeof(t_stack))))
		exit(FAIL);
	(*a)->nb = 0;
	(*a)->prev = NULL;
}

int		reader_argv(t_stack **a, t_instr **in, char **argv)
{
	int i;
	int cnt;
	int tmp;

	i = 0;
	cnt = 0;
	tmp = (*in)->split ? 0 : 1;
	if ((*in)->viz == 2)
	{
		++cnt;
		++tmp;
	}
	(*in)->size_a = 0;
	(*in)->size_b = 0;
	while (argv[++cnt])
	{
		i = 0;
		while (argv[cnt][i] && ((argv[cnt][i] >= '0' && argv[cnt][i] <= '9') ||
				argv[cnt][i] == '-' || argv[cnt][i] == '+'))
			++i;
		if (argv[cnt][i])
			return (ERROR);
	}
	if ((check_dubl(argv, tmp) == ERROR))
		return (ERROR);
	newlist_ch(a);
	add_nbrs(tmp, a, argv, *in);
	return (SUCCESS);
}