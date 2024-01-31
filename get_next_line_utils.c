/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:52:08 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/31 09:08:34 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	check_newline_idx(char *s)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == '\n')
			return (idx);
		++idx;
	}
	return (-1);
}

char	*last_line(t_lnode *node)
{
	int		idx;
	char	*dst;

	idx = 0;
	if (node->len <= 0)
		return (0);
	dst = (char *)malloc(sizeof(char) * (node->len + 1));
	if (!dst)
		return (0);
	while (idx < node->len)
	{
		dst[idx] = node->buf[idx];
		++idx;
	}
	dst[idx] = '\0';
	return (dst);
}

t_lnode	*remove_fd(t_lnode *head, t_lnode *node)
{
	t_lnode	*tmp;

	tmp = head;
	if (node == head)
	{
		tmp = head->next;
		if (!head->buf)
			free(head->buf);
		free(head);
		return (tmp);
	}
	while (tmp->next != node)
		tmp = tmp->next;
	tmp->next = node->next;
	if (!node->buf)
		free(node->buf);
	free(node);
	return (head);
}

t_lnode	*find_fd(t_lnode *head, int fd)
{
	t_lnode	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = add_new_fd(head, fd);
	if (!tmp)
		return (0);
	return (tmp);
}

t_lnode	*add_new_fd(t_lnode *head, int fd)
{
	t_lnode	*new;
	t_lnode	*tmp;

	new = (t_lnode *)malloc(sizeof(t_lnode));
	if (!new)
		return (0);
	new->fd = fd;
	new->buf = NULL;
	new->len = 0;
	new->res = BUFFER_SIZE;
	new->next = NULL;
	new->nl_flag = -1;
	if (!head)
	{
		head = new;
		return (head);
	}
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (tmp->next);
}
