/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 04:47:18 by huller            #+#    #+#             */
/*   Updated: 2019/09/17 20:52:26 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_stack	*turn_end(t_stack **x)
{
	while ((*x) && (*x)->next)
		(*x) = (*x)->next;
	return (*x);
}

t_stack	*turn_begin(t_stack **x)
{
	while ((*x) && (*x)->prev)
		(*x) = (*x)->prev;
	return (*x);
}

int main(int argc, char **argv)
{
	t_stack 	*a;
	t_stack 	*b;
	t_instr		*in;
	char 		**av_str;

	av_str = NULL;
	b = NULL;
	in = (t_instr *)malloc(sizeof(t_instr));
	in->split = 0;
	in->inst = 0;
	in->viz = 0;
	in->push_swap = 1;
	if (argc == 1)
		return (0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		av_str = ft_strsplit(argv[1], ' ');
		in->split++;
	}
	if ((reader_argv(&a, &in, (av_str ? av_str : argv)) == ERROR))
	{
		free_lsts(&a);
		ft_putstr("Error\n");
		free(in);
		return (0);
	}
	algorithm(in, &a, &b);
	free_lsts(&a);
	free_lsts(&b);
	free(in);
	return (SUCCESS);
}