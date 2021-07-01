/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_with_non_printable.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:13:01 by amorion-          #+#    #+#             */
/*   Updated: 2021/07/01 13:29:59 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	print_char(char c)
{
	char	hex[2];

	if (c / 16 <= 9)
		hex[0] = '0' + c / 16;
	else
		hex[0] = 'a' + c / 16 - 10;
	if (c % 16 <= 9)
		hex[1] = '0' + c % 16;
	else
		hex[1] = 'a' + c % 16 - 10;
	write(1, hex, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] > 31 && str[i] < 127)
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			if (str[i] == 127)
			{
				write(1, "7F", 2);
			}
			else
				print_char(str[i]);
		}
		i++;
	}
}
