/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_type_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:45:53 by sdeppe            #+#    #+#             */
/*   Updated: 2025/11/16 00:11:48 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_base(long int n, char *base)
{
	int		i;
	char	*res;
	size_t	siz;
	long	tmp;

	i = (n == 0);
	siz = ft_strlen(base);
	tmp = n;
	if (n < 0 && i++ == 0)
		n = -n;
	while (n > 0 && i++ >= 0)
		n /= siz;
	res = malloc(i + 1);
	res[i] = 0;
	if (tmp < 0 && i >= 0)
	{
		tmp = -tmp;
		res[0] = '-';
	}
	while (--i >= 0 && res[i] != '-')
	{
		res[i] = base[tmp % siz];
		tmp /= siz;
	}
	return (res);
}

static char	*ft_uitoa_base(unsigned long int n, char *base)
{
	int				i;
	char			*res;
	size_t			siz;
	unsigned long	tmp;

	i = (n == 0);
	siz = ft_strlen(base);
	tmp = n;
	while (n > 0 && i++ >= 0)
		n /= siz;
	res = malloc(i + 1);
	res[i] = 0;
	while (--i >= 0)
	{
		res[i] = base[tmp % siz];
		tmp /= siz;
	}
	return (res);
}

static char	*set_max(char *res, char *base)
{
	char	last;
	int		i;
	char	*n_res;

	i = ft_strlen(res) - 1;
	last = base[ft_strlen(base) - 1];
	while (res[i] == last)
		res[i--] = base[0];
	if (res[i] == '-')
	{
		n_res = malloc(ft_strlen(res) + 1);
		if (n_res == NULL)
			return (NULL);
		n_res[0] = '-';
		n_res[1] = last;
		n_res[ft_strlen(res)] = 0;
		i = 2;
		while (i < (int)ft_strlen(res))
			n_res[i++] = base[0];
		return (free(res), n_res);
	}
	res[i]++;
	return (res);
}

char	*ft_itoa_type_base(long long int nbr, char *base, char type)
{
	char	*res;
	char	is_max;

	is_max = 0;
	if (type == _TYPE_INT_)
		res = ft_itoa_base((long int)nbr, base);
	else if (type == _TYPE_UINT_)
		res = ft_uitoa_base((unsigned int)nbr, base);
	else if (type == _TYPE_LINT_)
	{
		if (nbr == (long)1 << 63)
		{
			is_max = 1;
			nbr++;
		}
		res = ft_itoa_base((long int)nbr, base);
	}
	else if (type == _TYPE_ULINT_)
		res = ft_uitoa_base((unsigned long int)nbr, base);
	if (is_max)
		res = set_max(res, base);
	return (res);
}
