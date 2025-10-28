/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 04:32:13 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/28 23:18:32 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	current;

	i = 0;
	current = -1;
	if ((unsigned char)c == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			current = i;
		i++;
	}
	if (current != -1)
		return ((char *)s + current);
	return (NULL);
}
