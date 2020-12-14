/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:43:26 by ihorcada          #+#    #+#             */
/*   Updated: 2020/01/20 10:48:08 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (c == 0)
		return ((char *)s + i);
	while (i > 0)
	{
		i--;
		if (s[i] == c)
			return ((char *)s + i);
	}
	return (NULL);
}
