/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:31:52 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/19 18:56:50 by adupuy           ###   ########.fr       */
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
	if (c != ' ')
		printf("r%c\n", c);
}

void	rotate_rotate(t_struct *ps)
{
	rotate(&ps->a, ' ');
	rotate(&ps->b, ' ');
	printf("rr\n");
}
