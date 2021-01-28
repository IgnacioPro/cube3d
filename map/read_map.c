/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:14:47 by ihorcada          #+#    #+#             */
/*   Updated: 2021/01/28 20:15:32 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../getnextline/get_next_line.h"
#include "../cubelib.h"
#include "../libft/libft.h"

void	alloc_map(t_data *data, t_vars *vars)
{
	data->map[data->c] = (char*)malloc((data->mapx + 1) * sizeof(char));
	vars->worldmap[data->c] = (char*)malloc((data->mapx + 1) * sizeof(char));
	data->map[data->c] = ft_memset(data->map[data->c], ' ', data->mapx);
	vars->worldmap[data->c] = ft_memset(vars->worldmap[data->c],
		'1', data->mapx);
	data->map[data->c][data->mapx] = '\0';
	vars->worldmap[data->c][data->mapx] = '\0';
}
