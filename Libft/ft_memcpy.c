/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:27:46 by kbrun             #+#    #+#             */
/*   Updated: 2025/11/14 19:48:56 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*srccpy;
	unsigned char		*destcpy;

	srccpy = (const unsigned char *)src;
	destcpy = (unsigned char *)dest;
	i = 0;
	if (n == 0)
		return (dest);
	while (i < n)
	{
		destcpy[i] = srccpy[i];
		i++;
	}
	return (dest);
}
