/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:25:07 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/26 13:16:41 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	ft_strjoin(t_node *node, char *tmp_buf)
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

char	*ft_split(t_node *node)
{
	int		idx;
	char	*dst;
	int		dst_len;

	dst_len = check_newline_strlen(node->buf, 0);
	if (dst_len < 0)
		return (node->buf);
	dst = (char *)malloc(sizeof(char) * (dst_len + 1));
	if (!dst)
		return (0);
	idx = 0;
	while (idx < dst_len)
	{
		dst[idx] = node->buf[idx];
		++idx;
	}
	dst[idx] = '\0';
	if (!reset_buf_offset(node, dst_len))
		return (0);
	return (dst);
}

char	*reset_buf_offset(t_node *node, int len)
{
	char	*dst;
	int		idx;

	dst = (char *)malloc(sizeof(char) * (node->len - len + 1));
	if (!dst)
		return (0);
	while (idx < node->len - len)
	{
		dst[idx] = node->buf[idx + node->len - len + 1];
		++idx;
	}
	dst[idx] = '\0';
	free(node->buf);
	node->buf = dst;
	return (dst);
}

int	read_to_buf(t_node *node)
{
	char	tmp_buf[BUFFER_SIZE + 1];

	node->res = read(node->fd, tmp_buf, BUFFER_SIZE);
	node->len += node->res;
	node->nl_flag = check_newline_strlen(tmp_buf, 0);
	ft_strjoin(node, tmp_buf);
	return (node->len);
}

char	*get_next_line(int fd)
{
	static t_node	*head;
	t_node			*tmp;

	if (fd < 0)
		return (0);
	if (!head)
		head = add_new_fd(head, fd);
	if (!head)
		return (0);
	tmp = find_fd(head, fd);
	if (!tmp)
		return (0);
	while (tmp->nl_flag == -1 || tmp->res == BUFFER_SIZE)
		read_to_buf(tmp);
	return (ft_split(tmp));
}

int	main(void)
{
	int	fd = open("./text.txt", O_RDONLY);
	char	*dst;

	dst = get_next_line(fd);
	printf("%s", dst);
	dst = get_next_line(fd);
	printf("%s", dst);
	dst = get_next_line(fd);
	printf("%s", dst);
	dst = get_next_line(fd);
	printf("%s", dst);
	dst = get_next_line(fd);
	printf("%s", dst);
}
