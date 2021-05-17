/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:14:35 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/17 22:59:57 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_stack(t_stack *l)
{
	t_list	*tmp;
	int		*new;
	int		i;

	tmp = l->stack;
	new = malloc(sizeof(int) * l->size_stack);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (l->stack->next != NULL)
	{
		new[i] = ft_atoi(l->stack->content);
		i++;
		l->stack = l->stack->next;
	}
	new[i] = ft_atoi(l->stack->content);
	l->stack = tmp;
	return (new);
}

void	clear_tab_int(int *tab)
{

}

int	*get_chunck(t_stack *a, t_arg arg, int nb_chunck)
{
	int		*tab;
	int		i;
	int		*tmp;

	tmp = copy_stack(a);
	print_tab_int(tmp, a->size_stack);
/*	tab = malloc(sizeof(int) * nb_chunck);
	if (tab == NULL)
		return (1);
	tab[0] = arg.arg_min;
	i = 1;
	while (i < nb_chunck)
	{

	}*/
	clear_tab_int(tmp);
	return (0);
}

void	process_middle_sort(t_struct *ps, t_arg arg)
{
	t_chunck	chunck;

	chunck.nb_chunck = ps->a.size_stack / 20;
	printf("nb_chunck = %d\n", chunck.nb_chunck);
	chunck.tab = get_chunck(&ps->a, arg, chunck.nb_chunck);
}


int	main(int argc, char **argv)
{
	t_arg		arg;
	t_struct	*ps;

	if (argc == 1)
		return (0);
	arg = init_arg(argv, 1);
	ps = init_struct_ps(argv, size_tab(argv) - 1);
	if (ps->a.size_stack <= 5)
		process_small_sort(ps, arg);
	else if (ps->a.size_stack <= 100)
		process_middle_sort(ps, arg);
	clear_struct(ps);
	return (0);
}
