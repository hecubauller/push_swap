/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 09:12:59 by huller            #+#    #+#             */
/*   Updated: 2019/09/02 13:40:57 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_create_maxs(t_alg **q, t_stack **a, t_instr **in)
{
	int		cnt;
	int 	i;
	int 	*ar;
	int 	prev_max;
	int 	cycle;

	cnt = -1;
	i = -1;
	cycle = 0;
	prev_max = (*q)->min;
	if (!(ar = (int *)malloc(sizeof(int) * (*in)->size_a)))
		return ;
	if (!((*q)->ar_of_mx = (int *)malloc(sizeof(int) * (*q)->chunks)))
		return ;
	ft_create_array(ar, a, q, in);
	ft_quick_sort(ar, 0, (*in)->size_a);
	i = -1;
	ft_putstr(GRN"sorted array: "RESET);
	while (++i != 5 )
		ft_printf("%d ", ar[i]);
	ft_putstr("\n");
	i = -1;
	if ((*q)->chunks == 1) //всего 1 чанк
		(*q)->ar_of_mx[0] = (*q)->max;
	else //несколько чанков
	{
		while (++cycle < (*q)->chunks)
		{
			cnt += 10;
			(*q)->ar_of_mx[++i] = ar[cnt];
		}
		(*q)->ar_of_mx[++i] = (*q)->max;
	}
}

void 	ft_how_long(t_instr *in, t_alg **q)
{
	(*q)->ra_f = 0;
	(*q)->ra_s = 0;
	(*q)->rra_f = 0;
	(*q)->res = 0;
	(*q)->rra_s = 0;
	(*q)->act_for_f = -1; //what to do for hold_first
	(*q)->act_for_s = -1; //what to do for hold_second
	((*q)->place[0] <= ((*in).size_a / 2)) ? ((*q)->act_for_f = RA_IS) :
	((*q)->act_for_f = RRA_IS);
	((*q)->place[1] <= ((*in).size_a / 2)) ? ((*q)->act_for_s = RA_IS) :
	((*q)->act_for_s = RRA_IS);
	if ((*q)->act_for_f == RA_IS && (*q)->act_for_f == ((*q)->act_for_s)) // 'ra' is faster for both
	{
		if ((*q)->place[0] >= (*q)->place[1]) //if hold_first is faster
			(*q)->res = F_RA; //first is faster
		else
			(*q)->res = S_RA; //second is faster

	}
	else if ((*q)->act_for_f == RRA_IS && (*q)->act_for_f == ((*q)->act_for_s)) // 'rra' is faster for both
	{
		if (((*in).size_a - (*q)->place[0]) < (*in).size_a - (*q)->place[1]) //if hold_first is faster
			(*q)->res = F_RRA; //first is faster
		else
			(*q)->res = S_RRA; //second is faster
	}
	else if ((*q)->act_for_f > (*q)->act_for_s) // 'ra' for first & 'rra' for second
	{
		if ((*q)->place[0] <  (*in).size_a - (*q)->place[1]) //if hold_first is faster
			(*q)->res = F_RA; //first is faster
		else
			(*q)->res = S_RRA; //second is faster
	}
	else if ((*q)->act_for_f < (*q)->act_for_s) // 'rra' for first & 'ra' for second
	{
		if (((*in).size_a - (*q)->place[0]) < (*q)->place[1]) //if hold_first is faster
			(*q)->res = F_RRA; //first is faster
		else
			(*q)->res = S_RA; //second is faster
	}
}

void	ft_create_array(int *ar, t_stack **a, t_alg **q, t_instr **in)
{
	int i;

	i = -1;
	ft_turn_begin(a);
	while ((*a) && (*a)->next)
	{
		ar[++i] = (*a)->nb;
		(*a) = (*a)->next;
	}
	ar[++i] = (*a)->nb;
	ft_turn_begin(a);
}


int 	ft_partition(int l, int h, int *ar)
{
	int pivot;
	int i;
	int tmp;
	int j;

	i = 1;
	j = h - 1;
	tmp = 0;
	pivot = ar[l];
	while (i < j)
	{
		while (ar[i] <= pivot)
			i++;
		while (ar[j] > pivot)
			j--;
		if (i < j)
		{
			tmp = ar[i];
			ar[i] = ar[j];
			ar[j] = tmp;
		}
	}
	tmp = ar[l];
	ar[l] = ar[j];
	ar[j] = tmp;
	return (j);
}

void	ft_quick_sort(int *ar, int l, int h)
{
	int 	j; //end
	int 	i; //beginning

	if (l < h)
	{
		j = ft_partition(l, h, ar);
		ft_quick_sort(ar, l, j);
		ft_quick_sort(ar, j + 1, h);
	}
}
