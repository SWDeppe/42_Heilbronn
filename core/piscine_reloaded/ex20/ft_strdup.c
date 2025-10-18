/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 00:14:30 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/09 22:15:46 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	ft_str_cpy(char *src, char *dest)
{
	int	strlen;
	int	i;

	strlen = 0;
	while (src[strlen])
		strlen++;
	i = 0;
	while (i < strlen)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*res;

	i = 0;
	while (src[i])
		i++;
	res = (char *)malloc(i + 1);
	if (res == NULL)
		return (0);
	ft_str_cpy(src, res);
	return (res);
}
