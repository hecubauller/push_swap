/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 20:26:13 by huller            #+#    #+#             */
/*   Updated: 2019/08/12 20:26:15 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_includes/checker.h"

int		ft_reader_str(t_stack **s, t_instr **in, char **argv, int *fd)
{
	int		res;

	res = ft_atoi(argv[1]);
	ft_printf("%d\n, res");
}

int		ft_reader(t_stack **s, t_instr **in, char **argv, int *fd)
{
	if (!(*argv + 2))
		if (!(ft_reader_str(&s, &in, &argv, &fd)))
			return (ERROR);
}