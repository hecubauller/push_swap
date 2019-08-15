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

t_stack	**ft_nextlist(t_stack **a)
{
	t_stack **tmp;

	tmp = a;
	if (!((*a)->next = (struct s_stack *)malloc(sizeof(struct s_stack))))
		exit (FAIL);
	(*a)->prev = tmp;
	(*a)->nb = 0;
	return (tmp);
}

void	ft_newlist(t_stack **a)
{
	(*a)->nb = 0;
	if (!((*a)->next = (struct s_stack *)malloc(sizeof(struct s_stack))))
		exit (FAIL);
	(*a)->prev = NULL;
}

int		ft_reader_argv(t_stack **a, t_instr **in, char **argv, t_stack **b)
{
	int 	i;
	int 	cnt;
	char 	*chckr;

	i = -1;
	cnt = -1;
	if (!(chckr = (char *)malloc(sizeof(char) * 10)))
		return (FAIL);
	chckr[9] = '\0';
	chckr = "./checker";
	if (!(ft_strcmp(argv[0], chckr)))
		cnt++;
	while (argv[++cnt]
	{
		while (argv[cnt][i] && argv[cnt][i] >= 0 && argv[cnt][i] <= 9)
			++i;
		if (argv[cnt][i])
			return (ERROR);
	}
	ft_newlist(a);
	ft_newlist(b);
	while ()
}