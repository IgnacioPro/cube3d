/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:26:55 by ihorcada          #+#    #+#             */
/*   Updated: 2020/01/17 18:17:52 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;
	size_t	j;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	if (size < dst_size)
		return (src_size + size);
	j = 0;
	i = dst_size;
	while (i < size - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	dst[i] = '\0';
	return (src_size + dst_size);
}
