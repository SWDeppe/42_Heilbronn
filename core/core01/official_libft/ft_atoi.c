/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 07:23:52 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/28 23:34:21 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_skip(char c)
{
	if ((c <= 13 && c >= 9)
		|| c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		res;
	char	sine;

	i = 0;
	res = 0;
	sine = 1;
	while (is_skip(nptr[i])
		|| (nptr[i] == '+' && ft_isdigit(nptr[i + 1]))
		|| (nptr[i] == '-' && ft_isdigit(nptr[i + 1])))
	{
		if (nptr[i] == '-' && ft_isdigit(nptr[i + 1]))
			sine = -1;
		i++;
	}
	while (nptr[i] == '0')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		res *= 10;
		res += nptr[i] - 48;
		i++;
	}
	return (res * sine);
}
