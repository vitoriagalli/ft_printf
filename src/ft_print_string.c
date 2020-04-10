/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 20:00:06 by vscabell          #+#    #+#             */
/*   Updated: 2020/04/08 11:05:43 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_prec_string(char *str, t_bag *bag)
{
	int		len_str;
	int		prec;
	char	*str_prec;

	if (bag->prec < 0)
		return (ft_strdup("\0"));
	prec = bag->prec > bag->prec_star ? bag->prec : bag->prec_star;
	len_str = ft_strlen(str);
	if (prec >= len_str)
		return (str);
	if (!(str_prec = malloc(sizeof(char) * (prec + 1))))
		return (NULL);
	ft_memcpy(str_prec, str, prec);
	str_prec[prec] = '\0';
	free(str);
	return (str_prec);
}

char	*ft_check_width_string(char *str, t_bag *bag)
{
	int	len_str;
	int len_wid;
	int width;

	width = bag->width > bag->width_star ? bag->width : bag->width_star;
	len_str = ft_strlen(str);
	len_wid = width - len_str;
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

void	ft_print_string(va_list arg, t_bag *bag)
{
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	if (bag->prec > 0 || bag->prec_star > 0)
		str = ft_check_prec_string(str, bag);
	if (bag->dot == 1 && bag->prec == 0 && bag->prec_star == 0)
	{
		free(str);
		str = ft_strdup("\0");
	}
	if (bag->width > 0 || bag->width_star > 0)
		str = ft_check_width_string(str, bag);
	ft_putstr(str);
	bag->ret = bag->ret + ft_strlen(str);
	free(str);
	str = NULL;
}
