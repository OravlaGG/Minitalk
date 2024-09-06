/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvargom <alvargom@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:13:32 by alvargom          #+#    #+#             */
/*   Updated: 2024/07/23 14:40:32 by alvargom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_cpc = 0;

void	s_s_to_client(int n, int bol)
{
	static int	pid;
	
	printf(" CPID %d   ", pid);
	if (n >= 0)
	{
		pid *= 10;
		pid += (n - '0');
	}
	if (bol == 1)
	{
		kill(pid, SIGUSR1);
		g_cpc = 1;
		pid = 0;
	}
}

void	sig_pro(int n)
{
	int	bol;

	bol = 0;

	if (g_cpc != 0)
	{
		write(1, &n, 1);
		if (n == '\n')
			g_cpc = 0;
	}
	else if (n == 27)
	{
		bol = 1;
		s_s_to_client(-1, bol);
	}
	else if (g_cpc == 0)
		s_s_to_client(n, bol);
}

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
		sig_pro(n);
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
