/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:06:20 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/17 21:15:55 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	for_three_int(t_struct *ps, t_arg arg)
{
	if (check_order(&ps->a) == 0)
		return ;
	if (arg.arg_min == ft_atoi(ps->a.stack->next->next->content))
	{
		if (arg.arg_max == ft_atoi(ps->a.stack->content))
			swap(&ps->a, 'a');
		reverse_rotate(&ps->a, 'a');
	}
	else if (arg.arg_min != ft_atoi(ps->a.stack->next->next->content)
		&& arg.arg_max != ft_atoi(ps->a.stack->next->next->content))
	{
		if (arg.arg_min == ft_atoi(ps->a.stack->content))
			swap(&ps->a, 'a');
		rotate(&ps->a, 'a');
	}
	else
		swap(&ps->a, 'a');
}

void	add_int(t_struct *ps, t_arg arg)
{
	int		num;
	int		middle;
	int		count;
	t_list	*lst;

	count = 0;
	while (ps->b.size_stack != 0)
	{
		num = ft_atoi(ps->b.stack->content);
		middle = search_middle_stack(&ps->a);
		count = 0;
		if (num < middle)
		{
			while (num > ft_atoi(ps->a.stack->content))
			{
				rotate(&ps->a, 'a');
				count++;
			}
			push(&ps->a, &ps->b, 'a');
			while (count > 0)
			{
				reverse_rotate(&ps->a, 'a');
				count--;
			}
		}
		else
		{
			lst = ft_lstlast(ps->a.stack);
			while (num < ft_atoi(lst->content))
			{
				reverse_rotate(&ps->a, 'a');
				count++;
				lst = ft_lstlast(ps->a.stack);
			}
			push(&ps->a, &ps->b, 'a');
			while (count >= 0)
			{
				rotate(&ps->a, 'a');
				count--;
			}
		}
	}
}

void	process_small_sort(t_struct *ps, t_arg arg)
{
	t_arg	tmp;

	if (check_order(&ps->a) == 1) // Ajout du cas $ARG="2 3 4 5 1" -> RRA
									// et $ARG="6 2 3 4 5" ->  RA
									// et $ARG="5 4 3 2 1" -> 4 * RA
	{
		if (ps->a.size_stack == 2)
			swap(&ps->a, 'a');
		else if (ps->a.size_stack == 3)
			for_three_int(ps, arg);
		else if (ps->a.size_stack <= 5)
		{
			if (ps->a.size_stack == 5)
				push(&ps->b, &ps->a, 'b');
			push(&ps->b, &ps->a, 'b');
			new_tab_arg(&ps->a, 4, &tmp);
			for_three_int(ps, tmp);
			add_int(ps, tmp);
		}
	}
}
