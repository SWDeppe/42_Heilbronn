/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:49:41 by sdeppe            #+#    #+#             */
/*   Updated: 2025/11/16 00:58:11 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_sign(char *nbr_res, t_pars *p, char *str)
{
	if (nbr_res[0] == '-')
		str[0] = '-';
	else if (p->plus)
		str[0] = '+';
	else if (p->space)
		str[0] = ' ';
}

int	render_integer(t_pars *p, int nbr)
{
	char	*str;
	char	*nbr_res;
	int		zeros;
	int		siz;

	nbr_res = ft_itoa(nbr);
	zeros = 0;
	siz = ft_strlen(nbr_res);
	if (p->with > siz && p->zero)
	{
		p->precision = p->with - (nbr_res[0] == '-');
		p->with = 0;
	}
	while (siz + zeros < p->precision + (nbr_res[0] == '-'))
		zeros++;
	if ((p->plus || p->space) && nbr_res[0] != '-')
		zeros++;
	str = malloc(siz + zeros + 1);
	str[siz + zeros] = 0;
	while (siz-- > 0)
		str[siz + zeros] = nbr_res[siz];
	set_sign(nbr_res, p, str);
	while (zeros != 0 + ((p->plus || p->space) && nbr_res[0] != '-'))
		str[--zeros + (nbr_res[0] == '-' || p->plus)] = '0';
	return (free(nbr_res), print_wis_with(p, str));
}

int	render_uinteger(t_pars *parser, unsigned int nbr)
{
	char	*str;
	char	*nbr_res;
	size_t	zeros;
	size_t	siz;

	nbr_res = ft_itoa_type_base(nbr, "0123456789", _TYPE_UINT_);
	zeros = 0;
	siz = ft_strlen(nbr_res);
	while (siz + zeros < (size_t)parser->precision)
		zeros++;
	str = malloc(siz + zeros + 1);
	str[siz + zeros] = 0;
	while (siz-- > 0)
		str[siz + zeros] = nbr_res[siz];
	while (zeros != 0)
		str[--zeros] = '0';
	return (free(nbr_res), print_wis_with(parser, str));
}

int	render_hexa(t_pars *parser, int nbr)
{
	char	*str;
	char	*nbr_res;
	size_t	zeros;
	size_t	siz;

	nbr_res = ft_itoa_type_base(nbr, "0123456789abcdef", _TYPE_UINT_);
	if (nbr_res[0] == '0' && nbr_res[1] == 0)
		parser->see_hex = FALSE;
	zeros = 0;
	siz = ft_strlen(nbr_res);
	while (siz + zeros < (size_t)parser->precision)
		zeros++;
	str = malloc(siz + zeros + parser->see_hex * 2 + 1);
	str[siz + zeros + parser->see_hex * 2] = 0;
	while (siz-- > 0)
		str[siz + parser->see_hex * 2 + zeros] = nbr_res[siz];
	while (zeros != 0)
		str[--zeros + parser->see_hex * 2] = '0';
	if (parser->see_hex)
	{
		str[0] = '0';
		str[1] = 'x';
	}
	return (free(nbr_res), print_wis_with(parser, str));
}

int	render_hexa_maj(t_pars *parser, int nbr)
{
	char	*str;
	char	*nbr_res;
	size_t	zeros;
	size_t	siz;

	nbr_res = ft_itoa_type_base(nbr, "0123456789ABCDEF", _TYPE_UINT_);
	if (nbr_res[0] == '0' && nbr_res[1] == 0)
		parser->see_hex = FALSE;
	zeros = 0;
	siz = ft_strlen(nbr_res);
	while (siz + zeros < (size_t)parser->precision)
		zeros++;
	str = malloc(siz + zeros + parser->see_hex * 2 + 1);
	str[siz + zeros + parser->see_hex * 2] = 0;
	while (siz-- > 0)
		str[siz + parser->see_hex * 2 + zeros] = nbr_res[siz];
	while (zeros != 0)
		str[--zeros + parser->see_hex * 2] = '0';
	if (parser->see_hex)
	{
		str[0] = '0';
		str[1] = 'X';
	}
	return (free(nbr_res), print_wis_with(parser, str));
}
