/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeppe <sdeppe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 04:18:24 by sdeppe            #+#    #+#             */
/*   Updated: 2025/10/11 05:20:30 by sdeppe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 1

int	ft_display_file(char *file_name)
{
	int		fd;
	char	buf[BUF_SIZE];
	int		read_res;

	read_res = BUF_SIZE;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (1);
	}
	read_res = read(fd, buf, BUF_SIZE);
	write(1, buf, read_res);
	if (read_res == -1)
	{
		write(2, "Cannot read file.\n", 19);
		return (1);
	}
	while (read_res)
	{
		read_res = read(fd, buf, BUF_SIZE);
		write(1, buf, read_res);
	}
	close(fd);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	return (ft_display_file(argv[1]));
}
