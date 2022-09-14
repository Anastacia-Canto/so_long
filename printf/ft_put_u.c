/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:35:21 by anastacia         #+#    #+#             */
/*   Updated: 2022/08/20 13:35:29 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u(unsigned int n)
{
	int		i;
	char	*s;
	char	*base;

	i = 0;
	if (n == 0)
		return (i += ft_putstr("0"));
	base = "0123456789";
	s = ft_put_base(n, base);
	i += ft_putstr(s);
	free (s);
	return (i);
}