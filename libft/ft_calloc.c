/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:31:10 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/16 11:01:31 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*new;
	size_t	i;

	size *= count;
	new = malloc(sizeof(char) * size);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = 0;
		i++;
	}
	return ((void *)new);
}
