/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:55:29 by amorion-          #+#    #+#             */
/*   Updated: 2021/07/01 17:48:34 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_hexa(char	c)
{
	char	h1;
	char	h2;

	h1 = c / 16 + '0';
	h2 = c % 16;
	write(1, &h1, 1);
	if (h2 < 10)
	{
		h2 = h2 + '0';
		write(1, &h2, 1);
	}
	else
	{
		h2 = h2 + 'a' - 10;
		write(1, &h2, 1);
	}
}

void	ft_put_addr(void *addr)
{
	char	addr_c[15];
	long	addrl;
	int		i;

	addrl = (long)addr;
	i = 0;
	while (addrl > 0)
	{
		addr_c[i] = addrl % 16;
		if (addr_c[i] < 10)
			addr_c[i] += '0';
		else
			addr_c[i] = addr_c[i] + 'a' - 10;
		addrl = addrl / 16;
		i++;
	}
	while (i < 15)
	{
		addr_c[i] = '0';
		i++;
	}
	while (--i > 0)
		write(1, &addr_c[i], 1);
}

void	ft_print_line(char *addr, int size)
{
	int		i;
	int		sprint;
	char	*addr_c;

	addr_c = (char *)addr;
	i = 0;
	while (i < size)
	{
		ft_print_hexa(addr_c[i++]);
		if (i % 2 == 0)
			write(1, " ", 1);
	}
	sprint = 2 * (16 - size) + (19 - size) / 2;
	while (--sprint > 0)
		write(1, " ", 1);
	i = -1;
	while (i++ < size)
	{
		if (addr_c[i] >= 32 && addr_c[i] <= 126)
			write(1, &addr_c[i], 1);
		else
			write(1, ".", 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	ctp;
	unsigned int	os;

	os = 0;
	while (size > 0)
	{
		if (size >= 16)
		{
			ctp = 16;
			size -= 16;
		}
		else
		{
			ctp = size;
			size = 0;
		}
		ft_put_addr(addr + os);
		write(1, ": ", 2);
		ft_print_line(addr + os, ctp);
		write (1, "\n", 1);
		os += 16;
	}
	return (addr);
}
