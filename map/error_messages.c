/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 20:39:53 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/14 20:40:20 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../getnextline/get_next_line.h"
#include "../cubelib.h"
#include "../libft/libft.h"

void	texture_error(void)
{
	ft_putstr_fd("Error\nTexture is invalid.", 2);
	exit(0);
}

void	resolution_error(void)
{
	ft_putstr_fd("Error\nResolution is invalid.", 2);
	exit(0);
}

void	rgb_error(void)
{
	ft_putstr_fd("Error\nRGB Invalid.", 2);
	exit(0);
}

void	map_error(void)
{
	ft_putstr_fd("Error\nMap is Invalid", 2);
	exit(0);
}
