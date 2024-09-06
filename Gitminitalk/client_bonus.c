/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvargom <alvargom@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:13:39 by alvargom          #+#    #+#             */
/*   Updated: 2024/07/23 14:51:27 by alvargom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_signal(unsigned char c, int pid)
{
	int				i;
	unsigned char	temp;

	temp = c;
	i = 8;
	while (i > 0)
	{
		i--;
		temp = c >> i;
		if (temp % 2 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
	}
}

void	ft_message(int signal)
{
	if (signal == SIGUSR1)
		write(1, "SUCCESS!\n", 10);
}

void	client_pid(int s_pid)
{
	char	*c_pid;
	int		c;

	c_pid = itoa_pid(getpid());
	printf(" ESte es el pid del cliente %s", c_pid);
	c = 0;
	while (c_pid[c] != '\0')
	{
		ft_send_signal(c_pid[c], s_pid);
		c++;
	}
	ft_send_signal(27, s_pid);
	ft_send_signal(37, s_pid);
	free(c_pid);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	c;

	c = 0;
	if (argc < 3)
	{
		write(2, "ERROR: Need more arguments to work", 34);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(2, "ERROR: Invalid PID", 18);
		return (1);
	}
	client_pid(pid);
	printf("PAso el envio del pid del cliente");
	while (argv[2] && argv[2][c])
	{
		ft_send_signal(argv[2][c], pid);
		c++;
	}
	ft_send_signal('\n', pid);
	signal(SIGUSR1, ft_message);
	while (1)
		usleep(100);
	return (0);
}
