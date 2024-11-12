/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:07:46 by fcrocq            #+#    #+#             */
/*   Updated: 2024/06/17 16:10:36 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putp(void *arg)
{
	int				count;
	unsigned long	arg2;

	count = 0;
	arg2 = (unsigned long)arg;
	if (arg == 0)
		return (write(1, "(nil)", 5));
	count += ft_puts("0x");
	count += ft_hexa(arg2);
	return (count);
}

int	ft_hexa(unsigned long arg)
{
	int		count;
	char	*hexa;

	count = 0;
	hexa = "0123456789abcdef";
	if (arg > 15)
	{
		count += ft_hexa(arg / 16);
		count += ft_hexa(arg % 16);
	}
	else
		count += ft_putc(hexa[arg]);
	return (count);
}
