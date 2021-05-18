/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:31:43 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/18 19:31:01 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_pos
{
	int		high;
	int		low;
	int		value_high;
	int		value_low;
	int		min;
	int		max;
}				t_pos;

typedef struct s_stack
{
	int		size_stack;
	t_list		*stack;
}				t_stack;

typedef struct s_arg
{
	int		arg_max;
	int		arg_min;
}				t_arg;

typedef struct s_chunck
{
	int		*tab;
	int		*nb_int_chunck;
	int		nb_chunck;
}				t_chunck;

typedef struct s_struct
{
	t_stack		a;
	t_stack		b;
}				t_struct;

/*
   ***** MAIN *****
*/


/*
   ***** ARG *****
*/
int	get_arg_max(char **tab, int i);
int	get_arg_min(char **tab, int i);
t_arg	init_arg(char **argv, int i);
void	new_tab_arg(t_stack *l, int size, t_arg *tmp);

/*
   ***** STRUCT *****
*/
void	clear_struct(t_struct *ps);
t_struct	*init_struct_ps(char **argv, int size);
t_list	*filling_stack(char **argv);
int	search_middle_stack(t_stack *l);

/*
   ***** SMALL SORT *****
*/
void	for_three_int(t_struct *ps, t_arg arg);
void	add_int(t_struct *ps, t_arg arg);
void	process_small_sort(t_struct *ps, t_arg arg);

/*
   ***** SORT *****
*/
void	loop_sort(t_struct *ps, t_chunck chunck, t_arg arg);
void	process_sort(t_struct *ps, t_arg arg, int div);

/*
   ***** PROCESS PUSH *****
*/
int	before_push_b(int value, t_stack *b);
void	process_push_stack_b(t_pos *pos, t_struct *ps);
void	push_max_in_stack_b(int max, t_struct *ps);

/*
   ***** CHUNCK *****
*/
void	value_chunck(int *tab, int *tmp, int size_stack, int *nb_int_chunck);
int	*get_chunck(t_stack *a, t_arg arg, int nb_chunck, int **nb_int_chunck);
void	sort_with_chunck(int min, int max, t_struct *ps, int nb_int_chunck);

/*
   ***** VALUE *****
*/
int	search_value_just_below(int *value_beside, int *pos, int value, t_stack *b);
int	search_value_just_above(int *value_beside, int *pos, int value, t_stack *b);

/*
   ***** POSITION *****
*/
void	search_pos(t_pos *pos, t_stack *l, int i);
void	search_pos_low(t_pos *pos, t_stack *a, int i);
void	search_pos_high(t_pos *pos, t_stack *a, int i);

/*
   ***** UTILS *****
*/
int	size_tab(char **tab);
int	check_order(t_stack *l);
void	sort_tab_int(int *tab, int size);
int	*copy_stack(t_stack *l);

/*
   ***** PRINT *****
*/
void	print_lst(t_list *lst);
void	print_tab_int(int *tab, int size);
void	print_pos(t_pos pos);
void	print_struct(t_stack *a, t_stack *b);

/*
   ***** SWAP *****
*/
void	swap(t_stack *l, char c);
void	swap_swap(t_struct *ps);

/*
   ***** PUSH *****
*/
void	push(t_stack *dest, t_stack *src, char c);

/*
   ***** ROTATE *****
*/
void	rotate(t_stack *l, char c);
void	rotate_rotate(t_struct *ps);

/*
   ***** REVERSE ROTATE
*/
void	reverse_rotate(t_stack *l, char c);
void	reverse_rotate_rotate(t_struct *ps);

#endif
