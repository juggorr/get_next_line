/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:17:50 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/24 15:41:04 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line_bonus.h"

int	ft_stricat(char *dst, char *src, int end_idx)
{
	int	idx;

	idx = 0;
	while (idx < BUFFER_SIZE + 1 && src[idx])
	{
		dst[end_idx] = src[idx];
		++idx;
		++end_idx;
	}
	dst[end_idx] = '\0';
	return (end_idx);
}

char	*ft_strdup(char *dst, char *src, int len)
{
	int	idx;

	idx = 0;
	while (idx <= len)
	{
		dst[idx] = src[idx];
		++idx;
	}
	dst[idx] = '\0';
	return (dst);
}

int	check_newline(char *s)
{
	int	idx;

	idx = 0;
	while(idx < 4096 && s[idx])
	{
		if (s[idx] == '\n')
			return (idx);
		++idx;
	}
	return (idx);
}

void	reset_buf_offset(char *buf, int idx)
{
	int	reset_idx;

	reset_idx = 0;
	while (buf[idx])
	{
		buf[reset_idx] = buf[idx];
		++reset_idx;
		++idx;
	}
}
