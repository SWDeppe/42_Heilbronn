/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:28:25 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/28 23:46:03 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"
// the iterator will be set at the the number of character
static char	*assigne_char_to_num(int i, long int n, char *res)
{
	int	neg;

	neg = 0;
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
		neg++;
	}
	while (i >= 0 + neg)
	{
		res[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		cpy;

	i = 1;
	cpy = n;
	cpy /= 10;
	while (cpy)
	{
		i++;
		cpy /= 10;
	}
	if (n < 0)
		i++;
	res = malloc(i + 1);
	if (res == NULL)
		return (NULL);
	res[i--] = '\0';
	return (assigne_char_to_num(i, (long int)n, res));
}
