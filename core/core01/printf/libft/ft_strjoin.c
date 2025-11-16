/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 23:37:24 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/30 08:30:51 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*res;

	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res == NULL)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	res[i] = '\0';
	while (i-- > 0)
	{
		if (i < ft_strlen(s1))
			res[i] = s1[i];
		else
			res[i] = s2[i - ft_strlen(s1)];
	}
	return (res);
}
