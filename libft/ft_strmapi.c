/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:19:55 by ihorcada          #+#    #+#             */
/*   Updated: 2020/01/31 10:54:59 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str;
	unsigned int		i;
	int					a;

	if (!s || !f)
		return (NULL);
	if (s && f)
	{
		i = 0;
		a = ft_strlen((char *)s);
		str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!str)
			return (NULL);
		while (s[i])
		{
			str[i] = f(i, s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
