/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:51:50 by ihorcada          #+#    #+#             */
/*   Updated: 2020/01/31 12:52:46 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**w;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s || (!(w = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1)))))
		return (NULL);
	i = 0;
	k = 0;
	while (i < ft_wordcount(s, c))
	{
		if (!((w[i] = malloc(sizeof(char) * (ft_wordlen(&s[k], c) + 1)))))
			return (NULL);
		j = 0;
		while (s[k] == c)
			k++;
		while ((s[k] != c) && (s[k]))
			w[i][j++] = s[k++];
		w[i][j] = '\0';
		i++;
	}
	w[i] = NULL;
	return (w);
}
