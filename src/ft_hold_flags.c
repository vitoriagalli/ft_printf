/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hold_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 10:32:26 by vscabell          #+#    #+#             */
/*   Updated: 2020/04/10 18:36:30 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_hold_flags(const char *format, t_bag *bag)
{
	if (format[bag->index] == '-' && bag->zero == 1)
	{
		bag->minus = 1;
		bag->zero = 0;
	}
	if (format[bag->index] == '-')
		bag->minus = 1;
	else if ((format[bag->index] == '0') && bag->minus == 0)
		bag->zero = 1;
	bag->index++;
}

void	ft_hold_width(const char *format, va_list arg, t_bag *bag)
{
	int n;

	n = 0;
	if (format[bag->index] == '*')
	{
		bag->width_star = va_arg(arg, int);
		if (bag->width_star < 0)
		{
			bag->minus = 1;
			bag->zero = 0;
			bag->width_star = bag->width_star * -1;
		}
		bag->index++;
	}
	else
	{
		while (ft_isdigit(format[bag->index]))
		{
			n = 10 * n + (format[bag->index] - '0');
			bag->index++;
		}
		bag->width = n;
	}
}

void	ft_hold_prec(const char *format, va_list arg, t_bag *bag)
{
	int n;

	n = 0;
	bag->index++;
	bag->dot = 1;
	if (format[bag->index] == '*')
	{
		bag->prec_star = va_arg(arg, int);
		bag->index++;
	}
	else
	{
		while (ft_isdigit(format[bag->index]))
		{
			n = 10 * n + (format[bag->index] - '0');
			bag->index++;
		}
		bag->prec = n;
	}
	if (bag->prec >= 0 && bag->prec_star >= 0)
		bag->zero = 0;
}
