/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 06:23:01 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/23 06:31:40 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (i + 1 < n
		&& (unsigned char)*((char *)s1 + i)
		== (unsigned char)*((char *)s2 + i))
		i++;
	return ((unsigned char)*((char *)s1 + i)
		- (unsigned char)*((char *)s2 + i));
}
