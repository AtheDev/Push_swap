/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 21:43:27 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/24 11:03:59 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*my_strjoin(char *s1, char *s2, int i, int j)
{
	char	*str;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	i = ft_strlen(s1);
	str = malloc(sizeof(char) * (i + j + 2));
	if (str == NULL)
	{
		free(s1);
		return (NULL);
	}
	str[i + j + 1] = '\0';
	str[i + j] = ' ';
	while (--j >= 0)
		str[i + j] = s2[j];
	while (--i >= 0)
		str[i] = s1[i];
	if (s1)
		free(s1);
	return (str);
}

char	**free_tab_string(char **tab_string)
{
	int		i;

	i = -1;
	while (tab_string[++i] != NULL)
	{
		free(tab_string[i]);
		tab_string[i] = NULL;
	}
	free(tab_string);
	tab_string = NULL;
	return (NULL);
}

int	process_split(char ***new, char *str)
{
	*new = ft_split(str, ' ');
	if (*new == NULL)
		return (1);
	return (0);
}
