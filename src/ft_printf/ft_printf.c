/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:26:54 by fcrocq            #+#    #+#             */
/*   Updated: 2024/11/12 09:21:59 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list lst, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += (char)ft_putc(va_arg(lst, int));
	else if (format == 's')
		len += ft_puts(va_arg(lst, char *));
	else if (format == 'p')
		len += ft_putp(va_arg(lst, void *));
	else if (format == 'd' || format == 'i')
		len += ft_putdi(va_arg(lst, int));
	else if (format == 'u')
		len += ft_putun(va_arg(lst, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_putx(va_arg(lst, int), format);
	else if (format == '%')
			len += ft_putc('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	lst;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(lst, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_format(lst, format[i]);
		}
		else
			len += ft_putc(format[i]);
		i++;
	}
	va_end(lst);
	return (len);
}
