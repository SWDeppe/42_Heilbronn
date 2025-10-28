/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:45:26 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/27 21:47:25 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

/*  logic is to count words malloc res , then store give in v as much 
	integers as there is words + 1,
	then the forth next are iteratores(for optimisation could be 16 bits
	integers but here use 32 for security).
	v stands for variables is a bouble array that 
	+containes 3 arrays of itegers :
		v[1] -> v[words + 1] --> store the beginnings end ends
		v[words + 2] --> first iterator = i --> iterate over the string
		v[words + 3] --> second iterator = j --> iterate to find start
		v[words + 4] --> third iterator = y --> useless
		v[words + 5] --> fourth iterator = beg --> stor index of curent beginig
		v[words + 6] --> sixed iterator = end --> stor index of curent end
		*/
static char	**assigne_and_retrun(int *v, char **res, const char *s, const int b)
{
	while (v[b + 1]--)
	{
		if ((s[v[b + 1]] == '\0' || s[v[b + 1]] == v[b + 4])
			&& s[v[b + 1] - 1] != v[b + 4] && v[b + 1] != 0)
		{
			v[b + 2] = 0;
			while ((s[v[b + 1] - v[b + 2]++ - 1] != v[b + 4]
					&& s[v[b + 1] - v[b + 2]] != '\0'))
				v[v[b + 5] - 1] = v[b + 1] - v[b + 2] - 1;
			v[v[b + 6] - 1] = v[b + 1] - 1;
			res[v[b + 5] - 1] = malloc(v[v[b + 6] - 1] - v[v[b + 5] - 1] + 1);
			if (res[v[b + 5] - 1] == NULL || v[b + 6]-- == v[b + 5]--)
			{
				while (res[v[b + 5]])
					free(res[v[b + 5]++]);
				return (free(res), NULL);
			}
			res[v[b + 5]][v[v[b + 6]] - v[v[b + 5]]] = '\0';
		}
		if (s[v[b + 1]] != v[b + 4] && s[v[b + 1]] != '\0')
			res[v[b + 5]][v[b + 1] - v[v[b + 5]] - 1] = s[v[b + 1]];
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		beg;
	int		*v;

	i = 0;
	beg = 0;
	while (s[i++])
		if ((i == 0 || s[i - 1] != c) && (s[i] == c || s[i] == '\0'))
			beg++;
	res = malloc((beg + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	v = (int *)malloc((beg + 7) * sizeof(int));
	if (v == NULL)
		return (free(res), NULL);
	v[beg + 1] = i;
	v[beg + 4] = c;
	v[beg + 5] = beg;
	v[beg + 6] = beg + 1;
	res[beg] = 0;
	res = assigne_and_retrun(v, res, s, beg);
	return (free(v), res);
}

/////////////////////readable version////////////////////////
// char	**ft_split(char const *s, char c)
// {
// 	char **res;
// 	int	i;
// 	int *beginnings_and_end;
// 	int	beg;
// 	int end;
// 	int y;
// 	int j;	
// 	i = 0;
// 	beg = 0;
// 	end = 0;
// 	j = 0;
// 	while (s[i++])
// 		if ((i == 0 || s[i - 1] != c) && (s[i] == c || s[i] == '\0'))
// 			beg++;
// 	res = malloc((beg + 1) * sizeof(char *));
// 	beginnings_and_end = (int *)malloc((end = beg + 1) * 4);
// 	if (beginnings_and_end == NULL || res == NULL)
// 	{
// 		free(res);
// 		free(beginnings_and_end);
// 		return (NULL);
// 	}
// 	res[beg] = 0;
// 	while (i--)
// 	{
// 		if ((s[i] == '\0' || s[i] == c) && s[i - 1] != c && i != 0)
// 		{
// 			j = 0;
// 			while ((s[i - j++ - 1] != c && s[i - j] != '\0'))
// 				beginnings_and_end[beg - 1] = i - j - 1;
// 			beginnings_and_end[end - 1] = i - 1;
// 			res[beg - 1] = malloc(beginnings_and_end[end - 1] 
//- beginnings_and_end[beg - 1] + 1); // TODO line up
// 			if (res[beg - 1] == NULL || beg-- == end--)
// 			{
// 				while (res[beg])
// 				 	free(res[beg++]);
// 				free(res);
// 				free(beginnings_and_end);
// 				return (NULL);
// 			}
// 			res[beg][y = beginnings_and_end[end] 
// - beginnings_and_end[beg]] = '\0'; // TODO line up
// 		}
// 		if (s[i] != c && s[i] != '\0')
// 			res[beg][y-- - 1] = s[i];
// 	}
// 	free(beginnings_and_end);
// 	return (res);
// }