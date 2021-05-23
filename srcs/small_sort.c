/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:06:20 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/23 15:34:09 by adupuy           ###   ########.fr       */
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
		if (ps->b.size_stack == 2 && ft_atoi(ps->b.stack->content)
			< ft_atoi(ps->b.stack->next->content))
			rotate_rotate(ps);
		else
			rotate(&ps->a, 'a');
	}
	else
		swap(&ps->a, 'a');
}

void	put_in_order(t_stack *l, int value, char c)
{
	int	pos;
	int	size;

	size = 0;
	search_pos_value(&pos, value, l);
	if (l->size_stack % 2 == 1)
		size = 1;
	if (pos <= l->size_stack / 2 + size)
	{
		while (pos > 1)
		{
			rotate(l, c);
			pos--;
		}
	}
	else
	{
		while (pos <= l->size_stack)
		{
			reverse_rotate(l, c);
			pos++;
		}
	}
}

int	special_cases_1(t_stack *a)
{
	t_list	*lst;
	int		count;
	int		ret;

	count = a->size_stack - 1;
	ret = 0;
	lst = a->stack;
	while (count > 0)
	{
		if (ft_atoi(a->stack->content) < ft_atoi(a->stack->next->content))
			ret = 1;
		a->stack = a->stack->next;
		count--;
	}
	a->stack = lst;
	return (ret);
}

void	more_than_three(t_struct *ps)
{
	t_arg	tmp;
	int		count;

	if (special_cases_1(&ps->a) == 0)
	{
		count = ps->a.size_stack - 1;
		while (--count > 0)
		{
			reverse_rotate(&ps->a, 'a');
			push(&ps->b, &ps->a, 'b');
		}
		swap(&ps->a, 'a');
		while (ps->b.size_stack > 0)
			push(&ps->a, &ps->b, 'a');
		return ;
	}
	if (ps->a.size_stack == 5)
		push(&ps->b, &ps->a, 'b');
	push(&ps->b, &ps->a, 'b');
	new_tab_arg(&ps->a, 3, &tmp);
	for_three_int(ps, tmp);
	add_int(ps, tmp, 0);
	new_tab_arg(&ps->a, ps->a.size_stack, &tmp);
	put_in_order(&ps->a, tmp.arg_min, 'a');
}

void	process_small_sort(t_struct *ps, t_arg arg)
{
	if (check_order(&ps->a) == 1)
	{
		if (ps->a.size_stack == 2)
			swap(&ps->a, 'a');
		else if (ps->a.size_stack == 3)
			for_three_int(ps, arg);
		else if (ps->a.size_stack <= 5)
			more_than_three(ps);
	}
}
