/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:28:58 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/23 16:00:04 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	before_push_b(int value, t_stack *b, int res)
{
	int		value_beside;
	int		pos_value_beside;

	if (b->stack == NULL)
		return (0);
	if (search_value_just_below
		(&value_beside, &pos_value_beside, value, b) == 2)
		res = 1;
	if (pos_value_beside <= b->size_stack / 2)
	{
		while (pos_value_beside + res > 0)
		{
			rotate(b, 'b');
			pos_value_beside--;
		}
	}
	else if (pos_value_beside > b->size_stack / 2)
	{
		while (pos_value_beside + res < b->size_stack)
		{
			reverse_rotate(b, 'b');
			pos_value_beside++;
		}
	}
	return (0);
}

void	process_push_stack_b(t_pos *pos, t_struct *ps, int res)
{
	if (ps->a.size_stack + pos->high <= ps->a.size_stack + pos->low)
	{
		while (pos->high > 0)
		{
			rotate(&ps->a, 'a');
			pos->high--;
		}
		if (before_push_b(pos->value_high, &ps->b, 0) == 1)
			res = 1;
	}
	else if (ps->a.size_stack + pos->high > ps->a.size_stack + pos->low)
	{
		while (pos->low < ps->a.size_stack)
		{
			reverse_rotate(&ps->a, 'a');
			pos->low++;
		}
		if (before_push_b(pos->value_low, &ps->b, 0) == 1)
			res = 1;
	}
	push(&ps->b, &ps->a, 'b');
	if (res == 1)
		rotate(&ps->b, 'b');
}
