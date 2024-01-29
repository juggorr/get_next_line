/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:52:08 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/29 16:38:09 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	check_newline_strlen(char *s, int flag)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == '\n')
			flag = 1;
		++idx;
	}
	if (flag)
		return (idx);
	return (-1);
}

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

t_node	*find_fd(t_node *head, int fd)
{
	t_node	*tmp;

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

t_node	*add_new_fd(t_node *head, int fd)
{
	t_node	*new;
	t_node	*tmp;

	new = (t_node *)malloc(sizeof(t_node));
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
