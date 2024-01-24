/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:17:50 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/24 17:01:51 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line_bonus.h"

void	ft_stricat(char *dst, char *src)
{
	int	idx;

	idx = 0;
	while (dst[idx])
		++idx;
	while (*src)
	{
		dst[idx] = *src;
		++idx;
		++src;
	}
	dst[idx] = '\0';
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
	return (-1);
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
