/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 23:46:24 by huller            #+#    #+#             */
/*   Updated: 2019/09/20 18:50:50 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

char	**getstring(int argc, char **argv, t_instr *in)
{
	char **av_str;

	av_str = NULL;
	if (!(ft_strcmp(argv[1], "-v")))
		in->viz = 1;
	if (argc == 2 && !in->viz && ft_strchr(argv[1], ' '))
	{
		av_str = ft_strsplit(argv[1], ' ');
		in->split++;
	}
	else if (argc == 3 && in->viz && ft_strchr(argv[2], ' '))
	{
		av_str = ft_strsplit(argv[2], ' ');
		in->split += 2;
	}
	else if (in->viz && argc > 3)
		in->viz = 2;
	return (av_str);
}

int		int_ch_2(t_ch **j, char *tmp)
{
	(*j)->pos = 0;
	if (tmp[(*j)->i] == '+')
		(*j)->pos = 1;
	if (tmp[(*j)->i] == '-')
		(*j)->neg = -1;
	if ((*j)->pos && ((tmp[++(*j)->i] == '-') || tmp[(*j)->i] == '+'))
		return (ERROR);
	while (tmp[(*j)->i] == '0')
		(*j)->i++;
	while (tmp[(*j)->i] >= '0' && tmp[(*j)->i] <= '9')
	{
		(*j)->cmp_str[++(*j)->k] = tmp[(*j)->i];
		(*j)->i++;
	}
	return (SUCCESS);
}

int		reader_cycle(char **argv, int *i, int *cnt, t_instr **in)
{
	while (argv[*cnt])
	{
		(*i) = 0;
		while (argv[*cnt][*i] &&
				((argv[*cnt][*i] >= '0' && argv[*cnt][*i] <= '9') ||
				argv[*cnt][*i] == '-' || argv[*cnt][*i] == '+'))
			++(*i);
		if (argv[*cnt][*i] || ((*cnt) == 1 && !(*in)->split && (*i) == 0))
			return (ERROR);
		(*cnt)++;
	}
	return (SUCCESS);
}

int		check_valid_instr(char **line, t_instr *in)
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
