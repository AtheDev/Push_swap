/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 21:41:06 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/24 09:32:22 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int		i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (i == 0 && (str[i] == '-'))
			i++;
		else
		{
			if (ft_isdigit(str[i]) == 0)
				return (1);
			i++;
		}
	}
	if (i == 1 && (str[0] == '-'))
		return (1);
	return (0);
}

int	out_of_bounds(char *str)
{
	long long	num;

	num = ft_atoi(str);
	if (num > MAX_INT || num < MIN_INT)
		return (1);
	return (0);
}

int	check_duplicate(char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (tab[i + 1] != NULL)
	{
		while (tab[j] != NULL)
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	check_arg(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (is_number(tab[i]) == 1)
			return (1);
		if (out_of_bounds(tab[i]) == 1)
			return (1);
		i++;
	}
	if (check_duplicate(tab) != 0)
		return (1);
	return (0);
}

int	check_parsing(char ***new, char **argv, int argc, int i)
{
	char	*str;

	str = NULL;
	if (argc == 2)
	{
		*new = ft_split(argv[1], ' ');
		if (*new == NULL)
			return (1);
	}
	else if (argc > 2)
	{
		while (argv[++i] != NULL)
		{
			str = my_strjoin(str, argv[i], 0, ft_strlen(argv[i]));
			if (str == NULL)
				return (1);
		}
		*new = ft_split(str, ' ');
		if (str != NULL)
			free(str);
		if (*new == NULL)
			return (1);
	}
	if (*new != NULL)
		return (check_arg(*new));
	else
		return (check_arg(argv + 1));
}
