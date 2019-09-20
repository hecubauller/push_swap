/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 01:03:23 by huller            #+#    #+#             */
/*   Updated: 2019/09/20 19:13:09 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		ret_fr(char *res_nb, char *cmp_str)
{
	free(res_nb);
	free(cmp_str);
	return (ERROR);
}

void	cycles_int(char *tmp, int *i, char *cmp_str)
{
	int	k;

	k = -1;
	while (tmp[(*i)] == '0')
		(*i)++;
	while (tmp[(*i)] >= '0' && tmp[(*i)] <= '9')
	{
		cmp_str[++k] = tmp[(*i)];
		(*i)++;
	}
}

int		int_checker(char *tmp, int nb)
{
	char	*res_nb;
	int		i;
	char	*cmp_str;
	int		pos;

	i = 0;
	pos = 0;
	res_nb = ft_itoa(nb);
	if (!(cmp_str = (char *)malloc(sizeof(char) * ft_strlen(tmp))))
		exit(ERROR);
	if (ft_strcmp(tmp, res_nb))
	{
		if (tmp[i] == '+')
			pos = 1;
		if (pos && ((tmp[++i] == '-') || tmp[i] == '+'))
			return (ret_fr(res_nb, cmp_str));
		cycles_int(tmp, &i, cmp_str);
		if (ft_strcmp(res_nb, cmp_str))
			return (ret_fr(res_nb, cmp_str));
	}
	free(res_nb);
	free(cmp_str);
	return (SUCCESS);
}

void	put_result(int res)
{
	if (res == ERROR)
		ft_putstr("Error\n");
	if (res == OK)
		ft_putstr("OK\n");
	if (res == KO)
		ft_putstr("KO\n");
}

int		get_input(t_instr *in, t_stack **a, t_stack **b)
{
	char	*line;

	(*in).viz ? vizualize_init(a, b, in) : 0;
	while (get_next_line(0, &line))
	{
		if ((check_valid_instr(&line, in)) == ERROR)
		{
			(line) ? free(line) : 0;
			return (ERROR);
		}
		appl_instr(in, a, b);
		free(line);
	}
	(line) ? free(line) : 0;
	return (SUCCESS);
}
