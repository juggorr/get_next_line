/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:50:46 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/25 11:39:25 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line_bonus.h"

int	read_buffer_size(int fd, char *buf)
{
	char	tmp_buf[BUFFER_SIZE + 1];
	ssize_t	res;

	if (fd < 0)
		return (-1);
	res = read(fd, tmp_buf, BUFFER_SIZE);
	tmp_buf[res] = '\0';
	ft_stricat(buf, tmp_buf);
	return (res);
}

char	*line_from_buf(char *buf, int idx)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (idx + 1));
	if (!dst)
		return (0);
	ft_strdup(dst, buf, idx);
	reset_buf_offset(buf, idx + 1);
	return (dst);
}

char	*get_next_line_bonus(int fd)
{
	static char	buf[4096];
	int			idx;
	char		*dst;
	int			res;

	idx = check_newline(buf);
	if (idx != -1)
		dst = line_from_buf(buf, idx);
	else
	{
		while (idx == -1)
		{
			res = read_buffer_size(fd, buf);
			if (res == 0)
				return (buf);
			else if (res == -1)
				return (0);
			idx = check_newline(buf);	
		}
		dst = line_from_buf(buf, idx);
	}
	if (!dst)
		return (0);
	return (dst);
}

int	main(void)
{
	int		fd1;
	char	*dst;
	char	*dst2;
	char	*dst3;
	char	*dst4;

	fd1 = open("./text.txt", O_RDONLY);
	dst = get_next_line_bonus(fd1);
	printf("dst1: %s", dst);
	dst2 = get_next_line_bonus(fd1);
	printf("dst2: %s", dst2);
	dst3 = get_next_line_bonus(fd1);
	printf("dst3: %s", dst3);
	dst4 = get_next_line_bonus(fd1);
	printf("dst4: %s", dst4);
}
