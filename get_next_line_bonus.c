/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:50:46 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/19 17:44:31 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line_bonus.h"
#include<stdio.h>
#include<fcntl.h>

void	read_fd(int fd)
{
	char	buf[BUFFER_SIZE];
	ssize_t	res;

	res = read(fd, buf, BUFFER_SIZE);
	printf("%s\n", buf);
}

int	main(void)
{
	int	fd0 = open("./text.txt", O_RDONLY);
	int	fd2 = open("./text2.txt", O_RDONLY);

	read_fd(fd0);
}
