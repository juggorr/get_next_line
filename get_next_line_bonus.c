/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:50:46 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/23 16:57:22 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line_bonus.h"
#include<stdio.h>
#include<fcntl.h>	

char	*get_next_line_bonus(int fd)
{
	static	char	*buf[4096];
	char	*tmp_buf = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	ssize_t	res;

	res = read(fd, tmp_buf, BUFFER_SIZE);

	tmp_buf[res] = '\0';
	printf("res: %zd\n", res);
	printf("buf: %s\n", tmp_buf);
	return (tmp_buf);
}

int	main(void)
{
	int	fd1;
	int	fd2;
	char	*dst;

	fd1 = open("./text.txt", O_RDONLY);
	fd2 = open("./text2.txt", O_RDONLY);
	dst = get_next_line_bonus(fd1);
	dst = get_next_line_bonus(fd1);
	dst = get_next_line_bonus(fd2);
	dst = get_next_line_bonus(fd2);
}
