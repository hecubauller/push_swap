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

void	ft_add_nbrs(int tmp, t_stack **a, char **argv)
{
	t_stack		*tmp2;

	while (argv[tmp])
	{
		(*a)->nb = ft_atoi(argv[tmp]);
		tmp2 = (*a);
		if (!((*a)->next = (struct s_stack *)malloc(sizeof(struct s_stack))))
			exit (FAIL);
		(*a) = (*a)->next;
		(*a)->prev = tmp2;
		(*a)->nb = 0;
		++tmp;
	}
}

int		ft_check_dubl(char **argv, int tmp)
{
	int 	cnt;
	int 	cnt2;
	int 	cnst;

	cnt = tmp;
	cnst = tmp;
	cnt2 = tmp;
	while (argv[tmp])
	{
		cnt2 = cnst;
		while (argv[cnt2])
		{
			cnt2 == tmp ? ++cnt2 : 0;
			if (ft_strcmp(argv[tmp], argv[cnt2]))
				return (ERROR);
			++cnt2;
		}
		++tmp;
	}
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
	int 		i;
	int 		cnt;
	int 		tmp;
	char 		*chckr;

	i = -1;
	cnt = -1;
	if (!(chckr = (char *)malloc(sizeof(char) * 10)))
		return (FAIL);
	chckr[9] = '\0';
	chckr = "./checker";
	if (!(ft_strcmp(argv[0], chckr)))
		cnt++;
	tmp = cnt;
	while (argv[++cnt]
	{
		while (argv[cnt][i] && argv[cnt][i] >= 0 && argv[cnt][i] <= 9)
			++i;
		if (argv[cnt][i])
			return (ERROR);
	}
	if (!(ft_check_dubl(argv, tmp)))
		return (ERROR);
	ft_newlist(a);
	ft_newlist(b);
	ft_add_nbrs(tmp, a, argv);
}