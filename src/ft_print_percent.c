/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 20:00:20 by vscabell          #+#    #+#             */
/*   Updated: 2020/04/08 11:04:58 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent(va_list arg, t_bag *bag)
{
	char	*str;

	(void)arg;
	str = ft_calloc_char(1, '%');
	if (bag->prec > 0 || bag->prec_star > 0)
		str = ft_check_prec(str, bag);
	if (bag->width > 0 || bag->width_star > 0)
		str = ft_check_width(str, bag);
	ft_putstr(str);
	bag->ret = bag->ret + ft_strlen(str);
	free(str);
	str = NULL;
}
