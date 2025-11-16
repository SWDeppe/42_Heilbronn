/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 10:07:50 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/18 17:28:31 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *restrict src, size_t dsize)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = 0;
	dst_len = 0;
	while (dst[dst_len])
		dst_len++;
	if (dst_len >= dsize)
		return (ft_strlen(src) + dsize);
	while (dst_len + 1 != dsize && src[src_len])
		dst[dst_len++] = src[src_len++];
	dst[dst_len] = '\0';
	return ((ft_strlen(src) - src_len) + dst_len);
}
