/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvargom <alvargom@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:06:44 by alvargom          #+#    #+#             */
/*   Updated: 2024/07/19 10:51:23 by alvargom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*itoa_pid(int nb)
{
	int		i;
	int		x;
	char	*str;

	i = 0;
	x = nb;
	while (x)
	{
		x /= 10;
		i++;
	}
	str = malloc(i + 2);
	str[i + 1] = '\0';
	str[i] = 27;
	while (--i >= 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int	s;
	int	c;
	int	n;

	c = 0;
	s = 1;
	n = 0;
	while (str[c] == 32 || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			s *= -1;
		c++;
	}
	while (str[c] <= '9' && str[c] >= '0' && str[c] != '\0' )
	{
		n = n * 10 + (str[c] - '0');
		c++;
	}
	return (n * s);
}

void	ft_putnbr(int nbr)
{
	char	temp;

	if (nbr / 10 > 0)
		ft_putnbr(nbr / 10);
	temp = nbr % 10 + '0';
	write(1, &temp, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
