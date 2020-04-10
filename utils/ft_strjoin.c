/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 18:08:29 by vscabell          #+#    #+#             */
/*   Updated: 2020/04/08 18:08:31 by vscabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	char	*join;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	if (!(join = malloc(sizeof(char) * (lens1 + lens2 + 1))))
		return (NULL);
	ft_memcpy(join, s1, lens1);
	i = 0;
	while (s2[i])
	{
		join[lens1 + i] = s2[i];
		i++;
	}
	join[lens1 + i] = '\0';
	free(s1);
	free(s2);
	return (join);
}