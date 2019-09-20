/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:13:58 by huller            #+#    #+#             */
/*   Updated: 2019/09/20 01:35:11 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		main(int argc, char **argv)
{
	int 		res;
	t_stack 	*a;
	t_stack 	*b;
	int 		i;
	t_instr		*in;
	char 		**av_str;

	a = NULL;
	b = NULL;
	i = -1;
	res = 0;
	av_str = NULL;
	in = (t_instr *)malloc(sizeof(t_instr));
	in->split = 0;
	in->inst = 0;
	in->viz = 0;
	in->push_swap = 0;
	if (argc == 1)
		return (0);
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
	if ((reader_argv(&a, &in, (av_str ? av_str : argv)) == ERROR))
	{
		free_lsts(&a);
		ft_putstr("Error\n");
		while (av_str && av_str[++i])
			free(av_str[i]);
		av_str ? free(av_str) : 0;
		free(in);
		return (0);
	}
	if ((get_input(in, &a, &b) == ERROR))
	{
		ft_putstr("Error\n");
		(a) ? (free_lsts(&a)) : 0;
		(b) ? free_lsts(&b) : 0;
		free(in);
		while (av_str && av_str[++i])
			free(av_str[i]);
		av_str ? free(av_str) : 0;
		return (0);
	}
	res = check_output(&a, in);
	free_lsts(&a);
	free_lsts(&b);
	free(in);
	free(av_str);
	if (res == OK)
		ft_putstr("OK\n");
	if (res == KO)
		ft_putstr("KO\n");
	return (0);
}
