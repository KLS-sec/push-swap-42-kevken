/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:28:32 by kbrun             #+#    #+#             */
/*   Updated: 2025/11/18 18:40:09 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_start(const char *s1, const char *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	return (start);
}

static size_t	count_end(const char *s1, const char *set)
{
	size_t	end;

	end = ft_strlen(s1);
	while (end > 0 && ft_strchr(set, s1[end - 1]))
		end--;
	return (end);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trim;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	start = count_start(s1, set);
	end = count_end(s1, set);
	if (end <= start)
		return (ft_strdup(""));
	trim = malloc(end - start + 1);
	if (!trim)
		return (NULL);
	i = 0;
	while (end > start)
		trim[i++] = s1[start++];
	trim[i] = '\0';
	return (trim);
}
