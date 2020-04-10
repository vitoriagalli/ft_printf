/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reinit_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 20:02:28 by vscabell          #+#    #+#             */
/*   Updated: 2020/04/10 18:35:44 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_reinit_var(t_bag *bag)
{
	bag->zero = 0;
	bag->minus = 0;
	bag->width_star = 0;
	bag->prec_star = 0;
	bag->width = 0;
	bag->prec = 0;
	bag->dot = 0;
}
