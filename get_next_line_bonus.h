/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:25:53 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/26 15:28:26 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
//delete these
# include <stdio.h>
# include <fcntl.h>

typedef struct s_node
{
	int				fd;
	char			*buf;
	int				len;
	ssize_t			res;
	int				nl_flag;
	struct s_node	*next;
}	t_node;

char	*get_next_line_bonus(int fd);
int		read_to_buf(t_node *node);
char	*reset_buf_offset(t_node *node, int len);
char	*ft_split(t_node *node);
int		ft_strjoin(t_node *node, char *tmp_buf);
int		check_newline_strlen(char *s, int flag);
int		check_newline_idx(char *s);
t_node	*add_new_fd(t_node *head, int fd);
t_node	*find_fd(t_node *head, int fd);

#endif
