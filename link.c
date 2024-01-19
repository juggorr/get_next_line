/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:44:52 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/19 15:23:14 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "link.h"

t_node	*init_list()
{
	t_node	*head;
	
	head = (t_node *)malloc(sizeof(t_node));
	head->fd = 10;
	head->next = NULL;
	return (head);
}

t_node	*add_node(t_node *head, int	val)
{
	t_node	*new;
	t_node	*tmp;

	new = (t_node*)malloc(sizeof(t_node));
	new->fd = val;
	new->next = NULL;
	// head가 없다면
	if (!head)
		// 새로선언한 노드를 헤드로 선언
		head = new;
	// head가 있다면
	else
	{
		// head를 옮기면 안되기때문에 tmp 선언
		tmp = head;
		// tmp->next == NULL 까지
		// 즉, 마지막노드에 도달할 때 까지
		while (tmp->next)
			tmp = tmp->next;
		// 도달하면 마지막노드로 new 추가
		tmp->next = new;
	}
	return (head);
}

void	pop_node(t_node *head)
{
	t_node	*new_end;
	t_node	*tmp;

	tmp = head;
	while (tmp->next)
	{
		new_end = tmp;
		tmp = tmp->next;
	}
	new_end->next = NULL;
	free(tmp);
}

t_node	*remove_node(t_node *head, t_node *node)
{
	t_node	*tmp;

	tmp = head;
	if (node == head)
	{
		tmp = head->next;
		free(head);
		return (tmp);
	}
	while (tmp->next != node)
		tmp = tmp->next;
	tmp->next = node->next;
	free(node);
	return (head);
}

t_node	*insert_list(t_node *head, int idx, int val)
{
	int		lst_idx;
	t_node	*pre_node;
	t_node	*tmp;
	t_node	*new;

	lst_idx = 0;
	tmp = head;
	new = (t_node *)malloc(sizeof(t_node));
	new->fd = val;
	if (idx == 0)
	{
		new->next = head;
		head = new;
		return (head);
	}
	while (tmp->next)
	{
		if (lst_idx == idx)
			break ;
		pre_node = tmp;
		tmp = tmp->next;
		lst_idx++;
	}
	if (idx == lst_idx + 1)
	{
		tmp->next = new;
		new->next = NULL;
		return (head);
	}
	if (idx > lst_idx)
		return (head);
	pre_node->next = new;
	new->next = tmp;
	return (head);
}

int	main(void)
{
	t_node	*head;

	head = init_list();
	head = add_node(head, 20);
	head = add_node(head, 30);
	head = remove_node(head, head);
	printf("%d\n", head->fd);
}
