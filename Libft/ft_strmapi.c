/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:28:22 by kbrun             #+#    #+#             */
/*   Updated: 2025/11/20 16:26:58 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*scpy;

	if (!s || !f)
		return (NULL);
	i = 0;
	scpy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (scpy == NULL)
		return (NULL);
	while (s[i])
	{
		scpy[i] = (*f)(i, s[i]);
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}
