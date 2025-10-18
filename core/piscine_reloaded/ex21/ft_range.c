/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 00:26:10 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/09 23:59:56 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	*ft_range(int min, int max)
{
	int	*res;
	int	i;

	i = 0;
	if (max <= min)
		return (NULL);
	res = (int *)malloc(4 * (max - min) + 1);
	if (res == NULL)
		return (NULL);
	while (i < max - min)
	{
		res[i] = min + i;
		i++;
	}
	res[(max - min) + 1] = '\0';
	return (res);
}
