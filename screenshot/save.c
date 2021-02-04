/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:38:47 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/02/04 17:06:36 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubelib.h"

void			write_header(t_vars *vars, int size, int fd)
{
	unsigned char	header[54];

	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(size);
	header[3] = (unsigned char)(size >> 8);
	header[4] = (unsigned char)(size >> 16);
	header[5] = (unsigned char)(size >> 24);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	header[18] = (unsigned char)(vars->screenwidth);
	header[19] = (unsigned char)(vars->screenwidth >> 8);
	header[20] = (unsigned char)(vars->screenwidth >> 16);
	header[21] = (unsigned char)(vars->screenwidth >> 24);
	header[22] = (unsigned char)(vars->screenheight);
	header[23] = (unsigned char)(vars->screenheight >> 8);
	header[24] = (unsigned char)(vars->screenheight >> 16);
	header[25] = (unsigned char)(vars->screenheight >> 24);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(32);
	write(fd, header, 54);
}

static void		write_screenshot(int fd, t_vars *vars, int width, int height)
{
	int				x;
	unsigned int	color;

	height -= 1;
	while (height >= 0)
	{
		x = 0;
		while (x < width)
		{
			color = *(unsigned int *)(vars->imagen.addr + (height *
				vars->imagen.line_length +
				(x * (vars->imagen.bits_per_pixel / 8))));
			write(fd, &color, 4);
			x++;
		}
		height--;
	}
}

void			take_screenshot(t_vars *vars)
{
	int				fd;
	int				size;

	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0777)) < 0)
		map_error();
	ft_putstr_fd("\n\x1b[32m[BMP creado]\x1b[0m", 1);
	size = 54 + (vars->screenwidth * vars->screenheight) * 4;
	write_header(vars, size, fd);
	write_screenshot(fd, vars, vars->screenwidth, vars->screenheight);
	ft_putstr_fd("\n\x1b[32m[BMP pintado]\x1b[0m", 1);
	close(fd);
	exit(0);
}
