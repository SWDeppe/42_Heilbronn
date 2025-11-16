/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:54:43 by sdeppe            #+#    #+#             */
/*   Updated: 2025/11/16 00:59:21 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static TYPES	get_type(char curent)
{
	if (curent == _CHARACTER_)
		return (_CHARACTER_);
	if (curent == _STRING_)
		return (_STRING_);
	if (curent == _POINTER_)
		return (_POINTER_);
	if (curent == _INTEGER_)
		return (_INTEGER_);
	if (curent == _UINTEGER_)
		return (_UINTEGER_);
	if (curent == _HEXA_)
		return (_HEXA_);
	if (curent == _HEXA_MAJ_)
		return (_HEXA_MAJ_);
	if (curent == _DECIMAL_)
		return (_DECIMAL_);
	if (curent == _PERCENT_)
		return (_PERCENT_);
	return (0);
}

static _BOOL_	set_pars_first(const char *format, int *i, t_pars *res)
{
	if (format[*i] == '#')
		return (res->see_hex = TRUE);
	else if (format[*i] == '0')
		return (res->zero = TRUE);
	else if (format[*i] == '-')
		return (res->invert = TRUE);
	else if (format[*i] == ' ')
		return (res->space = TRUE);
	else if (format[*i] == '+')
		return (res->plus = TRUE);
	return (FALSE);
}

static void	set_precision(const char *format, int *i, t_pars *res)
{
	res->is_prec = TRUE;
	*i += 1;
	while (ft_isdigit(format[*i]) && !get_type(format[*i + 1]))
	{
		res->precision += format[*i] - 48;
		res->precision *= 10;
		*i += 1;
	}
	res->precision += format[*i] - 48;
	if (!ft_isdigit(format[*i]) && *i != 0)
	{
		*i -= 1;
		res->precision = 0;
	}
}

static void	set_pars_second(const char *format, int *i, t_pars *res)
{
	if (format[*i] == '.')
		set_precision(format, i, res);
	else if (ft_isdigit(format[*i]))
	{
		while (ft_isdigit(format[*i])
			&& (format[*i + 1] != '.' && !get_type(format[*i + 1])))
		{
			res->with += format[*i] - '0';
			res->with *= 10;
			*i += 1;
		}
		res->with += format[*i] - '0';
	}
}

t_pars	pars(const char *format, int *i)
{
	t_pars	res;
	_BOOL_	is_beg;

	is_beg = TRUE;
	ft_memset(&res, 0, sizeof(t_pars));
	*i += 1;
	while (!get_type(format[*i]))
	{
		if (is_beg)
			is_beg = set_pars_first(format, i, &res);
		if (!is_beg)
			set_pars_second(format, i, &res);
		*i += 1;
	}
	res.type = get_type(format[*i]);
	return (res);
}
