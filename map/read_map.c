/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:14:47 by ihorcada          #+#    #+#             */
/*   Updated: 2020/12/17 20:02:50 by IgnacioHB        ###   ########.fr       */
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
	int x;
	int y;
	int i;
} t_data;

void map_name_validator(t_data data)
{
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

	// j = NULL;
	// if (data.arg2 && ft_strlen(data.arg2) == 6)
	j = ft_strncmp(data.arg2, "--save", 6);
	if (j != 0)
	{
		printf("Second argument is invalid. Try '--save'.\n");
		exit(0);
	}
}

void get_resolution(t_data *data)
{
	data->i++;
	while (data->linea[data->i] == ' ')
		data->i++;
	data->x = ft_atoi(&data->linea[data->i]);
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
	while (data->linea[data->i] == ' ')
		data->i++;
	data->y = ft_atoi(&data->linea[data->i]);
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
}

int main(int argc, char *argv[])
{
	t_data data;
	int fd;
	char *line = 0;
	int i = 0;
	data.arg1 = argv[1];
	data.arg2 = argv[2];

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		perror("Error opening map\n");
	if (!data.arg1)
		perror("Error. No map provided\n");

	if (argc > 3 || argc < 2)
	{
		perror("Number of arguments is invalid\n");
		exit(0);
	}

	map_name_validator(data);
	if (argc == 3)
		save_image_validator(data);

	
	while ((i = get_next_line(fd, &line)) > 0)
	{
		data.linea = line;
		data.i = 0;
		while(data.linea[data.i] ==  ' ')
			data.i++;
		if (data.linea[data.i] == 'R')
			get_resolution(&data);
		// if (data.linea[0] == 'N' && data.linea[1] == 'O')
			// printf("%s\n", data.linea);
		// if (data.linea[0] == 'S' && data.linea[1] == ' ')
		// 	printf("%s\n", data.linea);
		// if (data.linea[0] == 'S' && data.linea[1] == 'O')
		// 	printf("%s\n", data.linea);
		// if (data.linea[0] == 'E' && data.linea[1] == 'A')
		// 	printf("%s\n", data.linea);
		// if (data.linea[0] == 'W' && data.linea[1] == 'E')
		// 	printf("%s\n", data.linea);
		// if (data.linea[0] == 'F')
		// 	printf("%s\n", data.linea);
		// if (data.linea[0] == 'C')
		// printf("%s\n", data.linea);
	}
	printf("la x es: %d\n", data.x);
	printf("la y es: %d\n", data.y);
	
	return (0);
}