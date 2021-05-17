/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adupuy <adupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:03:35 by adupuy            #+#    #+#             */
/*   Updated: 2021/05/15 20:08:36 by adupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (!ft_sep(s[i], c))
			if (i == 0 || ft_sep(s[i - 1], c))
				count++;
		i++;
	}
	return (count);
}

static char	*ft_new_str(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while ((!(ft_sep(s[i], c)) && s[i] != '\0'))
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while ((!(ft_sep(s[i], c)) && s[i] != '\0'))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_free_tab(char **split, int j)
{
	while (j >= 0)
	{
		free(split[j]);
		j--;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (split == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (j < ft_count_word(s, c))
	{
		if (!ft_sep(s[++i], c))
		{
			if (i == 0 || (ft_sep(s[i - 1], c)))
			{
				split[j] = ft_new_str((char *)&s[i], c);
				if (split[j++] == NULL)
					return (split = ft_free_tab(split, j - 1));
			}
		}
	}
	split[j] = NULL;
	return (split);
}
