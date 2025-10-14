/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 10:07:30 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/12 20:22:33 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*p_dest;
	const char	*p_src;
	size_t		i;

	p_dest = dest;
	p_src = src;
	i = 0;
	while (i < n)
	{
		if (p_dest[i] != '\0')
		{
			while (i-- > 0)
				p_dest[i] = p_src[i];
			return (dest);
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}
