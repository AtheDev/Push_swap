/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:32:27 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/23 13:21:12 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_num_sup(t_struct *ps, int num, t_arg arg, int *count)
{
	t_list	*lst;

	if (num < arg.arg_min)
	{
		lst = ft_lstlast(ps->a.stack);
		if (arg.arg_max != ft_atoi(lst->content))
		{
			while (arg.arg_max != ft_atoi(lst->content))
			{
				reverse_rotate(&ps->a, 'a');
				lst = ft_lstlast(ps->a.stack);
			}
		}
	}
	else
	{
		while (num > ft_atoi(ps->a.stack->content)
			|| (num < ft_atoi(ps->a.stack->content)
				&& num > ft_atoi(ps->a.stack->next->content)))
		{
			rotate(&ps->a, 'a');
			(*count)++;
		}
	}
}

void	if_num_inf(t_struct *ps, int num, t_arg arg, int *count)
{
	t_list		*lst;

	if (num > arg.arg_max)
		put_in_order(&ps->a, arg.arg_min, 'a');
	else
	{
		lst = ft_lstlast(ps->a.stack);
		while (num < ft_atoi(lst->content))
		{
			reverse_rotate(&ps->a, 'a');
			(*count)++;
			lst = ft_lstlast(ps->a.stack);
		}
		lst = ps->a.stack;
		while (num > ft_atoi(lst->content))
		{
			rotate(&ps->a, 'a');
			(*count)++;
			lst = ps->a.stack;
		}
	}
	push(&ps->a, &ps->b, 'a');
	if (*count == 0 && ps->b.size_stack == 0)
		rotate(&ps->a, 'a');
}

void	add_int(t_struct *ps, t_arg arg, int count)
{
	int		num;
	int		middle;
	t_list	*lst;

	while (ps->b.size_stack != 0)
	{
		num = ft_atoi(ps->b.stack->content);
		middle = search_middle_stack(&ps->a);
		count = 0;
		if (num < middle)
		{
			if_num_sup(ps, num, arg, &count);
			push(&ps->a, &ps->b, 'a');
			while (count > 0)
			{
				reverse_rotate(&ps->a, 'a');
				count--;
			}
		}
		else
			if_num_inf(ps, num, arg, &count);
		new_tab_arg(&ps->a, ps->a.size_stack, &arg);
		add_int(ps, arg, 0);
	}
}
