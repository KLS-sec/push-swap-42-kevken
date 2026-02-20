/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:27:15 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/18 14:23:01 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	value;
	int	sign;

	i = 0;
	value = 0;
	sign = 1;
	if (!((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32 || nptr[i] == 45
			|| nptr[i] == 43 || (nptr[i] >= '0' && nptr[i] <= '9')))
		return (0);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == 45)
		sign = -sign;
	if (nptr[i] == 45 || nptr[i] == 43)
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = value * 10 + (nptr[i] - '0');
		i++;
	}
	return (value * sign);
}
/*int main ()
{
	char	*nb = "+42";
	printf("%d\n", ft_atoi(nb));
	return (0);
}*/