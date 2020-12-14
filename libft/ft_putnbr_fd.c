/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:33:58 by ihorcada          #+#    #+#             */
/*   Updated: 2020/01/29 12:37:00 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	long_n;

	if (n < 0)
	{
		write(fd, "-", 1);
		long_n = (unsigned int)(n * -1);
	}
	else
		long_n = (unsigned int)n;
	if (long_n >= 10)
		ft_putnbr_fd(long_n / 10, fd);
	ft_putchar_fd((char)(long_n % 10 + 48), fd);
}
