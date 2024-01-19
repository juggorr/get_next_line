/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:41:36 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/19 15:47:43 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include<stdlib.h>
# include<unistd.h>
# define BUFFER_SIZE 10

typedef struct s_node
{
	int				fd;
	struct s_node	*next;
}	t_node;

#endif
