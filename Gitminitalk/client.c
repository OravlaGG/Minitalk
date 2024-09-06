/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvargom <alvargom@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:13:39 by alvargom          #+#    #+#             */
/*   Updated: 2024/07/23 14:31:17 by alvargom         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	pid;

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
	while (argv[2] && *argv[2])
		ft_send_signal(*argv[2]++, pid);
	ft_send_signal('\n', pid);
	return (0);
}
