/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:24:52 by ihorcada          #+#    #+#             */
/*   Updated: 2020/02/18 19:31:59 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *src)
{
	char	*string;
	int		src_size;
	int		i;

	i = 0;
	src_size = 0;
	while (src[src_size])
	{
		src_size++;
	}
	string = (char *)malloc(src_size * sizeof(*src) + 1);
	if (!string)
		return (NULL);
	while (i < src_size)
	{
		string[i] = src[i];
		i++;
	}
	string[src_size] = '\0';
	return (string);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*newline_check(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*str;

	if (!s || !(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[start] && i < len)
		{
			if (s[i] == '\n')
			{
				str[i] = '\0';
				return (str);
			}
			str[i] = s[start];
			i++;
			start++;
		}
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*j;
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = (char *)malloc(sizeof(*j) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!j)
		return (NULL);
	while (*s1)
		j[i++] = *s1++;
	while (*s2)
		j[i++] = *s2++;
	j[i] = '\0';
	return (j);
}
