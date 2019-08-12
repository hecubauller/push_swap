/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:22:01 by huller            #+#    #+#             */
/*   Updated: 2019/08/12 18:22:02 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

# include <stdlib.h>
# include "../libft/libft/includes/libft.h"

# define ERROR -1

/*
 * STRUCTURES
 */

typedef struct			s_stack
{
	int 				nb;
	struct s_stack		*next;
	struct s_stack		*prev;
}						t_stack;

typedef struct			s_instr
{
	short int			inst;
	struct s_stack		*next;
}						t_instr;

/*
 * FUNCTIONS
 */

int		ft_reader_str(t_stack **s, t_instr **in, char **argv, int *fd);
int		ft_reader(t_stack **s, t_instr **in, char **argv, int *fd);

#endif
