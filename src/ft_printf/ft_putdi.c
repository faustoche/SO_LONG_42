/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:38:40 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/12 09:35:32 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdi(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = 11;
	}
	else if (nb < 0)
	{
		len += ft_putc('-');
		len += ft_putdi(-nb);
	}
	else if (nb >= 10)
	{
		len += ft_putdi(nb / 10);
		len += ft_putdi(nb % 10);
	}
	else
		len += ft_putc(nb % 10 + '0');
	return (len);
}
