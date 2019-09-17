/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:24:52 by huller            #+#    #+#             */
/*   Updated: 2019/09/17 22:02:00 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../includes/ft_printf.h"
# include "../includes/get_next_line.h"

# define NO_NBRS -90
# define DONT_LOOKIN_FOR -30
# define NOT_IN_STACK -20
# define NTHNG 10
# define F_RA 9
# define F_RRA 8
# define S_RA 7
# define S_RRA 6

# define RA_IS 5
# define RRA_IS 4
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
	int 				push_swap;
	int 				size_a;
	int 				size_b;
	unsigned short int	inst;
	int 				split;
	struct s_stack		*next;
}						t_instr;

typedef struct			s_alg
{
	int 				chunks;
	int 				hold_first;
	int 				hold_second;
	t_stack				*cnt_up;
	t_stack				*cnt_dwn;
	int 				place[2];
	int					res;
	int 				act_for_f;
	int 				*ar_of_mx;
	int 				act_for_s;
	int 				max;
	int 				min;

}						t_alg;

typedef struct 			s_sort
{
	int 				cmnd_a; //comands in stack a
	int 				cmnd_b; //comands in stack b
	int 				rr;
	int 				rrr;
	int 				ra;
	int 				rra;
	int 				rb;
	int 				rrb;
	int 				prev_cmnds; //amount of comands for prev nb
	int 				prev_nb; //prev number
	int 				p_rr;
	int 				p_rrr;
	int 				p_ra;
	int 				p_rb;
	int 				p_rrb;
	int 				p_rra;
//	int 				push_nb;
	int 				tot_cmnds;
	int 				nb; //number now
	int 				min;
	int 				max;
}						t_sort;
/*
 * FUNCTIONS
 */

void		compare_comands(t_sort **p);
void 		apply_cmnds(t_stack **a, t_stack **b, t_instr *in, t_sort **p);
void		total_cmnds(t_sort **p);
void		cnt_cmnds_a(t_stack **a, t_stack **b, t_instr *in, t_sort **p);
void 		cnt_cmnds_b(t_stack **b, t_instr *in, t_sort **p);
void		new_algo(t_stack **a, t_stack **b, t_instr *in, t_sort **p);
void 		finish_stack(t_stack **a, t_instr *in, t_sort **p);
void 		create_min(t_stack **a, t_sort **p);
void 		create_max(t_stack **a, t_sort **p);
void 		push_to_a(t_stack **a, t_stack **b, t_instr *in);
void 		push_back(t_stack **a, t_stack **b, t_instr **in, t_alg **q);
void		put_result(int res);
t_stack		*turn_end(t_stack **x);
void		free_lsts(t_stack **a);
void		newlist_ch(t_stack **a);
t_stack		*turn_begin(t_stack **x);
void	 	how_long(t_instr *in, t_alg **q);
void		alg_two(t_instr *in, t_stack **a);
int			int_checker(char *tmp, int nb);
void		sa(t_stack **x, t_instr *instr);
void		sb(t_stack **x, t_instr *instr);
void		ra(t_stack **x, t_instr *instr);
void		rb(t_stack **x, t_instr *instr);
void		rrb(t_stack **x, t_instr *instr);
void		rra(t_stack **x, t_instr *instr);
int			check_dubl(char **argv, int tmp);
int 		partition(int l, int h, int *ar);
int		 	alg_three(t_instr *in, t_stack **a);
void		quick_sort(int *ar, int l, int h);
void		define_action(t_instr *in, t_alg **q);
int 		check_output(t_stack **a, t_instr *in);
int 		check_valid_instr(char **line, t_instr *in);
void		cnt_place(t_stack **a, t_instr **in, t_alg **q);
void		ss(t_stack **a, t_stack **b, t_instr *instr);
void		rr(t_stack **a, t_stack **b, t_instr *instr);
int 		alg_five(t_instr *in, t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b, t_instr *instr);
void		pb(t_stack **a, t_stack **b, t_instr *instr);
void		rrr(t_stack **a, t_stack **b, t_instr *instr);
int 		is_sorted(t_instr *in, t_stack **a, t_stack **b);
int 		algorithm(t_instr *in, t_stack **a, t_stack **b);
int			get_input(t_instr *in, t_stack **a, t_stack **b);
void		appl_instr(t_instr *in, t_stack **a, t_stack **b);
void		create_maxs(t_alg **q, t_stack **a, t_instr **in);
int			alg_hundred(t_instr *in, t_stack **a, t_stack **b);
int			reader_argv(t_stack **a, t_instr **in, char **argv);
void		vizualize_init(t_stack **a, t_stack **b, t_instr *instr);
void		add_nbrs(int tmp, t_stack **a, char **argv, t_instr *in);
void		vizualize_check(t_stack **a, t_stack **b, t_instr *instr);
void 		check_b(t_stack **a, t_stack **b, t_instr *in, t_alg **q);
void		push_up(t_stack **a, t_stack **b, t_instr *in, t_alg **q);
void		create_array(int *ar, t_stack **a, t_alg **q, t_instr **in);
void		create_maxmin(t_stack **a, t_instr **in, t_alg **q);
void		check_size(t_stack **a, t_stack **b, t_instr **in, t_alg **q);

#endif
