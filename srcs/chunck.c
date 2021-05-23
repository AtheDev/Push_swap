/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:08:09 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/23 15:27:16 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	value_chunck(int *tab, int *tmp, int size_stack, int *nb_int_chunck)
{
	int		i;
	int		count;
	int		nb;

	nb = 20;
	if (size_stack > 400)
		nb = size_stack / 11;
	else if (size_stack > 300)
		nb = 40;
	else if (size_stack > 200)
		nb = 33;
	else if (size_stack > 100)
		nb = 28;
	i = 0;
	count = 0;
	while (i < size_stack)
	{
		tab[count] = tmp[i];
		i += nb;
		if (i < size_stack)
			nb_int_chunck[count] = nb;
		else
			nb_int_chunck[count] = size_stack - (count * nb);
		count++;
	}
}

int	*get_chunck(t_stack *a, t_arg arg, int nb_chunck, int **nb_int_chunck)
{
	int		*tab;
	int		i;
	int		*tmp;

	tmp = copy_stack(a);
	sort_tab_int(tmp, a->size_stack);
	tab = malloc(sizeof(int) * nb_chunck);
	*nb_int_chunck = malloc(sizeof(int) * nb_chunck);
	if (tab == NULL || nb_int_chunck == NULL)
		return (NULL);
	value_chunck(tab, tmp, a->size_stack, *nb_int_chunck);
	free(tmp);
	return (tab);
}

void	sort_with_chunck(int min, int max, t_struct *ps, int nb_int_chunck)
{
	t_pos	pos;

	while (nb_int_chunck > 0)
	{
		pos.min = min;
		pos.max = max;
		search_pos(&pos, &ps->a, 0);
		process_push_stack_b(&pos, ps, 0);
		nb_int_chunck--;
	}
}
