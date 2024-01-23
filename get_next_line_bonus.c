/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:50:46 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/23 13:19:22 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line_bonus.h"
#include<stdio.h>
#include<fcntl.h>

void	read_fd(int fd)
{
	char	*buf = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	ssize_t	res;

	res = read(fd, buf, BUFFER_SIZE);
	buf[res] = '\0';
	printf("res: %zd\n", res);
	printf("buf: %s\n", buf);
}

int	main(void)
{
	int	fd1;
	int	fd2;

	fd1 = open("./text.txt", O_RDONLY);
	fd2 = open("./text2.txt", O_RDONLY);
	read_fd(fd1);
	read_fd(fd2);
	read_fd(fd1);
	read_fd(fd2);
}
