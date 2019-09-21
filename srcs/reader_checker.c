/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 20:26:13 by huller            #+#    #+#             */
/*   Updated: 2019/09/21 03:38:31 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	add_nbrs_if(t_stack **a, t_stack *tmp2)
{
	if (!((*a)->next = (t_stack *)malloc(sizeof(t_stack))))
		exit(FAIL);
	(*a) = (*a)->next;
	(*a)->prev = tmp2;
	(*a)->nb = 0;
	(*a)->next = NULL;
}

int		add_nbrs(int tmp, t_stack **a, char **argv, t_instr *in)
{
	t_stack		*tmp2;
	char		*tmp_str;

	newlist_ch(a);
	while (argv[tmp])
	{
		tmp_str = argv[tmp];
		(*a)->nb = ft_atoi(argv[tmp]);
		if (int_checker(tmp_str, (*a)->nb) == ERROR)
			return (get_free(a));
		in->size_a++;
		tmp2 = (*a);
		if (argv[tmp + 1])
			add_nbrs_if(a, tmp2);
		else
			(*a)->next = NULL;
		++tmp;
	}
	if (in->size_a == 1)
		return (get_free(a));
	turn_begin(a);
	return (SUCCESS);
}

int		check_dubl(char **argv, int tmp)
{
	int			cnt;
	int			cnst;
	int			len;

	cnst = tmp;
	len = 0;
	ch_dbl_cycle(argv, &len, &tmp);
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
	(*a)->next = NULL;
}

int		reader_argv(t_stack **a, t_instr **in, char **argv)
{
	int i;
	int cnt;
	int tmp;

	i = 0;
	cnt = ((*in)->split) ? 0 : 1;
	tmp = ((*in)->split) ? 0 : 1;
	if ((*in)->viz == 2)
	{
		++cnt;
		++tmp;
	}
	(*in)->size_a = 0;
	(*in)->size_b = 0;
	if (!*argv)
		return (ERROR);
	if (reader_cycle(argv, &i, &cnt, in) == ERROR)
		return (ERROR);
	if ((check_dubl(argv, tmp) == ERROR))
		return (ERROR);
	if ((add_nbrs(tmp, a, argv, *in)) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
