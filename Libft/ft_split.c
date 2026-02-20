/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:28:02 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/18 14:59:04 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	free_all(char **tab, size_t idx)
{
	while (idx > 0)
	{
		idx--;
		free(tab[idx]);
	}
	free(tab);
}

static void	split_all(const char *s, char c, char **every_split, size_t words)
{
	size_t	i;
	size_t	idx;
	size_t	start;

	i = 0;
	idx = 0;
	while (s[i] && idx < words)
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			every_split[idx] = ft_substr(s, start, i - start);
			if (!every_split[idx])
			{
				free_all(every_split, idx);
			}
			idx++;
		}
	}
	every_split[idx] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**every_split;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	every_split = malloc(sizeof(char *) * (words + 1));
	if (!every_split)
		return (NULL);
	split_all(s, c, every_split, words);
	return (every_split);
}
