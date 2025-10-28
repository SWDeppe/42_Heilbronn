/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 23:08:59 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/23 23:33:46 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (ft_strlen(s) <= start)
	{
		len = 0;
		start = 0;
	}
	if (ft_strlen(&s[start]) <= len)
		len = ft_strlen(&s[start]);
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[len] = 0;
	return (res);
}
