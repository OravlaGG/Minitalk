/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvargom <alvargom@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:13:32 by alvargom          #+#    #+#             */
/*   Updated: 2024/07/19 12:02:14 by alvargom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handle(int signal)
{
	static int	c;
	static int	n;
	int			bis;

	if (signal == SIGUSR1)
		bis = 0;
	else
		bis = 1;
	n = (n << 1) + bis;
	c++;
	if (c == 8)
	{
		write(1, &n, 1);
		n = 0;
		c = 0;
	}
}

int	main(void)
{
	write(1, "This is the pid of the server: ", 31);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, sig_handle);
	signal(SIGUSR2, sig_handle);
	while (1)
		usleep(100);
	return (0);
}
