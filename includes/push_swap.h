/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:31:43 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/17 22:51:57 by adupuy           ###   ########.fr       */
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
   ***** UTILS *****
*/
int	size_tab(char **tab);
int	check_order(t_stack *l);

/*
   ***** PRINT *****
*/
void	print_lst(t_list *lst);
void	print_tab_int(int *tab, int size);

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
