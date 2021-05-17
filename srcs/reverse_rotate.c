/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:30:40 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/17 18:52:04 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *l, char c)
{
	t_list	*tmp;
	t_list	*lst;

	if (l->size_stack <= 1)
		return ;
	tmp = l->stack;
	while (l->stack->next->next != NULL)
		l->stack = l->stack->next;
	lst = l->stack->next;
	l->stack->next = NULL;
	lst->next = tmp;
	l->stack = lst;
	printf("rr%c\n", c);
}

void	reverse_rotate_rotate(t_struct *ps)
{
	reverse_rotate(&ps->a, 'a');
	reverse_rotate(&ps->b, 'b');
}
