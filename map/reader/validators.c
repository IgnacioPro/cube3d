/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:20:37 by IgnacioHB         #+#    #+#             */
/*   Updated: 2021/01/28 20:08:04 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubelib.h"
#include "../../libft/libft.h"
#include "../../getnextline/get_next_line.h"

void	map_name_validator(t_data data)
{
	char	*lastfour;
	int		j;

	lastfour = ft_substr(data.arg1, (ft_strlen(data.arg1) - 4), 5);
	j = ft_strncmp(lastfour, ".cub", 4);
	free(lastfour);
	if (j != 0)
	{
		printf("Error. Map name is invalid.\n");
		exit(0);
	}
}

void	save_image_validator(t_data data)
{
	int j;

	j = ft_strncmp(data.arg2, "--save", 6);
	if (j != 0)
	{
		ft_putstr_fd("Error\nSecond argument is invalid. Try '--save'.\n", 2);
		exit(0);
	}
}

void	element_validator(t_data *data)
{
	if (data->res != 1 ||
		data->n_tex != 1 ||
		data->s_tex != 1 ||
		data->w_tex != 1 ||
		data->e_tex != 1 ||
		data->sp_tex != 1 ||
		data->f_color != 1 ||
		data->c_color != 1)
	{
		ft_putstr_fd("Error\nPremaping error. Check number of elements", 2);
		exit(0);
	}
}

void	element_innit(t_data *data)
{
	data->res = 0;
	data->n_tex = 0;
	data->s_tex = 0;
	data->w_tex = 0;
	data->e_tex = 0;
	data->sp_tex = 0;
	data->f_color = 0;
	data->c_color = 0;
}
