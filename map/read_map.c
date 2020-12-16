/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:14:47 by ihorcada          #+#    #+#             */
/*   Updated: 2020/12/16 11:34:15 by IgnacioHB        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../getnextline/get_next_line.h"
#include "../cubelib.h"
#include "../libft/libft.h"

typedef struct s_data
{
	char *linea;
	char *arg1;
	char *arg2;
}	t_data;

void map_name_validator(t_data data)
{
	unsigned int len;
	char *lastFour;
	int j;
	lastFour = ft_substr(data.arg1, (ft_strlen(data.arg1) - 4), 5);
	j = ft_strncmp(lastFour, ".cub", 4);
	if (j != 0)
		printf("Error. Map name is invalid.\n");
}

void save_image_validator(t_data data)
{
	int j;
	if (data.arg2)
	{
	j = ft_strncmp(data.arg2, "--save", 5);
	if (j != 0)
		printf("Second argument is invalid. Try '--save'.\n");
	}
}

int main (int argc, char *argv[])
{
	t_data data;
	int fd;
	char *line = 0;
	int i = 0;
	int j;
	data.arg1 = argv[1];
	data.arg2 = argv[2];
	
	fd = open(argv[1], O_RDONLY);
	if (!data.arg1)
		printf("Error. No map provided.\n");

	if (argc > 3 || argc < 2)
	{
		printf("Number of arguments is invalid.\n");
		exit(0);
	}
	
	map_name_validator(data);
	save_image_validator(data);

	if (fd == -1)
	{
		printf("Error opening map.\n");
		exit(0);
	}
	
	while ((i = get_next_line(fd, &line)) > 0)
	{
		// printf("%s\n", line);
		data.linea = line;
		printf("%s\n", line);
		i++;
	}

	// ft_split(data.linea, 'a');
	return(0);
}