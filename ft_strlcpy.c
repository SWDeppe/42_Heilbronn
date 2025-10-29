/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 10:53:47 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/29 00:16:48 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	if (siz <= 0)
		return (len);
	while (i < siz - 1 && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

// int main(void)
// {
// 	char dst[100];
// 	char *src = "Hello";
// 	// dst = malloc(6);
// 	ft_strlcpy(dst, src, 6);
// 	printf("\ndest:%s\nsrc:%s\n", dst, src);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
// {
// 	size_t	i;
// 	size_t	len;

// 	len = 0;
// 	i = 0;
// 	while (src[len] != '\0')
// 		len++;
// 	if (siz <= 0)
// 		return (len);
// 	while (i < siz - 1
// 		&& i < len
// 		&& dst[i] != '\0')
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (len);
// }
