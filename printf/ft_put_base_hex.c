/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:32:10 by anastacia         #+#    #+#             */
/*   Updated: 2022/08/20 13:32:20 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_put_base_hex(unsigned int nb, char *base)
{
	int				len;
	size_t			len_base;
	unsigned int	n;
	char			*s;

	n = nb;
	len = 0;
	len_base = ft_strlen(base);
	while (n > 0)
	{
		n /= len_base;
		len++;
	}
	s = malloc(sizeof(*s) * (len + 1));
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	while (nb > 0)
	{
		s[--len] = base[nb % len_base];
		nb /= len_base;
	}
	return (s);
}