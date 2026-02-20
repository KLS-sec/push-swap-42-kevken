/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:27:48 by kbrun             #+#    #+#             */
/*   Updated: 2025/11/18 18:35:25 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*srccpy;
	unsigned char		*destcpy;

	srccpy = (const unsigned char *)src;
	destcpy = (unsigned char *)dest;
	if (n == 0)
		return (dest);
	if (destcpy > srccpy)
	{
		while (n > 0)
		{
			destcpy[n - 1] = srccpy[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(destcpy, srccpy, n);
	return (dest);
}
/*int main(void)
{
	char	bytes[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
	char	src[10] = {42, 43, 44};

	ft_memmove(bytes, src, 3 * sizeof(char));
	for (int i = 0; i < 10; i++)
		if (bytes[i])
			printf("%c ", bytes[i]);
		else
			printf("\\0 ");
}*/