/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:50:46 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/24 17:15:25 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line_bonus.h"

void	read_buffer_size(int fd, char *buf)
{
	char	tmp_buf[BUFFER_SIZE + 1];
	ssize_t	res;

	res = read(fd, tmp_buf, BUFFER_SIZE);
	tmp_buf[res] = '\0';
	ft_stricat(buf, tmp_buf);
}

char	*get_next_line_bonus(int fd)
{
	static char	buf[4096];
	int			idx;
	char		*dst;

	idx = check_newline(buf);
	if (idx != -1)
	{
		dst = (char *)malloc(sizeof(char) * (idx + 1));
		ft_strdup(dst, buf, idx);
		reset_buf_offset(buf, idx);
		return (dst);
	}
	else
	{
		while (idx == -1)
		{
			read_buffer_size(fd, buf);
			idx = check_newline(buf);	
		}
		printf("%d\n", idx);
		dst = (char *)malloc(sizeof(char) * (idx + 1));
		ft_strdup(dst, buf, idx);
		reset_buf_offset(buf, idx);
		printf("dst: %s\n", dst);
		return (dst);
	}
}

int	main(void)
{
	int		fd1;
	//int		fd2;
	char	*dst;
	char	*dst2;

	fd1 = open("./text.txt", O_RDONLY);
	//fd2 = open("./text2.txt", O_RDONLY);
	dst = get_next_line_bonus(fd1);
	printf("%s", dst);
	dst2 = get_next_line_bonus(fd1);
	printf("%s", dst2);
}
