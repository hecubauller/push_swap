/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:13:43 by huller            #+#    #+#             */
/*   Updated: 2019/09/20 20:13:43 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	innn(t_stack **a, t_sort **p, int *end, int *start)
{
	(*p)->ra = 0;
	(*p)->rra = 0;
	(*p)->cmnd_a = 0;
	create_max(a, p);
	turn_end(a);
	(*a) ? ((*end) = (*a)->nb) : 0;
	turn_begin(a);
	(*start) = search_beginning(a, (*end));
	turn_begin(a);
}
