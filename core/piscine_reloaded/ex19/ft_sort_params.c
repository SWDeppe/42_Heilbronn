/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:11:54 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/09 20:30:24 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(int c);

void	ft_putstr_sort(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int	ft_strcmp_sort(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i]
		&& s1[i] != '\0'
		&& s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_print_arrray(int argc, char *argv[])
{
	int	i;
	int	y;

	i = 1;
	while (i < argc)
	{
		y = 0;
		while (argv[i][y] != '\0')
			ft_putchar(argv[i][y++]);
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		y;
	char	*tmp;

	i = 1;
	while (i < argc - 1)
	{
		y = 1;
		while (y < argc - 1)
		{
			if (ft_strcmp_sort(argv[y], argv[y + 1]) > 0)
			{
				tmp = argv[y];
				argv[y] = argv[y + 1];
				argv[y + 1] = tmp;
			}
			y++;
		}
		i++;
	}
	ft_print_arrray(argc, argv);
}
