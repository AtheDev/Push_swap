/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:55:06 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/17 21:03:52 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

int	check_order(t_stack *l)
{
	t_list	*tmp;
	int		res;

	tmp = l->stack;
	res = ft_atoi(l->stack->content);
	while (l->stack->next != NULL)
	{
		if (res > ft_atoi(l->stack->content))
		{
			l->stack = tmp;
			return (1);
		}
		res = ft_atoi(l->stack->content);
		l->stack = l->stack->next;
	}
	if (res > ft_atoi(l->stack->content))
	{
		l->stack = tmp;
		return (1);
	}
	l->stack = tmp;
	return (0);
}

int	search_middle_stack(t_stack *l)
{
	t_list	*tmp;
	int		res;
	int		middle;

	tmp = l->stack;
	middle = l->size_stack / 2;
	while (middle > 0)
	{
		l->stack = l->stack->next;
		middle--;
	}
	res = ft_atoi(l->stack->content);
	l->stack = tmp;
	return (res);
}
