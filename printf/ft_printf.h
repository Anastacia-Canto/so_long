/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastacia <anastacia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 05:49:33 by anastacia         #+#    #+#             */
/*   Updated: 2022/08/20 07:21:37 by anastacia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_put_di(int n);
int		ft_put_u(unsigned int n);
char	*ft_put_base(unsigned int n, char *base);
int		ft_put_pointer(void *p);
char	*ft_put_base_pointer(unsigned long address, char *base);
int		ft_put_hex(unsigned int n, char format);
char	*ft_put_base_hex(unsigned int nb, char *base);

#endif