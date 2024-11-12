/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:53:44 by fcrocq            #+#    #+#             */
/*   Updated: 2024/06/15 13:36:04 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexamaj(unsigned long nb)
{
	int		len;
	char	*maj;

	len = 0;
	maj = "0123456789ABCDEF";
	if (nb > 15)
	{
		len += ft_hexamaj(nb / 16);
		len += ft_hexamaj(nb % 16);
	}
	else
		len += ft_putc(maj[nb]);
	return (len);
}

int	ft_hexamin(unsigned long nb)
{
	int		len;
	char	*min;

	len = 0;
	min = "0123456789abcdef";
	if (nb > 15)
	{
		len += ft_hexamin(nb / 16);
		len += ft_hexamin(nb % 16);
	}
	else
		len += ft_putc(min[nb]);
	return (len);
}

int	ft_putx(unsigned int n, char format)
{
	int				len;
	unsigned long	nb;

	nb = 0;
	nb = (unsigned long)n;
	len = 0;
	if (format == 'x')
		len += ft_hexamin(n);
	else if (format == 'X')
		len += ft_hexamaj(n);
	return (len);
}
