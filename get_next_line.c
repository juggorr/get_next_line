/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:25:07 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/31 17:28:14 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strjoin(t_lnode *head, t_lnode *node, char *tmp_buf)
{
	char	*new;
	int		idx;

	new = (char *)malloc(sizeof(char) * (node->len + node->res + 1));
	if (!new)
	{
		head = remove_fd(head, node);
		return (0);
	}
	idx = -1;
	while (++idx < node->len)
	{
		new[idx] = node->buf[idx];
	}
	idx = -1;
	while (++idx < node->res)
		new[node->len + idx] = tmp_buf[idx];
	new[node->len + idx] = '\0';
	free(node->buf);
	node->buf = new;
	node->len += node->res;
	return (node->len);
}

char	*ft_split(t_lnode *head, t_lnode *node)
{
	int		idx;
	char	*dst;
	int		nl_idx;

	nl_idx = check_newline_idx(node->buf);
	if (nl_idx < 0 && node->res < BUFFER_SIZE)
	{
		dst = last_line(head, node);
		if (!dst)
			return (0);
		return (dst);
	}
	dst = (char *)malloc(sizeof(char) * (nl_idx + 2));
	if (!dst)
	{
		head = remove_fd(head, node);
		return (0);
	}
	idx = -1;
	while (++idx <= nl_idx)
		dst[idx] = node->buf[idx];
	dst[idx] = '\0';
	if (!reset_buf_offset(head, node, nl_idx))
		return (0);
	return (dst);
}

char	*reset_buf_offset(t_lnode *head, t_lnode *node, int nl_idx)
{
	char	*dst;
	int		idx;

	dst = (char *)malloc(sizeof(char) * (node->len - nl_idx));
	if (!dst)
	{
		head = remove_fd(head, node);
		return (0);
	}
	idx = -1;
	while (++idx < node->len - nl_idx - 1)
		dst[idx] = node->buf[idx + nl_idx + 1];
	dst[idx] = '\0';
	free(node->buf);
	node->buf = dst;
	node->len -= nl_idx + 1;
	node->nl_flag = check_newline_idx(node->buf);
	return (node->buf);
}

int	read_to_buf(t_lnode *head, t_lnode *node)
{
	char	tmp_buf[BUFFER_SIZE + 1];

	node->res = read(node->fd, tmp_buf, BUFFER_SIZE);
	if (node->res <= 0)
		return (0);
	tmp_buf[node->res] = '\0';
	node->nl_flag = check_newline_idx(tmp_buf);
	ft_strjoin(head, node, tmp_buf);
	return (node->len);
}

char	*get_next_line(int fd)
{
	static t_lnode	*head;
	t_lnode			*tmp;
	char			*dst;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (0);
	if (!head)
		head = add_new_fd(head, fd);
	tmp = find_fd(head, fd);
	if (!tmp)
		return (0);
	while (tmp->nl_flag == -1 && tmp->res == BUFFER_SIZE)
		read_to_buf(head, tmp);
	if (tmp->res < 0 || !(tmp->buf))
	{
		head = remove_fd(head, tmp);
		return (0);
	}
	dst = ft_split(head, tmp);
	return (dst);
}
/*
int	main(void)
{
	int	fd = open("foo.txt", O_RDONLY);
	int	fd2 = open("bar.txt", O_RDONLY);
	int	fd3 = open("a.txt", O_RDONLY);
	char	*dst;

	//atexit(check_leak());
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
	dst = get_next_line(fd3);
	printf("dst:%s", dst);
}*/
