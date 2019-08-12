/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:13:58 by huller            #+#    #+#             */
/*   Updated: 2019/08/12 18:14:00 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_includes/checker.h"

int main(int argc, char **argv)
{
	t_stack 	*s;
	t_instr		*in;
	int 		fd;

	if (argc == 1)
		return (0);
	fd = 0;
	if (!(reader(&s, &in, &argv, &fd)))
	{

	}
}