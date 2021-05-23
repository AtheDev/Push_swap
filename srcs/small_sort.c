/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:06:20 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/22 15:13:24 by adupuy           ###   ########.fr       */
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

void	search_pos_value(int *pos, int value, t_stack *l)
{
	t_list	*lst;
	int		num;
	int		count;

	lst = l->stack;
	count = 0;
	while (l->stack != NULL)
	{
		num = ft_atoi(l->stack->content);
		if (num == value)
		{
			*pos = count + 1;
			break ;
		}
		count++;
		l->stack = l->stack->next;
	}
	l->stack = lst;
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
				while (num > ft_atoi(ps->a.stack->content) || (num < ft_atoi(ps->a.stack->content) && num > ft_atoi(ps->a.stack->next->content)))
				{
					rotate(&ps->a, 'a');
					count++;
				}
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
			if (num > arg.arg_max)
				put_in_order(&ps->a, arg.arg_min, 'a');
			else
			{
				lst = ft_lstlast(ps->a.stack);
				while (num < ft_atoi(lst->content))
				{
					reverse_rotate(&ps->a, 'a');
					count++;
					lst = ft_lstlast(ps->a.stack);
				}
				lst = ps->a.stack;
				while (num > ft_atoi(lst->content))
				{
					rotate(&ps->a, 'a');
					count++;
					lst = ps->a.stack;
				}
			}
			push(&ps->a, &ps->b, 'a');
			if (count == 0 && ps->b.size_stack == 0)
				rotate(&ps->a, 'a');
		}
			new_tab_arg(&ps->a, ps->a.size_stack, &arg);
			add_int(ps, arg);
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

/*void	special_cases_2(t_stack *a, t_arg arg)
{
	if (arg.arg_max == ft_atoi(a->stack->next->next->content))
	{
		if (a->size_stack == 5)
			reverse_rotate(a, 'a');
		reverse_rotate(a, 'a');
	}
	else if (a->size_stack == 5 && arg.arg_max == ft_atoi(a->stack->next->next->next->content) && arg.arg_min != ft_atoi(a->stack->next->next->content))
		reverse_rotate(a, 'a');
}*/



void	process_small_sort(t_struct *ps, t_arg arg)
{
	t_arg	tmp;
	int		count;

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
			add_int(ps, tmp);
			new_tab_arg(&ps->a, ps->a.size_stack, &tmp);
			put_in_order(&ps->a, tmp.arg_min, 'a');
		}
	}
}
