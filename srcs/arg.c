/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:59:54 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/23 11:56:26 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_arg_max(char **tab, int i)
{
	int		res;

	res = ft_atoi(tab[i]);
	i++;
	while (tab[i] != NULL)
	{
		if (res < ft_atoi(tab[i]))
			res = ft_atoi(tab[i]);
		i++;
	}
	return (res);
}

int	get_arg_min(char **tab, int i)
{
	int		res;

	res = ft_atoi(tab[i]);
	i++;
	while (tab[i] != NULL)
	{
		if (res > ft_atoi(tab[i]))
			res = ft_atoi(tab[i]);
		i++;
	}
	return (res);
}

t_arg	init_arg(char **argv, int i)
{
	t_arg	new;

	new.arg_max = get_arg_max(argv, i);
	new.arg_min = get_arg_min(argv, i);
	return (new);
}

void	new_tab_arg(t_stack *l, int size, t_arg *tmp)
{
	t_list	*lst;
	char	**tab;
	int		i;

	tab = malloc(sizeof(char *) * (size + 1));
	if (tab == NULL)
		return ;
	lst = l->stack;
	i = 0;
	while (i < size)
	{
		tab[i] = l->stack->content;
		l->stack = l->stack->next;
		i++;
	}
	tab[i] = NULL;
	l->stack = lst;
	*tmp = init_arg(tab, 0);
}
