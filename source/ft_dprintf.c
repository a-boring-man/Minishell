/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:28:39 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/22 11:30:30 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_putchar_fd_int(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

static int	ft_putstr_fd_int(int fd, char *s)
{
	int	i;

	i = -1;
	if (!s)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	while (s[++i])
		ft_putchar_fd(s[i], fd);
	if (i == -1)
		i++;
	return (i);
}

static int	ft_putnbr_base_fd_int(int fd, long nbr, char *base, int mode)
{
	unsigned long	unbr;
	int				r;
	int				counter;

	counter = 0;
	if (mode == 0 && nbr < 0)
	{
		unbr = -nbr;
		write(fd, "-", 1);
		++counter;
	}
	else
		unbr = *((unsigned long *)(&nbr));
	r = unbr % ft_strlen_s(base);
	if (unbr >= (unsigned int)ft_strlen_s(base))
	{
		counter += ft_putnbr_base_fd_int(fd, (unbr / ft_strlen_s(base)),
				base, mode);
	}
	ft_putchar_fd_int(fd, base[r]);
	return (counter + 1);
}

static int	ft_conversion(int fd, char i, int *t, va_list ag)
{
	if (i == 'c')
		*t += ft_putchar_fd_int(fd, va_arg(ag, int));
	if (i == 's')
		*t += ft_putstr_fd_int(fd, va_arg(ag, char *));
	if (i == 'd')
		*t += ft_putnbr_base_fd_int(fd, va_arg(ag, int), "0123456789", 0);
	if (i == 'i')
		*t += ft_putnbr_base_fd_int(fd, va_arg(ag, int), "0123456789", 0);
	if (i == 'u')
		*t += ft_putnbr_base_fd_int(fd, va_arg(ag, unsigned int),
				"0123456789", 0);
	if (i == 'x')
		*t += ft_putnbr_base_fd_int(fd, va_arg(ag, unsigned int),
				"0123456789abcdef", 1);
	if (i == 'X')
		*t += ft_putnbr_base_fd_int(fd, va_arg(ag, unsigned int),
				"0123456789ABCDEF", 1);
	if (i == '%')
		*t += ft_putchar_fd_int(fd, '%');
	if (i == 'p')
		*t += ft_putstr_fd_int(fd, "0x");
	if (i == 'p')
		*t += ft_putnbr_base_fd_int(fd, va_arg(ag, long),
				"0123456789abcdef", 1);
	return (*t);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		i;
	int		total;
	va_list	argtab;

	va_start(argtab, format);
	i = -1;
	total = 0;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			ft_conversion(fd, format[i + 1], &total, argtab);
			i++;
		}
		else
			total += ft_putchar_fd_int(fd, format[i]);
	}
	va_end(argtab);
	return (total);
}
