/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:41:36 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/24 15:26:36 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include<stdlib.h>
# include<unistd.h>
# define BUFFER_SIZE 10
// delete these !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# include<stdio.h>
# include<fcntl.h>

typedef struct s_node
{
	int				fd;
	struct s_node	*next;
}	t_node;

void	read_buffer_size(int fd, char *buf, int idx);
char	*get_next_line_bonus(int fd);
int		ft_stricat(char	*dst, char *src, int end_idx);
char	*ft_strdup(char *dst, char *src, int len);
int		check_newline(char *s);
void	reset_buf_offset(char *buf, int idx);

#endif
