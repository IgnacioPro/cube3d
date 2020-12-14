/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:14:47 by ihorcada          #+#    #+#             */
/*   Updated: 2020/12/14 20:29:53 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../getnextline/get_next_line_bonus.h"
#include "../cubelib.h"

typedef struct s_data
{
	char *linea;
	char *arg1;
}	t_data;

void map_name_validator(t_data data)
{
	unsigned int len;
	char lastFour;
	int i;

	// len = ft_strlen(data.arg1);
	printf("El argumento 1 es: %s", data.arg1);
}


int main (int argc, char *argv[])
{
	t_data data;
	int fd;
	char *line = 0;
	int i = 0;
	data.arg1 = argv[1];
	
	fd = open(argv[1], O_RDONLY);
	if (argc > 3 || argc < 2)
	{
		printf("Number o  f arguments is invalid\n");
		exit(0);
	}
	map_name_validator(data);
	if (fd == -1)
	{
		printf("\nOpen Error\n");
		exit(0);
	}
	
	
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		data.linea = line;
		i++;
	}
	return(0);
}