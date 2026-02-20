/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:27:39 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/01 10:54:34 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_length(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	char	*int_to_char;

	nb = n;
	i = int_length(n);
	int_to_char = malloc(sizeof(char) * (i + 1));
	if (int_to_char == NULL)
		return (NULL);
	int_to_char[i--] = '\0';
	if (nb < 0)
		nb = -nb;
	while (i >= 0 && (!(n < 0 && i == 0)))
	{
		int_to_char[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		int_to_char[0] = '-';
	return (int_to_char);
}

/*int main ()
{
	int i, n = 0;
	char *itoa_test;
	i = int_length(n);
	itoa_test = ft_itoa(n);
	printf("%s\n", itoa_test);
	free(itoa_test);
}*/
