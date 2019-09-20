/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 04:47:18 by huller            #+#    #+#             */
/*   Updated: 2019/09/20 17:54:22 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		swap_2(int argc, char **argv, t_instr **in, char **av_str)
{
	if (argc == 1)
	{
		free(in);
		return (0);
	}
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		av_str = ft_strsplit(argv[1], ' ');
		(*in)->split++;
	}
	return (SUCCESS);
}

void	in_swap(t_instr *in, t_stack **a, t_stack **b)
{
	b = NULL;
	a = NULL;
	in->split = 0;
	in->inst = 0;
	in->viz = 0;
	in->push_swap = 1;
	in->size_b = 0;
}

int		main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	t_instr			*in;
	char			**av_str;
	int				i;

	av_str = NULL;
	if (!(in = (t_instr *)malloc(sizeof(t_instr))))
		return (ERROR);
	in_swap(in, &a, &b);
	if (argc == 1)
	{
		free(in);
		return (0);
	}
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		av_str = ft_strsplit(argv[1], ' ');
		in->split++;
	}
	if ((reader_argv(&a, &in, (av_str ? av_str : argv)) == ERROR))
	{
		newlist_ch(&a);
		(a) ? (free_lsts(&a)) : 0;
		ft_putstr("Error\n");
		i = -1;
		while (av_str && av_str[++i])
			free(av_str[i]);
		av_str ? free(av_str) : 0;
		free(in);
		return (0);
	}
	algorithm(in, &a, &b);
	free_lsts(&a);
	free_lsts(&b);
	free(in);
	i = -1;
	while (av_str && av_str[++i])
		free(av_str[i]);
	av_str ? free(av_str) : 0;
	return (0);
}
