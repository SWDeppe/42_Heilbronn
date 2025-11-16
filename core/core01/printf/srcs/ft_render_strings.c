/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:49:37 by sdeppe            #+#    #+#             */
/*   Updated: 2025/11/16 00:02:27 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	render_character(t_pars *parser, int c)
{
	char	*res;
	char	buf[2];

	buf[0] = c;
	buf[1] = 0;
	res = ft_strdup(buf);
	return (print_wis_with(parser, res));
}

int	render_string(t_pars *parser, char *str)
{
	char	*res;

	if (str == NULL)
	{	
		if (parser->is_prec == TRUE && parser->precision < 6)
			return (print_wis_with(parser, ft_strdup("")));
		else
			return (print_wis_with(parser, ft_strdup("(null)")));
	}
	res = ft_strdup(str);
	if (parser->precision < (int)ft_strlen(res) && parser->is_prec)
		res[parser->precision] = '\0';
	return (print_wis_with(parser, res));
}
