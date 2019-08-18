/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:22:01 by huller            #+#    #+#             */
/*   Updated: 2019/08/19 01:16:58 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../includes/ft_printf.h"
# include "../includes/get_next_line.h"

# define OK 2
# define KO 3
# define ERROR -1
# define SUCCESS 1
# define FAIL 0

/*
 * MASKS
 */

# define SA		(1u << 0u)
# define SB		(1u << 1u)
# define SS		(1u << 2u)
# define PA		(1u << 3u)
# define PB		(1u << 4u)
# define RA		(1u << 5u)
# define RB		(1u << 6u)
# define RR		(1u << 7u)
# define RRA	(1u << 8u)
# define RRB	(1u << 9u)
# define RRR	(1u << 10u)

# define MAX_INTEGER 2147483647
# define MIN_INTEGER -2147483648

/*
 * STRUCTURES
 */

typedef struct			s_stack
{
	int 				nb;
	int 				size;
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

int			ft_get_input();
void		ft_put_result(int res);
void		ft_newlist_ch(t_stack **a);
int 		ft_check_valid_instr(char **line);
int			ft_check_dubl(char **argv, int tmp);
int 		ft_check_output(t_stack **a, t_stack **b);
void		ft_add_nbrs(int tmp, t_stack **a, char **argv);
int			ft_reader_argv(t_stack **a, t_instr **in, char **argv, t_stack **b);

#endif
