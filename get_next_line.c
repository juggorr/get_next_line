/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:25:07 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/29 17:00:30 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	ft_strjoin(t_lnode *node, char *tmp_buf)
{
	char	*new;
	int		idx;

	new = (char *)malloc(sizeof(char) * (node->len + 1));
	if (!new)
		return (0);
	idx = 0;
	while (idx < node->len - node->res)
	{
		new[idx] = node->buf[idx];
		++idx;
	}
	while (idx < node->len)
	{
		new[idx] = tmp_buf[idx - (node->len - node->res)];
		++idx;
	}
	new[idx] = '\0';
	free(node->buf);
	node->buf = new;
	return (node->len);
}

char	*ft_split(t_lnode *node)
{
	int		idx;
	char	*dst;
	int		nl_idx;

	nl_idx = check_newline_idx(node->buf);
	if (nl_idx < 0)
		return (node->buf);
	dst = (char *)malloc(sizeof(char) * (nl_idx + 1));
	if (!dst)
		return (0);
	idx = 0;
	while (idx <= nl_idx)
	{
		dst[idx] = node->buf[idx];
		++idx;
	}
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
	while (idx < node->len - nl_idx)
	{
		dst[idx] = node->buf[idx + nl_idx + 1];
		++idx;
	}
	dst[idx] = '\0';
	free(node->buf);
	node->buf = dst;
	node->len -= nl_idx + 1;
	node->nl_flag = -1;
	return (dst);
}

int	read_to_buf(t_lnode *node)
{
	char	tmp_buf[BUFFER_SIZE + 1];

	node->res = read(node->fd, tmp_buf, BUFFER_SIZE);
	tmp_buf[node->res] = '\0';
	node->len += node->res;
	node->nl_flag = check_newline_strlen(tmp_buf, 0);
	ft_strjoin(node, tmp_buf);
	return (node->len);
}

char	*get_next_line(int fd)
{
	static t_lnode	*head;
	t_lnode			*tmp;

	if (fd < 0)
		return (0);
	if (!head)
		head = add_new_fd(head, fd);
	if (!head)
		return (0);
	tmp = find_fd(head, fd);
	if (!tmp)
		return (0);
	while (tmp->nl_flag == -1 && tmp->res == BUFFER_SIZE)
		read_to_buf(tmp);
	return (ft_split(tmp));
}
/*
int	main(void)
{
	int	fd = open("./text.txt", O_RDONLY);
	int fd2 = open("./text2.txt", O_RDONLY);
	char	*dst;

	dst = get_next_line(fd);
	printf("%s", dst);
	dst = get_next_line(fd2);
	printf("%s", dst);
	dst = get_next_line(fd);
	printf("%s", dst);
	dst = get_next_line(fd2);
	printf("%s", dst);
	dst = get_next_line(fd);
	printf("%s", dst);
	dst = get_next_line(fd2);
	printf("%s", dst);
	dst = get_next_line(fd);
	printf("%s", dst);
	dst = get_next_line(fd2);
	printf("%s", dst);
}*/
