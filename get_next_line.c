/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:25:07 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/31 10:55:09 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	check_leak(void)
{
	system("leaks a.out");
}

int	ft_strjoin(t_lnode *node, char *tmp_buf)
{
	char	*new;
	int		idx;

	new = (char *)malloc(sizeof(char) * (node->len + node->res + 1));
	if (!new)
		return (0);
	idx = 0;
	while (idx < node->len)
	{
		new[idx] = node->buf[idx];
		++idx;
	}
	idx = 0;
	while (idx < node->res)
	{
		new[node->len + idx] = tmp_buf[idx];
		++idx;
	}
	new[node->len + idx] = '\0';
	free(node->buf);
	node->buf = new;
	node->len += node->res;
	return (node->len);
}

char	*ft_split(t_lnode *node)
{
	int		idx;
	char	*dst;
	int		nl_idx;

	nl_idx = check_newline_idx(node->buf);
	if (nl_idx < 0 && node->res < BUFFER_SIZE)
	{
		dst = last_line(node);
		if (!dst)
			return (0);
		node->buf = NULL;
		return (dst);
	}
	dst = (char *)malloc(sizeof(char) * (nl_idx + 2));
	if (!dst)
		return (0);
	idx = -1;
	while (++idx <= nl_idx)
		dst[idx] = node->buf[idx];
	dst[idx] = '\0';
	if (!reset_buf_offset(node, nl_idx))
		return (0);
	return (dst);
}

char	*reset_buf_offset(t_lnode *node, int nl_idx)
{
	char	*dst;
	int		idx;

	dst = (char *)malloc(sizeof(char) * (node->len - nl_idx));
	if (!dst)
		return (0);
	idx = 0;
	while (idx < node->len - nl_idx - 1)
	{
		dst[idx] = node->buf[idx + nl_idx + 1];
		++idx;
	}
	dst[idx] = '\0';
	free(node->buf);
	node->buf = dst;
	node->len -= nl_idx + 1;
	node->nl_flag = -1;
	return (node->buf);
}

int	read_to_buf(t_lnode *node)
{
	char	tmp_buf[BUFFER_SIZE + 1];

	node->res = read(node->fd, tmp_buf, BUFFER_SIZE);
	if (node->res <= 0)
		return (0);
	tmp_buf[node->res] = '\0';
	node->nl_flag = check_newline_idx(tmp_buf);
	ft_strjoin(node, tmp_buf);
	return (node->len);
}

char	*get_next_line(int fd)
{
	static t_lnode	*head;
	t_lnode			*tmp;
	char			*dst;

	atexit(check_leak);
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (0);
	if (!head)
		head = add_new_fd(head, fd);
	tmp = find_fd(head, fd);
	if (!tmp)
		return (0);
	while (tmp->nl_flag == -1 && tmp->res == BUFFER_SIZE)
		read_to_buf(tmp);
	if (tmp->res < 0 || !(tmp->buf))
	{
		head = remove_fd(head, tmp);
		return (0);
	}
	dst = ft_split(tmp);
	if (!dst)
		return (0);
	return (dst);
}

int	main(void)
{
	int	fd = open("foo.txt", O_RDONLY);
	int	fd2 = open("bar.txt", O_RDONLY);
	int	fd3 = open("a.txt", O_RDONLY);
	char	*dst;

	dst = get_next_line(fd);
	printf("dst:%s", dst);
	dst = get_next_line(fd);
	printf("dst:%s", dst);
	dst = get_next_line(fd);
	printf("dst:%s", dst);
	printf("\n");
	dst = get_next_line(fd2);
	printf("dst:%s", dst);
	dst = get_next_line(fd2);
	printf("dst:%s", dst);
	dst = get_next_line(fd2);
	printf("dst:%s", dst);
	printf("\n");
	dst = get_next_line(fd3);
	printf("dst:%s", dst);
	dst = get_next_line(fd3);
	printf("dst:%s", dst);
	dst = get_next_line(fd3);
	printf("dst:%s", dst);
}
