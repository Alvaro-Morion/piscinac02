/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_with_non_printable.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:13:01 by amorion-          #+#    #+#             */
/*   Updated: 2021/07/01 17:54:59 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_hex(char c)
{
	int	h1;
	int	h2;

	h1 = c / 16 + 48;
	write(1, &h1, 1);
	if (c % 16 < 10)
		h2 = c % 16 + 48;
	else
		h2 = (c % 16) - 10 + 97;
	write(1, &h2, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 31 && str[i] < 127)
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			if (str[i] == 127)
			{
				write(1, "7f", 2);
			}
			else
				print_hex(str[i]);
		}
		i++;
	}
}
