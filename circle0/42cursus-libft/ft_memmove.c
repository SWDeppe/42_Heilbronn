/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 10:07:30 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/28 23:35:00 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	size_t		dir;

	i = 0;
	dir = n;
	if (dest == NULL && src == NULL)
		return (dest);
	while (i < n && dir != 0)
	{
		if (dest > src)
		{
			dir--;
			((char *)dest)[dir] = ((char *)src)[dir];
		}
		else
			((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
