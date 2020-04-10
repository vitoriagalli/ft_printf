/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 20:00:54 by vscabell          #+#    #+#             */
/*   Updated: 2020/04/07 21:07:52 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen_ptr(unsigned long long int nbr, int size_base)
{
	int					len;
	long long int		n;

	n = nbr;
	len = 1;
	while (n / size_base > 0)
	{
		n = n / size_base;
		len++;
	}
	return (len);
}

char		*ft_itoa_ptr(long long int n, char *base, int size_base)
{
	unsigned long long int	nbr;
	char					*itoa;
	int						len;

	len = ft_nbrlen_ptr(n, size_base);
	nbr = (unsigned long long int)n;
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
