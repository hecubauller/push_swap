/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:13:58 by huller            #+#    #+#             */
/*   Updated: 2019/08/19 01:43:26 by huller           ###   ########.fr       */
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
	if (argc == 1)
		return (0);
	if (argc == 2)
		av_str = ft_strsplit(argv[1], ' ');
	if ((ft_reader_argv(&a, &in, (av_str ? av_str : argv), &b) == ERROR))
	{
		ft_putstr("Error");
		return (0);
	}
	if ((ft_get_input() == ERROR))
	{
		ft_putstr("Error");
		return (0);
	}
	res = ft_check_output(&a, &b);
	if (res == OK)
		ft_putstr("OK");
	if (res == KO)
		ft_putstr("KO");
	//ft_put_result(res);
	return (SUCCESS);
}
