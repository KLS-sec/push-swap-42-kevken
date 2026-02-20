/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:11:32 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/10 17:55:47 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (write (1, "(null)", 6));
	while (s[count] != '\0')
	{
		write (1, &s[count], 1);
		count++;
	}
	return (count);
}

int	ft_check_pntr(void *ptr)
{
	unsigned long	convert;

	if (!ptr)
		return (write(1, "(nil)", 5));
	convert = (unsigned long)ptr;
	return (ft_print_str("0x") + ft_print_pntr(convert, 16));
}

int	ft_print_pntr(unsigned long nb, int base)
{
	int				count;
	char			*hexa;

	count = 0;
	hexa = "0123456789abcdef";
	if (nb >= (unsigned long)base)
		count += ft_print_pntr(nb / base, base);
	count += ft_print_char(hexa[nb % base]);
	return (count);
}

int	ft_print_base(char c, long nb, int base)
{
	int		count;
	char	*hexa;

	count = 0;
	if ((c == 'd' || c == 'i') && (nb >= INT_MAX || nb <= INT_MIN))
	{
		nb = (int)nb;
		if (nb == INT_MIN)
			return (write(1, "-2147483648", 11));
	}
	if (nb < 0)
	{
		nb = -nb;
		count += write(1, "-", 1);
	}
	hexa = "0123456789abcdef";
	if (c == 'X')
		hexa = "0123456789ABCDEF";
	if (nb >= base)
		count += ft_print_base(c, nb / base, base);
	count += ft_print_char(hexa[nb % base]);
	return (count);
}
