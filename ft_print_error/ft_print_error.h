/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrun <kbrun@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:57:42 by kbrun             #+#    #+#             */
/*   Updated: 2026/02/13 14:59:06 by kbrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_ERROR_H
# define FT_PRINT_ERROR_H
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_print_error(const char *s, ...);
int	print_conditions_error(char c, va_list argp);
int	ft_print_char_error(int c);
int	ft_print_str_error(char *s);
int	ft_print_base_error(char c, long nb, int base);
int	ft_check_pntr_error(void *ptr);
int	ft_print_pntr_error(unsigned long nb, int base);

#endif