/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 10:25:05 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/12 10:50:56 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*p_dest;
	const char	*p_src;

	i = 0;
	p_dest = dest;
	p_src = src;
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}

// int main() {

//     // Initialize a variable
// 	unsigned int a = INT_MAX;
//     int b = 'b';

//     printf("Value of b before calling memcpy: %d\n", b);

//     // Use memcpy to copy the value of 'a' into 'b'
//     ft_memcpy(&b, &a, 4); 

//     printf("Value of b after calling memcpy: %d\n", b);

//     return 0;
// }