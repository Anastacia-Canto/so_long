/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:40:14 by anastacia         #+#    #+#             */
/*   Updated: 2022/08/22 08:58:32 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	conversion(va_list args, char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar((char)va_arg(args, int));
	else if (format == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		i += ft_put_pointer(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		i += ft_put_di(va_arg(args, int));
	else if (format == 'u')
		i += ft_put_u(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		i += ft_put_hex(va_arg(args, int), format);
	else if (format == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		index;

	if (!format)
		return (0);
	va_start(args, format);
	index = 0;
	i = 0;
	while (format[index])
	{
		if (format[index] == '%')
			i += conversion(args, format[++index]);
		else
			i += ft_putchar(format[index]);
		index++;
	}
	va_end(args);
	return (i);
}

