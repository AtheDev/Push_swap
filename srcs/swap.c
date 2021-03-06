/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 20:02:47 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/19 18:59:55 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *l, char c)
{
	t_list	*tmp;
	t_list	*tmp_next;

	if (l->size_stack <= 1)
		return ;
	tmp_next = l->stack->next->next;
	tmp = l->stack;
	l->stack = l->stack->next;
	l->stack->next = tmp;
	l->stack->next->next = tmp_next;
	if (c != ' ')
		printf("s%c\n", c);
}

void	swap_swap(t_struct *ps)
{
	swap(&ps->a, ' ');
	swap(&ps->b, ' ');
	printf("ss\n");
}
