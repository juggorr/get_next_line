/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:50:46 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/24 15:40:50 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line_bonus.h"

void	read_buffer_size(int fd, char *buf, int idx)
{
	char	tmp_buf[BUFFER_SIZE + 1];
	ssize_t	res;
	int		len;

	res = read(fd, tmp_buf, BUFFER_SIZE);
	tmp_buf[res] = '\0';
	printf("%s\n", tmp_buf);
	len = check_newline(tmp_buf);
	if (len == res)
	{
		idx = ft_stricat(buf, tmp_buf, idx);
		read_buffer_size(fd, buf, idx);
	}
	else
	{
		idx = ft_stricat(buf, tmp_buf, idx);
		printf("%d\n", idx);
		get_next_line_bonus(fd);
	}

}

char	*get_next_line_bonus(int fd)
{
	static char	buf[4096];
	int			idx;
	char		*dst;

	idx = check_newline(buf);
	if (buf[idx] == '\n')
	{
		dst = (char *)malloc(sizeof(char) * (idx + 1));
		ft_strdup(dst, buf, idx);
		reset_buf_offset(buf, idx);
		printf("gnl_dst: %s", dst);
		return (dst);
	}
	else
	{
		read_buffer_size(fd, buf, idx);
		return (buf);
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
	printf("dst: %s", dst);
	dst2 = get_next_line_bonus(fd1);
	printf("dst2: %s", dst2);
}
