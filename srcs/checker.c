/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:13:58 by huller            #+#    #+#             */
/*   Updated: 2019/09/05 14:40:49 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int main(int argc, char **argv)
{
	int 		res;
	t_stack 	*a;
	t_stack 	*b;
	t_instr		*in;
	char 		**av_str;

	res = 0;
	av_str = NULL;
	b = NULL;
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
	if ((ft_reader_argv(&a, &in, (av_str ? av_str : argv)) == ERROR))
	{
		ft_free_lsts(&a);
		ft_putstr("Error\n");
		free(in);
		return (0);
	}
	if ((ft_get_input(in, &a, &b) == ERROR))
	{
		ft_putstr("Error\n");
		ft_free_lsts(&a);
		free(in);
		return (0);
	}
	res = ft_check_output(&a, in);
	ft_free_lsts(&a);
	ft_free_lsts(&b);
	free(in);
	if (res == OK)
		ft_putstr("OK\n");
	if (res == KO)
		ft_putstr("KO\n");
	return (SUCCESS);
}
