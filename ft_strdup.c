/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:01:25 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/28 23:31:59 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = ((char *)s)[i];
		i++;
	}
	res[len] = '\0';
	return (res);
}
