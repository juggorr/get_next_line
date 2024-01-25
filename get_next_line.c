/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:50:46 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/25 13:57:08 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	read_buffer_size(int fd, char *buf)
{
	char	tmp_buf[BUFFER_SIZE];
	ssize_t	res;
	int		idx;

	if (fd < 0)
		return (-1);
	res = read(fd, tmp_buf, BUFFER_SIZE);
	if (res < 0)
	{
		idx = 0;
		while (buf[idx])
		{
			buf[idx] = 0;
			++idx;
		}
		return (res);
	}
	ft_stricat(buf, tmp_buf, res);
	return (res);
}

int	ft_strlen(char *s)
{
	int	idx;

	idx = 0;
	while (s[idx])
		++idx;
	return (idx);
}

char	*line_from_buf(char *buf, int idx, int res)
{
	char	*dst;

	if (idx < 0)
	{
		if (res == 0)
		{
			if (!buf[0])
				return (0);
			dst = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1));
			ft_strdup(dst, buf, ft_strlen(buf) - 1);
			reset_buf_offset(buf, ft_strlen(buf));
			return (dst);
		}
		return (0);
	}
	dst = (char *)malloc(sizeof(char) * (idx + 2));
	ft_strdup(dst, buf, idx);
	reset_buf_offset(buf, idx + 1);
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	buf[8192];
	int			idx;
	char		*dst;
	int			res;

	idx = check_newline(buf);
	if (idx != -1)
		dst = line_from_buf(buf, idx, idx);
	else
	{
		while (idx == -1)
		{
			res = read_buffer_size(fd, buf);
			if (res <= 0)
			{
				dst = line_from_buf(buf, idx, res);
				return (dst);
			}
			idx = check_newline(buf);
		}
		dst = line_from_buf(buf, idx, res);
	}
	if (!dst)
		return (0);
	return (dst);
}
