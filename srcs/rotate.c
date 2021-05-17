/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:31:52 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/17 18:50:58 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *l, char c)
{
	t_list	*tmp;
	int		i;

	if (l->size_stack <= 1)
		return ;
	tmp = l->stack->next;
	ft_lstadd_back(&l->stack, l->stack);
	l->stack = tmp;
	i = 0;
	tmp = l->stack;
	while (i < l->size_stack - 1)
	{
		l->stack = l->stack->next;
		i++;
	}
	l->stack->next = NULL;
	l->stack = tmp;
	printf("r%c\n", c);
}

void	rotate_rotate(t_struct *ps)
{
	rotate(&ps->a, 'a');
	rotate(&ps->b, 'b');
}
