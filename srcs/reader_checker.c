/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 20:26:13 by huller            #+#    #+#             */
/*   Updated: 2019/09/25 10:40:08 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		check_dubl(int *arr, t_instr **in)
{
	int			i;
	int			end;
	int			cnt;
	int			cnst;
	int			len;

	i = 0;
	cnst = 0;
	end = (*in)->size_a;
	len = (*in)->size_a;
	while (--len)
	{
		cnt = 0;
		cnst = arr[i];
		while (cnt <= end)
		{
			cnt == i ? ++i : 0;
			if (i < end && arr[i] == cnst)
				return (ERROR);
			++cnt;
		}
		++i;
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

int		*create_arr(t_stack **a, t_instr **in)
{
	int i;
	int *arr;

	i = -1;
	if (!(arr = (int *)malloc(sizeof(int) * (*in)->size_a)))
		exit(-1);
	turn_begin(a);
	while ((*a) && (*a)->next)
	{
		arr[++i] = (*a)->nb;
		(*a) = (*a)->next;
	}
	(*a) ? arr[++i] = (*a)->nb : 0;
	turn_begin(a);
	return (arr);
}

void	init_read(t_instr **in, int *i, int *cnt, int *tmp)
{
	(*i) = 0;
	(*tmp) = 0;
	(*cnt) = ((*in)->split) ? 0 : 1;
	(*tmp) = ((*in)->split) ? 0 : 1;
	if ((*in)->viz == 2)
	{
		++(*cnt);
		++(*tmp);
	}
	(*in)->size_a = 0;
	(*in)->size_b = 0;
}

int		reader_argv(t_stack **a, t_instr **in, char **argv)
{
	int i;
	int cnt;
	int tmp;
	int *arr;

	init_read(in, &i, &cnt, &tmp);
	if (!*argv)
		return (ERROR);
	if (reader_cycle(argv, &i, &cnt, in) == ERROR)
		return (ERROR);
	if ((add_nbrs(tmp, a, argv, *in)) == ERROR)
		return (ERROR);
	arr = create_arr(a, in);
	if ((check_dubl(arr, in) == ERROR))
	{
		free(arr);
		return (ERROR);
	}
	free(arr);
	return (SUCCESS);
}
