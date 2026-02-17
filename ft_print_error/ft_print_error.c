/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:57:24 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/13 14:58:02 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_error.h"

int	print_conditions_error(char c, va_list argp)
{
	int	count;

	count = 0;
	if (c == '%')
		count += write (2, &c, 1);
	else if (c == 'c')
		count += ft_print_char_error(va_arg(argp, int));
	else if (c == 's')
		count += ft_print_str_error(va_arg(argp, char *));
	else if (c == 'x' || c == 'X')
		count += ft_print_base_error(c, va_arg(argp, unsigned int), 16);
	else if (c == 'd' || c == 'i')
		count += ft_print_base_error(c, va_arg(argp, int), 10);
	else if (c == 'u')
		count += ft_print_base_error(c, va_arg(argp, unsigned int), 10);
	else if (c == 'p')
		count += ft_check_pntr_error(va_arg(argp, void *));
	return (count);
}

int	ft_print_error(const char *s, ...)
{
	int		count;
	int		i;
	va_list	argp;

	count = 0;
	i = 0;
	va_start(argp, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			count += print_conditions_error(s[i + 1], argp);
			i = i + 2;
		}
		else
		{
			count += write (2, &s[i], 1);
			i++;
		}
	}
	va_end(argp);
	return (count);
}

/*#include <stdio.h>

int	main(void)
{
	char			c = 'c';
	char			*str = "test";
	int				d = 4;
	int				i = 42;
	unsigned int	u = 421865645;
	unsigned int	x = 255;
	unsigned int	X = 255;
	unsigned long	p = 4294967295;
	

	ft_printf("MON PRINTF\n");
	ft_printf("test pour:%c\n", c);
	ft_printf("test pour:%s\n", str);
	ft_printf("test pour:%d\n", d);
	ft_printf("test pour:%i\n", i);
	ft_printf("test pour:%u\n", u);
	ft_printf("test pour:%x\n", x);
	ft_printf("test pour:%X\n", X);
	ft_printf("test pour:%p\n", &p);

	printf("\nVrai PRINTF\n");
	printf("test pour:%c\n", c);
	printf("test pour:%s\n", str);
	printf("test pour:%d\n", d);
	printf("test pour:%i\n", i);
	printf("test pour:%u\n", u);
	printf("test pour:%x\n", x);
	printf("test pour:%X\n", X);
	printf("test pour:%p\n", &p);
}*/
