/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 20:03:08 by vscabell          #+#    #+#             */
/*   Updated: 2020/04/07 21:06:47 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(unsigned int nbr, int size_base)
{
	int			len;
	long int	n;

	n = nbr;
	len = 1;
	while (n / size_base > 0)
	{
		n = n / size_base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(long long n, char *base, int size_base)
{
	unsigned int			nbr;
	char					*itoa;
	int						len;

	len = ft_nbrlen(n, size_base);
	nbr = n;
	if (!(itoa = malloc((len + 1) * sizeof(char))))
		return (NULL);
	itoa[len] = '\0';
	len--;
	while (nbr / size_base > 0)
	{
		itoa[len] = base[nbr % size_base];
		nbr = nbr / size_base;
		len--;
	}
	itoa[len] = base[nbr % size_base];
	return (itoa);
}
