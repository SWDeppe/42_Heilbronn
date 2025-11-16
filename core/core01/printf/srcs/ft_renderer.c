/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 06:01:03 by sdeppe            #+#    #+#             */
/*   Updated: 2025/11/16 01:00:47 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	_print_(t_pars *parser, char *str, char sep, size_t *i)
{
	size_t	siz;

	siz = ft_strlen(str);
	if (parser->invert == TRUE)
	{
		*i = siz;
		if (str[0] == 0 && parser->type == _CHARACTER_)
			write(1, "\0", 1);
		else
			ft_putstr_fd(str, 1);
		while (*i < (size_t)parser->with)
			*i += write(1, &sep, 1);
	}
	else
	{
		while (parser->with > (int)siz && *i < parser->with - siz)
			*i += write(1, &sep, 1);
		if (str[0] == 0 && parser->type == _CHARACTER_)
			write(1, "\0", 1);
		else
			ft_putstr_fd(str, 1);
	}
	return (siz);
}

int	print_wis_with(t_pars *parser, char *str)
{
	size_t	i;
	char	sep;
	size_t	siz;

	if (str[0] == '0' && str[1] == 0
		&& parser->is_prec == TRUE && parser->precision == 0)
		str[0] = 0;
	sep = ' ';
	i = 0;
	if (str[0] == 0 && parser->type == _CHARACTER_)
		i++;
	if (parser->zero)
		sep = '0';
	siz = _print_(parser, str, sep, &i);
	return (free(str), i + siz * !parser->invert);
}

static int	render_pointer(t_pars *parser, unsigned long long ptr)
{
	char	*str;
	char	*nbr;
	size_t	v[2];

	if (ptr == 0)
	{
		if (parser->is_prec == TRUE && parser->precision < 5)
			return (print_wis_with(parser, ft_strdup("")));
		else
			return (print_wis_with(parser, ft_strdup("(nil)")));
	}
	nbr = ft_itoa_type_base(ptr, "0123456789abcdef", _TYPE_ULINT_);
	v[0] = 0;
	v[1] = ft_strlen(nbr);
	while (v[1] + v[0] < (size_t)parser->precision)
		v[0]++;
	str = malloc(v[1] + v[0] + 3);
	str[v[1] + v[0] + 2] = 0;
	while (v[1]-- > 0)
		str[v[1] + 2 + v[0]] = nbr[v[1]];
	while (v[0] != 0)
		str[--v[0] + 2] = '0';
	str[0] = '0';
	str[1] = 'x';
	return (free(nbr), print_wis_with(parser, str));
}

static int	render_percent(t_pars *parser)
{
	char	*res;
	char	buf[2];

	buf[0] = '%';
	buf[1] = 0;
	parser->with = 0;
	parser->precision = 0;
	parser->is_prec = 0;
	res = ft_strdup(buf);
	return (print_wis_with(parser, res));
}

int	ft_renderer(t_pars parser, va_list ap)
{
	int	ret;

	if (parser.zero == TRUE && parser.is_prec == TRUE)
		parser.zero = FALSE;
	ret = 0;
	if (parser.type == _CHARACTER_)
		ret = render_character(&parser, va_arg(ap, int));
	if (parser.type == _STRING_)
		ret = render_string(&parser, va_arg(ap, char *));
	if (parser.type == _POINTER_)
		ret = render_pointer(&parser, (unsigned long long)va_arg(ap, void *));
	if (parser.type == _INTEGER_)
		ret = render_integer(&parser, va_arg(ap, int));
	if (parser.type == _UINTEGER_)
		ret = render_uinteger(&parser, va_arg(ap, unsigned int));
	if (parser.type == _DECIMAL_)
		ret = render_integer(&parser, va_arg(ap, int));
	if (parser.type == _HEXA_)
		ret = render_hexa(&parser, va_arg(ap, int));
	if (parser.type == _HEXA_MAJ_)
		ret = render_hexa_maj(&parser, va_arg(ap, int));
	if (parser.type == _PERCENT_)
		ret = render_percent(&parser);
	return (ret);
}
