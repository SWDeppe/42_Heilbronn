/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 10:07:50 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/12 10:10:35 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *restrict src, size_t dsize){
	size_t 	i;
	size_t	len;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	while (dst[len] != '\0')
		len++;
	while (i < dsize)
	{
		dst[i] = src[i];
		i++;
	}
	return (len);
}