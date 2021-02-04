/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:13:06 by ihorcada          #+#    #+#             */
/*   Updated: 2020/02/01 12:00:31 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src2;
	unsigned char	*dest2;

	i = 0;
	if (dest == src || !n)
		return (dest);
	if (dest != '\0' || src != '\0')
	{
		src2 = (unsigned char *)src;
		dest2 = (unsigned char *)dest;
		while (i < n)
		{
			dest2[i] = src2[i];
			i++;
		}
		return (dest);
	}
	return (0);
}
