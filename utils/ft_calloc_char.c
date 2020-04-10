/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 10:10:34 by vscabell          #+#    #+#             */
/*   Updated: 2020/04/08 10:15:15 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc_char(size_t count, char c)
{
	void	*ptr;
	size_t	mem;

	mem = count * sizeof(char);
	if (!(ptr = malloc(mem + 1)))
		return (NULL);
	ft_memset(ptr, c, mem);
	return (ptr);
}
