/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 06:45:34 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/23 07:19:57 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i]
		&& i < len)
	{
		y = 0;
		while (big[i + y] == little[y]
			&& y++ + i < len)
		{
			if (little[y] == '\0')
				return (((char *)big + i));
		}
		i++;
	}
	return (NULL);
}
