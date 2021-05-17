/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:57:06 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/17 21:15:41 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*filling_stack(char **argv)
{
	t_list	*new;
	int		i;

	i = 1;
	new = NULL;
	while (argv[i] != NULL)
	{
		ft_lstadd_back(&new, ft_lstnew(argv[i]));
		i++;
	}
	return (new);
}

t_struct	*init_struct_ps(char **argv, int size)
{
	t_struct	*new;

	new = malloc(sizeof(t_struct));
	if (new == NULL)
		return (NULL);
	new->a.size_stack = size;
	new->a.stack = filling_stack(argv);
	new->b.size_stack = 0;
	new->b.stack = NULL;
	return (new);
}

void	clear_struct(t_struct *ps)
{
	t_list	*lst;
	t_list	*tmp;

	lst = NULL;
	tmp = ps->a.stack;
	if (ps->a.stack != NULL)
	{
		while (tmp != NULL)
		{
			lst = tmp->next;
			free(tmp);
			tmp = lst;
		}
	}
	tmp = ps->b.stack;
	if (ps->b.stack != NULL)
	{
		while (tmp != NULL)
		{
			lst = tmp->next;
			free(tmp);
			tmp = lst;
		}
	}
	free(ps);
}
