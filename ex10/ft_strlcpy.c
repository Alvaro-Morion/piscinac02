/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:35:54 by amorion-          #+#    #+#             */
/*   Updated: 2021/07/01 17:51:37 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	n;

	n = 0;
	while (src[n] != '\0')
	{
		if (size > 0)
		{
			i = 0;
			while (i < size - 1 && i < n)
			{
				dest[i] = src[i];
				i++;
			}
			dest[i] = '\0';
		}
		n++;
	}
	return (n);
}
