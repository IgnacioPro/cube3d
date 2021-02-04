/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:48:54 by ihorcada          #+#    #+#             */
/*   Updated: 2020/01/20 14:02:08 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t z;

	i = 0;
	z = 0;
	if (dst != NULL && src != NULL)
	{
		while (src[i] != '\0')
		{
			i++;
		}
		if (dstsize == 0)
			return (i);
		while ((z < dstsize - 1) && (src[z] != '\0'))
		{
			dst[z] = src[z];
			z++;
		}
		dst[z] = '\0';
		return (i);
	}
	return (0);
}
