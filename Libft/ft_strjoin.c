/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:28:12 by kbrun             #+#    #+#             */
/*   Updated: 2025/11/18 19:01:47 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	int		len;

	if (!s1 && !s2)
	{
		s3 = malloc(1);
		if (s3 == NULL)
			return (NULL);
		s3[0] = '\0';
		return (s3);
	}
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = ft_calloc(len, sizeof(char));
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, s1, len);
	ft_strlcat(s3, s2, len);
	return (s3);
}
/*int main()
{
char s2[] = " bbb";
char *s3 = ft_strjoin(NULL, s2);
printf("resultat : \nX%sX\n",s3);
free (s3);
return (0);
}*/
