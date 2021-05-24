/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:14:35 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/24 11:10:48 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choice_process(t_struct *ps, t_arg arg)
{
	if (ps->a.size_stack <= 5)
		process_small_sort(ps, arg);
	else if (ps->a.size_stack <= 100)
		process_sort(ps, arg, 20);
	else if (ps->a.size_stack <= 200)
		process_sort(ps, arg, 28);
	else if (ps->a.size_stack <= 300)
		process_sort(ps, arg, 33);
	else if (ps->a.size_stack <= 400)
		process_sort(ps, arg, 40);
	else
		process_sort(ps, arg, ps->a.size_stack / 11);
}

int	main(int argc, char **argv)
{
	t_arg		arg;
	t_struct	*ps;
	char		**new_tab;

	if (argc == 1)
		return (0);
	new_tab = NULL;
	ps = NULL;
	if (check_parsing(&new_tab, argv, argc, 0) == 0)
	{
		arg = init_arg(new_tab, 0);
		ps = init_struct_ps(new_tab, size_tab(new_tab));
		if (check_order(&ps->a) != 0)
			choice_process(ps, arg);
		clear_struct(ps);
	}
	else
		ft_putstr_fd("Error\n", 2);
	if (new_tab != NULL)
		new_tab = free_tab_string(new_tab);
	return (0);
}
