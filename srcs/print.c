/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:55:59 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/17 22:51:30 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	while (lst->next != NULL)
	{
		printf("lst = %s\n", lst->content);
		lst = lst->next;
	}
	printf("lst = %s\n\n", lst->content);
	lst = tmp;
}

void	print_tab_int(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}
}
