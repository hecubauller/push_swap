/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <huller@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:24:52 by huller            #+#    #+#             */
/*   Updated: 2019/09/21 03:24:22 by huller           ###   ########.fr       */
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
# define YEL   "\x1B[33m"
# define MAG   "\x1B[35m"
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
}						t_instr;

typedef struct 			s_sort
{
	int 				cmnd_a;
	int 				cmnd_b;
	int 				tot_cmnds;
	int 				rr;
	int 				rrr;
	int 				ra;
	int 				rra;
	int 				rb;
	int 				rrb;
	int 				prev_cmnds;
	int 				prev_nb;
	int 				p_rr;
	int 				p_rrr;
	int 				p_ra;
	int 				p_rb;
	int 				p_rrb;
	int 				p_rra;
	int 				nb;
	int 				min;
	int 				max;
}						t_sort;

typedef struct			s_ch
{
	char				*res_nb;
	int 				i;
	int 				k;
	char			 	*cmp_str;
	int					pos;
	int 				neg;
}						t_ch;

/*
 * FUNCTIONS
 */

void		cmnds_two(t_sort **p);
int			get_free(t_stack **a);
int 		is_sorted(t_stack **a);
t_stack		*turn_end(t_stack **x);
void		free_lsts(t_stack **a);
void		cmnd_three(t_sort **p);
void		total_cmnds(t_sort **p);
void		newlist_ch(t_stack **a);
t_stack		*turn_begin(t_stack **x);
void		compare_comands(t_sort **p);
int 		int_ch_2(t_ch **j, char *tmp);
int			int_checker(char *tmp, int nb);
void		sa(t_stack **x, t_instr *instr);
void		sb(t_stack **x, t_instr *instr);
void		ra(t_stack **x, t_instr *instr);
void		rb(t_stack **x, t_instr *instr);
int			check_dubl(char **argv, int tmp);
void		rrb(t_stack **x, t_instr *instr);
void		pb_two(t_stack **a, t_stack **b);
void		rra(t_stack **x, t_instr *instr);
void		alg_two(t_instr *in, t_stack **a);
void		initialize(t_stack **b, t_sort **p);
int			ret_fr(char *res_nb, char *cmp_str);
void		rr_two(t_stack **b, t_stack *tmp_s);
void 		create_min(t_stack **a, t_sort **p);
void 		create_max(t_stack **a, t_sort **p);
int		 	alg_three(t_instr *in, t_stack **a);
int 		check_output(t_stack **a, t_instr *in);
int			search_beginning(t_stack **a, int end);
void		add_nbrs_if( t_stack **a, t_stack *tmp2);
int 		check_valid_instr(char **line, t_instr *in);
void		ss(t_stack **a, t_stack **b, t_instr *instr);
void		rr(t_stack **a, t_stack **b, t_instr *instr);
void		pa(t_stack **a, t_stack **b, t_instr *instr);
void		cycles_int(char *tmp, int *i, char *cmp_str);
void		pb(t_stack **a, t_stack **b, t_instr *instr);
void		ch_dbl_cycle(char **argv, int *len, int *tmp);
void		rrr(t_stack **a, t_stack **b, t_instr *instr);
void		in_swap(t_instr *in, t_stack **a, t_stack **b);
void		five_one(t_instr *in, t_stack **a, t_stack **b);
int			five_two(t_instr *in, t_stack **a, t_stack **b);
void		in_check(t_instr *in, t_stack **a, t_stack **b);
int		 	getint(t_stack **a, t_instr *in, char **av_str);
char		**getstring(int argc, char **argv, t_instr *in);
int 		alg_five(t_instr *in, t_stack **a, t_stack **b);
void		five_four(t_instr *in, t_stack **a, t_stack **b);
int 		algorithm(t_instr *in, t_stack **a, t_stack **b);
int			get_input(t_instr *in, t_stack **a, t_stack **b);
void 		push_to_a(t_stack **a, t_stack **b, t_instr *in);
void		five_three(t_instr *in, t_stack **a, t_stack **b);
void 		cnt_cmnds_b(t_stack **b, t_instr *in, t_sort **p);
void		appl_instr(t_instr *in, t_stack **a, t_stack **b);
void 		finish_stack(t_stack **a, t_instr *in, t_sort **p);
int			reader_argv(t_stack **a, t_instr **in, char **argv);
void		innn(t_stack **a, t_sort **p, int *end, int *start);
int			 geint_two(t_stack **a, t_instr *in, char **av_str);
void		rrr_two(t_stack **b, t_stack *tmp_s, t_stack *tmp_s2);
void		vizualize_1(t_stack **a, t_stack **b, t_instr *instr);
void		vizualize_init(t_stack **a, t_stack **b, t_instr *instr);
int			add_nbrs(int tmp, t_stack **a, char **argv, t_instr *in);
void		vizualize_check(t_stack **a, t_stack **b, t_instr *instr);
void		two(t_stack **a, t_stack **b, t_instr *in, char **av_str);
int			reader_cycle(char **argv, int *i, int *cnt, t_instr **in);
void		freee(t_stack **a, t_stack **b, t_instr *in, char **av_str);
void		new_algo(t_stack **a, t_stack **b, t_instr *in, t_sort **p);
void 		apply_cmnds(t_stack **a, t_stack **b, t_instr *in, t_sort **p);
void		cnt_cmnds_a(t_stack **a, t_stack **b, t_instr *in, t_sort **p);
void	 	apply_cmnds2(t_stack **a, t_stack **b, t_instr *in, t_sort **p);
void		vizua_2(t_stack **a, t_stack **b, t_stack **tmp_a, t_stack **tmp_b);

#endif
