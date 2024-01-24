/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juggorr <juggorr@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:52:33 by juggorr           #+#    #+#             */
/*   Updated: 2024/01/24 12:23:34 by juggorr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void	fill_buf(char *buf, int idx)
{
	buf[idx] = 'a';
}

int	main()
{
	static char	buf[10];

	fill_buf(buf, 0);
	write(1, buf, 10);
	printf("\n");
	fill_buf(buf, 1);
	write(1, buf, 10);
	printf("\n");
	fill_buf(buf, 2);
	write(1, buf, 10);
	printf("\n");
}
