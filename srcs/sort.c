/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:21:35 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/18 19:22:50 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	loop_sort(t_struct *ps, t_chunck chunck, t_arg arg)
{
	int		i;

	i = 0;
	while (chunck.nb_chunck > 0)
	{
		if (chunck.nb_chunck == 1)
			sort_with_chunck
				(chunck.tab[i], arg.arg_max + 1, ps, chunck.nb_int_chunck[i]);
		else
			sort_with_chunck
				(chunck.tab[i], chunck.tab[i + 1], ps, chunck.nb_int_chunck[i]);
		chunck.nb_chunck--;
		i++;
	}
}

void	process_sort(t_struct *ps, t_arg arg, int div)
{
	t_chunck	chunck;

	chunck.nb_chunck = ps->a.size_stack / div;
	if (ps->a.size_stack % div != 0)
		chunck.nb_chunck++;
	chunck.tab = get_chunck
		(&ps->a, arg, chunck.nb_chunck, &chunck.nb_int_chunck);
	loop_sort(ps, chunck, arg);
	push_max_in_stack_b(arg.arg_max, ps);
	while (ps->b.size_stack > 0)
		push(&ps->a, &ps->b, 'a');
	free(chunck.tab);
	free(chunck.nb_int_chunck);
}
