/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:13:58 by huller            #+#    #+#             */
/*   Updated: 2019/08/20 06:46:38 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_includes/checker.h"

int main(int argc, char **argv)
{
	int 		res;
	t_stack 	*a;
	t_stack 	*b;
	t_instr		*in;
	char 		**av_str;

	res = 0;
	av_str = NULL;
	in = (t_instr *)malloc(sizeof(t_instr));
	in->split = 0;
	in->inst = 0;
	if (argc == 1)
		return (0);
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		av_str = ft_strsplit(argv[1], ' ');
		in->split++;
	}
	if ((ft_reader_argv(&a, &in, (av_str ? av_str : argv), &b) == ERROR))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if ((ft_get_input(in, &a, &b) == ERROR))
	{
		ft_putstr("Error\n");
		return (0);
	}
	res = ft_check_output(&a, &b);
	if (res == OK)
		ft_putstr("OK\n");
	if (res == KO)
		ft_putstr("KO\n");
	//ft_put_result(res);
	return (SUCCESS);
}
