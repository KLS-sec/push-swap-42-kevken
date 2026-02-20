/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:11:32 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/13 15:00:40 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_error.h"

int	ft_print_char_error(int c)
{
	write (2, &c, 1);
	return (1);
}

int	ft_print_str_error(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (write (2, "(null)", 6));
	while (s[count] != '\0')
	{
		write (2, &s[count], 1);
		count++;
	}
	return (count);
}

int	ft_check_pntr_error(void *ptr)
{
	unsigned long	convert;

	if (!ptr)
		return (write(2, "(nil)", 5));
	convert = (unsigned long)ptr;
	return (ft_print_str_error("0x") + ft_print_pntr_error(convert, 16));
}

int	ft_print_pntr_error(unsigned long nb, int base)
{
	int				count;
	char			*hexa;

	count = 0;
	hexa = "0123456789abcdef";
	if (nb >= (unsigned long)base)
		count += ft_print_pntr_error(nb / base, base);
	count += ft_print_char_error(hexa[nb % base]);
	return (count);
}

int	ft_print_base_error(char c, long nb, int base)
{
	int		count;
	char	*hexa;

	count = 0;
	if ((c == 'd' || c == 'i') && (nb >= INT_MAX || nb <= INT_MIN))
	{
		nb = (int)nb;
		if (nb == INT_MIN)
			return (write(2, "-2147483648", 11));
	}
	if (nb < 0)
	{
		nb = -nb;
		count += write(2, "-", 1);
	}
	hexa = "0123456789abcdef";
	if (c == 'X')
		hexa = "0123456789ABCDEF";
	if (nb >= base)
		count += ft_print_base_error(c, nb / base, base);
	count += ft_print_char_error(hexa[nb % base]);
	return (count);
}
