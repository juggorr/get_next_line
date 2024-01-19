/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:34:43 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/19 13:46:43 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LINK_H
# define LINK_H
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int					fd;
	struct s_node		*next;
}	t_node;

#endif
