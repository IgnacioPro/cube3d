/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihorcada <ihorcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:41:49 by ihorcada          #+#    #+#             */
/*   Updated: 2020/01/31 12:42:41 by ihorcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(const char *s, char c)
{
	size_t i;
	size_t wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		if (s[i] != c)
			wc++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (wc);
}
