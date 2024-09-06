/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvargom <alvargom@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:57:11 by alvargom          #+#    #+#             */
/*   Updated: 2024/08/19 11:15:00 by alvargom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_atoi(const char *str);
int		ft_strlen(char *str);
void	ft_putnbr(int nbr);
char	*itoa_pid(int nb);

#endif
