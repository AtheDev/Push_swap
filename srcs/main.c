/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:14:35 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/18 19:31:24 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		process_sort(ps, arg, 20);
	else if (ps->a.size_stack <= 500)
		process_sort(ps, arg, 40);
	clear_struct(ps);
	return (0);
}
