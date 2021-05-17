/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:49:23 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/17 21:16:44 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *dest, t_stack *src, char c)
{
	t_list		*tmp;

	if (src->size_stack == 0)
		return ;
	tmp = src->stack->next;
	ft_lstadd_front(&dest->stack, src->stack);
	src->stack = tmp;
	dest->size_stack++;
	src->size_stack--;
	printf("p%c\n", c);
}
