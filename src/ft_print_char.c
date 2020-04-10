/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 19:56:26 by vscabell          #+#    #+#             */
/*   Updated: 2020/04/08 10:29:46 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_width_char(char ch, t_bag *bag)
{
	int		width;
	char	*str;

	width = bag->width > bag->width_star ? bag->width : bag->width_star;
	str = ft_calloc_char(width - 1, ' ');
	if (bag->minus > 0)
	{
		ft_putchar(ch);
		ft_putstr(str);
	}
	else
	{
		ft_putstr(str);
		ft_putchar(ch);
	}
	bag->ret = bag->ret + width;
	free(str);
}

void	ft_print_char(va_list arg, t_bag *bag)
{
	char ch;

	ch = va_arg(arg, int);
	if (bag->width > 0 || bag->width_star > 0)
		ft_check_width_char(ch, bag);
	else
	{
		ft_putchar(ch);
		bag->ret++;
	}
}
