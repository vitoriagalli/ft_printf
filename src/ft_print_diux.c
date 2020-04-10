/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 20:00:30 by vscabell          #+#    #+#             */
/*   Updated: 2020/04/10 18:36:18 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_check_diux(char *str, t_bag *bag)
{
	if (str && (bag->prec > 0 || bag->prec_star > 0))
		str = ft_check_prec(str, bag);
	if (bag->width > 0 || bag->width_star > 0)
		str = ft_check_width(str, bag);
	return (str);
}

char	*ft_check_di_neg(char *str, t_bag *bag)
{
	if (str && (bag->prec > 0 || bag->prec_star > 0))
		str = ft_check_prec_int_neg(str, bag);
	if (bag->width > 0 || bag->width_star > 0)
		str = ft_check_width_int_neg(str, bag);
	if (bag->width == 0 && bag->width_star == 0 &&
			bag->prec == 0 && bag->prec_star == 0)
		str = ft_strjoin(ft_calloc_char(1, '-'), str);
	return (str);
}

long	ft_type_specifier(va_list arg, char c)
{
	int				inte;
	unsigned int	u_inte;
	long			num;

	inte = 0;
	u_inte = 0;
	num = 0;
	if (c == 'i' || c == 'x' || c == 'X')
	{
		inte = va_arg(arg, int);
		num = inte;
	}
	if (c == 'u')
	{
		u_inte = va_arg(arg, unsigned int);
		num = u_inte;
	}
	return (num);
}

void	ft_print_diux(va_list arg, t_bag *bag, char *base, char c)
{
	char	*str;
	long	num;
	int		is_negative;

	num = ft_type_specifier(arg, c);
	is_negative = (c == 'i' && num < 0) ? 1 : 0;
	num = (c == 'i' && num < 0) ? num * -1 : num;
	bag->prec_star = bag->prec_star < 0 ? 1 : bag->prec_star;
	if (num == 0 && bag->prec == 0 && bag->prec_star == 0 && bag->dot > 0)
		str = ft_strdup("\0");
	else
		str = ft_itoa_base(num, base, ft_strlen(base));
	if (is_negative > 0 && c == 'i')
		str = ft_check_di_neg(str, bag);
	else
		str = ft_check_diux(str, bag);
	ft_putstr(str);
	bag->ret = bag->ret + ft_strlen(str);
	free(str);
	str = NULL;
}
