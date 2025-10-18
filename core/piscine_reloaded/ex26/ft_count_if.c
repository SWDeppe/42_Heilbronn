/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 02:48:59 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/10 02:58:17 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	counter;

	i = 1;
	counter = 0;
	if ((*f)(tab[0]) == 1)
		counter++;
	while (tab[i] != 0)
	{
		if ((*f)(tab[i]) == 1)
			counter++;
		i++;
	}
	return (counter);
}
