/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:33:58 by anastacia         #+#    #+#             */
/*   Updated: 2022/08/20 13:34:06 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned int n, char format)
{
	int				i;
	char			*base;
	char			*s;

	i = 0;
	if (n == 0)
		return (i += ft_putchar('0'));
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	s = ft_put_base_hex(n, base);
	i += ft_putstr(s);
	free (s);
	return (i);
}