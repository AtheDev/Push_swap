/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:55:59 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/18 13:54:09 by adupuy           ###   ########.fr       */
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

void	print_pos(t_pos pos)
{
	printf("\033[31m***** PRINT_POS *****\033[37m\n");
	printf("pos high = %d\n", pos.high);
	printf("pos low = %d\n", pos.low);
	printf("pos value_high = %d\n", pos.value_high);
	printf("pos value_low = %d\n", pos.value_low);
	printf("pos min = %d\n", pos.min);
	printf("pos max = %d\n", pos.max);
	printf("\033[31m***** FIN *****\033[37m\n\n");
}

void	print_struct(t_stack *a, t_stack *b)
{
	printf("\033[31m***** PRINT_A *****\033[37m\n");
	print_lst(a->stack);
	printf("\033[31m***** FIN *****\033[37m\n\n");
	printf("\033[31m***** PRINT_B *****\033[37m\n");
	print_lst(b->stack);
	printf("\033[31m***** FIN *****\033[37m\n\n");
}
