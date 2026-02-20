/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:33:13 by kbrun             #+#    #+#             */
/*   Updated: 2025/11/18 18:58:27 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sub_iterate(const char *s, char *substr, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || s[0] == '\0')
	{
		substr = malloc(sizeof(char));
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if ((start + len) > ft_strlen(s) || len > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = malloc(sizeof(char) * len + 1);
	if (substr == NULL)
		return (NULL);
	sub_iterate(s, substr, start, len);
	return (substr);
}
