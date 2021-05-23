/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:18:06 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/23 11:57:12 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	save_value(int *value_beside, int *pos, int num, int count)
{
	*value_beside = num;
	*pos = count;
}

int	search_value_just_above(int *value_beside, int *pos, int value, t_stack *b)
{
	t_list	*lst;
	int		num;
	int		count;
	int		ret;

	lst = b->stack;
	count = 0;
	ret = 1;
	while (b->stack != NULL)
	{
		num = ft_atoi(b->stack->content);
		if (value < num)
		{
			if (ret == 1 || (ret == 0 && num < *value_beside))
				save_value(value_beside, pos, num, count);
			ret = 0;
		}
		count++;
		b->stack = b->stack->next;
	}
	b->stack = lst;
	return (2);
}

int	search_value_just_below(int *value_beside, int *pos, int value, t_stack *b)
{
	t_list	*lst;
	int		num;
	int		count;
	int		ret;

	lst = b->stack;
	count = 0;
	ret = 1;
	while (b->stack != NULL)
	{
		num = ft_atoi(b->stack->content);
		if (value > num)
		{
			if (ret == 1 || (ret == 0 && num > *value_beside))
				save_value(value_beside, pos, num, count);
			ret = 0;
		}
		count++;
		b->stack = b->stack->next;
	}
	b->stack = lst;
	if (ret == 1)
		return (search_value_just_above(value_beside, pos, value, b));
	return (ret);
}
