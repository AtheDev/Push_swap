/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:14:11 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/23 11:56:47 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_pos_high(t_pos *pos, t_stack *a, int i)
{
	t_list	*lst;
	int		num;
	int		count;

	lst = a->stack;
	count = 0;
	while (a->stack != NULL)
	{
		num = ft_atoi(a->stack->content);
		if ((i == 0 && (num >= pos->min && num < pos->max))
			|| (i == 1 && (num >= pos->min && num <= pos->max)))
		{
			pos->value_high = num;
			pos->high = count;
			break ;
		}
		count++;
		a->stack = a->stack->next;
	}
	a->stack = lst;
}

void	search_pos_low(t_pos *pos, t_stack *a, int i)
{
	t_list	*lst;
	int		num;
	int		count;

	lst = a->stack;
	count = 0;
	while (a->stack != NULL)
	{
		num = ft_atoi(a->stack->content);
		if ((i == 0 && (num >= pos->min && num < pos->max))
			|| (i == 1 && (num >= pos->min && num <= pos->max)))
		{
			pos->value_low = num;
			pos->low = count;
		}
		count++;
		a->stack = a->stack->next;
	}
	a->stack = lst;
}

void	search_pos(t_pos *pos, t_stack *l, int i)
{
	search_pos_high(pos, l, i);
	search_pos_low(pos, l, i);
}
