/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 20:00:12 by vscabell          #+#    #+#             */
/*   Updated: 2020/04/10 18:35:55 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_check_prec_ptr(char *str, t_bag *bag)
{
	int	len_str;
	int	prec;

	len_str = ft_strlen(str);
	prec = bag->prec > bag->prec_star ? bag->prec : bag->prec_star;
	if (prec > len_str)
		str = ft_strjoin(ft_calloc_char((prec - len_str), '0'), str);
	return (str);
}

char	*ft_check_width_ptr(char *str, t_bag *bag)
{
	int		width;
	int		len_wid;
	char	*ad;

	ad = ft_strjoin(ft_calloc_char(1, '0'), ft_calloc_char(1, 'x'));
	width = bag->width > bag->width_star ? bag->width : bag->width_star;
	len_wid = width - ft_strlen(str);
	if (len_wid < 2)
		return (ft_strjoin(ad, str));
	else if (bag->zero)
		str = ft_strjoin(ft_calloc_char(len_wid - 2, '0'), ft_strjoin(ad, str));
	else if (bag->minus > 0)
		str = ft_strjoin(ft_strjoin(ad, str), ft_calloc_char(len_wid - 2, ' '));
	else
		str = ft_strjoin(ft_calloc_char(len_wid - 2, ' '), ft_strjoin(ad, str));
	return (str);
}

void	ft_print_pointer(va_list arg, t_bag *bag)
{
	unsigned long long int	ptr;
	char					*str;
	char					*ad;

	ptr = (unsigned long long int)va_arg(arg, void*);
	if (ptr != 0)
		str = ft_itoa_ptr(ptr, HEXA_LOWER, 16);
	else
	{
		str = (bag->dot > 0 && bag->prec == 0 && bag->prec_star == 0) ?
		ft_strdup("") : ft_strdup("0");
	}
	if (bag->prec > 0 || bag->prec_star > 0)
		str = ft_check_prec_ptr(str, bag);
	if (bag->width > 0 || bag->width_star > 0)
		str = ft_check_width_ptr(str, bag);
	else
	{
		ad = ft_strjoin(ft_calloc_char(1, '0'), ft_calloc_char(1, 'x'));
		str = ft_strjoin(ad, str);
	}
	ft_putstr(str);
	bag->ret = bag->ret + ft_strlen(str);
	free(str);
	str = NULL;
}
