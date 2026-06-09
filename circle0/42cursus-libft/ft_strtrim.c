/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 00:21:38 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/26 00:07:34 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	v is 4 differente varibles 
	v[0] = beginnig -> where to begin the creation of res
	v[1] = end -> where to end the creation of res
	v[2] = i -> simple itrator over set
	v[3] = y -> another iterator over s1(depending on beg and end)
	
	the idea is to iterate over the string and check from both sides at the time
	then alloc and assign depending on v[0] and v[1]
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	v[4];
	char	*res;

	v[0] = 0;
	v[1] = 0;
	v[3] = 0;
	while (ft_strlen(s1) / 2 > v[3] && ft_strlen(s1) > v[0] + v[1])
	{
		v[2] = 0;
		while (set[v[2]] && ft_strlen(s1) > v[0] + v[1])
		{
			v[1] += set[v[2]] == s1[ft_strlen(s1) - (v[1] + 1)];
			if (v[0] + v[1] < ft_strlen(s1))
				v[0] += s1[v[0]] == set[v[2]];
			v[2]++;
		}
		v[3]++;
	}
	res = (char *)malloc(ft_strlen(s1) - (v[1] + v[0]) + 1);
	if (res == NULL)
		return (NULL);
	res[ft_strlen(s1) - (v[1] + v[0])] = 0;
	while (ft_strlen(s1) - (v[1]++ + v[0]))
		res[ft_strlen(s1) - (v[1] + v[0])] = s1[ft_strlen(s1) - v[1]];
	return (res);
}
