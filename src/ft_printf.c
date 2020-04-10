/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 20:00:37 by vscabell          #+#    #+#             */
/*   Updated: 2020/04/10 18:35:47 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_specif(const char *format, va_list arg, t_bag *bag)
{
	if (format[bag->index] == 'c')
		ft_print_char(arg, bag);
	else if (format[bag->index] == 's')
		ft_print_string(arg, bag);
	else if (format[bag->index] == 'p')
		ft_print_pointer(arg, bag);
	else if (format[bag->index] == 'd' || format[bag->index] == 'i')
		ft_print_diux(arg, bag, DECA, 'i');
	else if (format[bag->index] == 'u')
		ft_print_diux(arg, bag, DECA, 'u');
	else if (format[bag->index] == 'x')
		ft_print_diux(arg, bag, HEXA_LOWER, 'x');
	else if (format[bag->index] == 'X')
		ft_print_diux(arg, bag, HEXA_UPPER, 'X');
	else
		ft_print_percent(arg, bag);
}

void	ft_convert_type(const char *format, va_list arg, t_bag *bag)
{
	bag->index++;
	while (format[bag->index] == '-' || format[bag->index] == '0')
		ft_hold_flags(format, bag);
	if (ft_isdigit(format[bag->index]) || format[bag->index] == '*')
		ft_hold_width(format, arg, bag);
	if (format[bag->index] == '.')
		ft_hold_prec(format, arg, bag);
	if (ft_isspecifier(format[bag->index]))
		ft_convert_specif(format, arg, bag);
	else
	{
		ft_putchar(0);
		bag->ret = -1;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list arg;
	t_bag	bag;

	bag.index = 0;
	bag.ret = 0;
	va_start(arg, format);
	while (format[bag.index] && bag.ret >= 0)
	{
		if (format[bag.index] == '%')
		{
			ft_reinit_var(&bag);
			ft_convert_type(format, arg, &bag);
		}
		else
		{
			ft_putchar(format[bag.index]);
			bag.ret++;
		}
		bag.index++;
	}
	va_end(arg);
	return (bag.ret);
}
