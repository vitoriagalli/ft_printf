/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 09:31:04 by vscabell          #+#    #+#             */
/*   Updated: 2020/04/10 18:36:35 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_check_prec(char *str, t_bag *bag)
{
	int	len_str;
	int	prec;

	len_str = ft_strlen(str);
	prec = bag->prec > bag->prec_star ? bag->prec : bag->prec_star;
	if (prec > len_str)
		str = ft_strjoin(ft_calloc_char((prec - len_str), '0'), str);
	return (str);
}

char	*ft_check_width(char *str, t_bag *bag)
{
	int	len_wid;
	int	width;

	width = bag->width > bag->width_star ? bag->width : bag->width_star;
	len_wid = width - ft_strlen(str);
	if (len_wid < 0)
		return (str);
	else if (bag->zero > 0)
		str = ft_strjoin(ft_calloc_char(len_wid, '0'), str);
	else if (bag->minus > 0)
		str = ft_strjoin(str, ft_calloc_char(len_wid, ' '));
	else
		str = ft_strjoin(ft_calloc_char(len_wid, ' '), str);
	return (str);
}

char	*ft_check_prec_int_neg(char *str, t_bag *bag)
{
	int	len_str;
	int	prec;

	len_str = ft_strlen(str);
	prec = bag->prec > bag->prec_star ? bag->prec : bag->prec_star;
	if (prec > len_str)
		str = ft_strjoin(ft_calloc_char((prec - len_str), '0'), str);
	if (bag->width == 0 && bag->width_star == 0)
		str = ft_strjoin(ft_calloc_char(1, '-'), str);
	return (str);
}

char	*ft_check_width_int_neg(char *str, t_bag *bag)
{
	int len_wid;
	int width;

	width = bag->width > bag->width_star ? bag->width : bag->width_star;
	len_wid = width - ft_strlen(str);
	if (len_wid <= 0)
		str = ft_strjoin(ft_calloc_char(1, '-'), str);
	else if (bag->zero > 0)
		str = ft_strjoin((ft_strjoin(ft_calloc_char(1, '-'),
		ft_calloc_char(len_wid - 1, '0'))), str);
	else
	{
		str = ft_strjoin(ft_calloc_char(1, '-'), str);
		len_wid--;
		if (len_wid < 0)
			return (str);
		str = (bag->minus > 0) ? ft_strjoin(str, ft_calloc_char(len_wid, ' '))
		: ft_strjoin(ft_calloc_char(len_wid, ' '), str);
	}
	return (str);
}
