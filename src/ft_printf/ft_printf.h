/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:56:12 by fcrocq            #+#    #+#             */
/*   Updated: 2024/10/30 09:37:53 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

int	ft_putdi(int nb);
int	ft_format(va_list lst, char format);
int	ft_putc(char c);
int	ft_printf(const char *format, ...);
int	ft_hexamaj(unsigned long nb);
int	ft_hexamin(unsigned long nb);
int	ft_putx(unsigned int n, char format);
int	ft_putp(void *arg);
int	ft_hexa(unsigned long arg);
int	ft_puts(char *s);
int	ft_putun(unsigned int nb);

#endif