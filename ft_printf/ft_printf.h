/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:57:42 by kbrun             #+#    #+#             */
/*   Updated: 2025/12/03 18:53:52 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *s, ...);
int	print_conditions(char c, va_list argp);
int	ft_print_char(int c);
int	ft_print_str(char *s);
int	ft_print_base(char c, long nb, int base);
int	ft_check_pntr(void *ptr);
int	ft_print_pntr(unsigned long nb, int base);

#endif