/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:32:49 by anastacia         #+#    #+#             */
/*   Updated: 2022/08/20 13:32:59 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_put_base_pointer(unsigned long address, char *base)
{
	int				len;
	unsigned long	n;
	char			*s;
	size_t			len_base;

	len = 0;
	n = address;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	s = malloc(sizeof(*s) * len + 1);
	if (s == NULL)
		return (NULL);
	len_base = ft_strlen(base);
	s[len] = '\0';
	len--;
	while (address > 0)
	{
		s[len] = base[address % len_base];
		address /= len_base;
		len--;
	}
	return (s);
}