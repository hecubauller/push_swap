/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:22:01 by huller            #+#    #+#             */
/*   Updated: 2019/08/26 05:56:46 by huller           ###   ########.fr       */
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
# define CYN   "\x1B[36m"
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define WHT   "\033[1;30m"
# define RESET "\x1B[0m"
# define CLR   "\e[1;1H\e[?25l"

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
	struct s_stack		*next;
	struct s_stack		*prev;
}						t_stack;

typedef struct			s_instr
{
	unsigned int		viz;
	int 				size_a;
	int 				size_b;
	unsigned short int	inst;
	int 				split;
	struct s_stack		*next;
}						t_instr;

/*
 * FUNCTIONS
 */

void		ft_sa(t_stack **x, t_instr *instr);
void		ft_ra(t_stack **x, t_instr *instr);
void		ft_rra(t_stack **x, t_instr *instr);
void		ft_ss(t_stack **a, t_stack **b, t_instr *instr);
void		ft_rr(t_stack **a, t_stack **b, t_instr *instr);
void		ft_rrb(t_stack **a, t_stack **b, t_instr *instr);
void		ft_rrr(t_stack **a, t_stack **b, t_instr *instr);
void		ft_pa(t_stack **a, t_stack **b, t_instr *instr);
void		ft_pb(t_stack **a, t_stack **b, t_instr *instr);

void		ft_put_result(int res);
void		ft_free_lsts(t_stack **a);
void		ft_newlist_ch(t_stack **a);
int			ft_int_checker(char *tmp, int nb);
int			ft_check_dubl(char **argv, int tmp);
int 		ft_check_output(t_stack **a, t_instr *in);
int 		ft_check_valid_instr(char **line, t_instr *in);
int			ft_get_input(t_instr *in, t_stack **a, t_stack **b);
void		ft_appl_instr(t_instr *in, t_stack **a, t_stack **b);
int			ft_reader_argv(t_stack **a, t_instr **in, char **argv);
void		ft_vizualize_init(t_stack **a, t_stack **b, t_instr *instr);
void		ft_add_nbrs(int tmp, t_stack **a, char **argv, t_instr *in);
void		ft_vizualize_check(t_stack **a, t_stack **b, t_instr *instr);

#endif
