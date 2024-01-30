/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:25:53 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/30 13:43:18 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
//delete these
# include <stdio.h>
# include <fcntl.h>

typedef struct s_lnode
{
	int				fd;
	char			*buf;
	int				len;
	ssize_t			res;
	int				nl_flag;
	struct s_lnode	*next;
}	t_lnode;

char	*get_next_line(int fd);
int		read_to_buf(t_lnode *node);
char	*reset_buf_offset(t_lnode *node, int len);
char	*ft_split(t_lnode *node);
int		ft_strjoin(t_lnode *node, char *tmp_buf);
int		check_newline_idx(char *s);
char	*last_line(t_lnode *node);
t_lnode	*remove_fd(t_lnode *head, t_lnode *node);
t_lnode	*add_new_fd(t_lnode *head, int fd);
t_lnode	*find_fd(t_lnode *head, int fd);

#endif
