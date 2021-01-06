/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: IgnacioHB <IgnacioHB@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:14:47 by ihorcada          #+#    #+#             */
/*   Updated: 2021/01/06 12:02:34 by IgnacioHB        ###   ########.fr       */
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
	
	char *north;
	char *east;
	char *west;
	char *south;
	char *sprite;
	int floor[3];
	int ceiling[3];
	int col;

	int comma;
	int rgb_error;

	int mapX;
	int mapY;
	char **map;
	int mapwidth;
	int coord_check;
	int c;
	
} t_data;
void texture_error()
{
	ft_putstr_fd("Error\nTexture is invalid.", 2);
	exit(0);
}
void resolution_error()
{
	ft_putstr_fd("Error\nResolution is invalid.", 2);
	exit(0);
}
void map_name_validator(t_data data)
{
	char *lastFour;
	int j;
	lastFour = ft_substr(data.arg1, (ft_strlen(data.arg1) - 4), 5);
	j = ft_strncmp(lastFour, ".cub", 4);
	if (j != 0)
	{
		printf("Error. Map name is invalid.\n");
		exit(0);
	}
}
void save_image_validator(t_data data)
{
	int j;

	// j = NULL;
	// if (data.arg2 && ft_strlen(data.arg2) == 6)
	j = ft_strncmp(data.arg2, "--save", 6);
	if (j != 0)
	{
		ft_putstr_fd("Error\nSecond argument is invalid. Try '--save'.\n", 2);
		exit(0);
	}
}

int	valid_resolution(int c)
{
	if (ft_isdigit(c) || c == 32)
		return (1);
	return (0);
}

void get_resolution(t_data *data)
{
	int i;
	data->y = -1;
	i = data->i + 1;
	while(data->linea[i] != '\0')
	{
		if (!(valid_resolution(data->linea[i])))
			resolution_error();
		i++;
	}
	data->i++;
	if(data->linea[data->i] != ' ')
		resolution_error();
	data->i++;
	while (data->linea[data->i] == ' ')
		data->i++;
	if (ft_isdigit(data->linea[data->i]))
		data->x = ft_atoi(&data->linea[data->i]);
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
	while (data->linea[data->i] == ' ')
		data->i++;
	if (ft_isdigit(data->linea[data->i]))
		data->y = ft_atoi(&data->linea[data->i]);
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
	while (data->linea[data->i] != '\0')
	{
		if(data->linea[data->i] != ' ' )
			resolution_error();
		data->i++;
	}
	if (data->y < 0 || data->x < 0)
		resolution_error();
}

void north_texture(t_data *data)
{
	data->i += 2;
	if (data->linea[data->i] != ' ')
		texture_error();
	while (data->linea[data->i] == ' ')
		data->i++;
	data->north = &data->linea[data->i];
	while(ft_isalpha(data->linea[data->i]) && data->linea[data->i] != ' ')
		data->i++;
}
void south_texture(t_data *data)
{
	data->i += 2;
	if (data->linea[data->i] != ' ')
		texture_error();
	while (data->linea[data->i] == ' ')
		data->i++;
	data->south = &data->linea[data->i];
	while(ft_isalpha(data->linea[data->i]) && data->linea[data->i] != ' ')
		data->i++;
}
void east_texture(t_data *data)
{
	data->i += 2;

	if (data->linea[data->i] != ' ')
		texture_error();
	while (data->linea[data->i] == ' ')
		data->i++;
	data->east = &data->linea[data->i];
	while(ft_isalpha(data->linea[data->i]) && data->linea[data->i] != ' ')
		data->i++;
}
void west_texture(t_data *data)
{
	data->i += 2;
	if (data->linea[data->i] != ' ')
		texture_error();
	while (data->linea[data->i] == ' ')
		data->i++;
	data->west = &data->linea[data->i];
	while(ft_isalpha(data->linea[data->i]) && data->linea[data->i] != ' ')
		data->i++;
}
void sprite_texture(t_data *data)
{
	data->i++;
	while (data->linea[data->i] == ' ')
		data->i++;
	data->sprite = &data->linea[data->i];
	while(ft_isalpha(data->linea[data->i]) && data->linea[data->i] != ' ')
		data->i++;
	if (data->sprite == '\0')
		texture_error();
}

int	valid_rgb(int c)
{
	if (ft_isdigit(c) || c == 44 || c == 32)
		return (1);
	return (0);
}

void rgb_error()
{
	ft_putstr_fd("Error\nRGB Invalid.",2);
	exit(0);
}

void error_check(t_data *data)
{
	int i;
	data->floor[0] = -1;
	data->floor[1] = -1;
	data->floor[2] = -1;


	i = data->i;
	data->rgb_error = 0;
	if (data->linea[i] != ' ' )
		data->rgb_error = 1;
	while (data->linea[i] != '\0')
	{
		if (data->linea[i] == ',')
			data->comma++;
		if (data->linea[i] == '-')
			data->rgb_error = 1;
		if (data->linea[i] == ',' && data->linea[i + 1] == ',' )
			data->rgb_error = 1;
		if (!(valid_rgb(data->linea[i])))
			data->rgb_error = 1;
		i++;
	}
	if( data->comma != 2)
		data->rgb_error = 1;
	
	if (data->rgb_error == 1)
		rgb_error();
	
}


void floor_color(t_data *data)
{
	data->i++;
	error_check(data);	
	while (data->linea[data->i] == ' ')
		data->i++;		
	if (ft_isdigit(data->linea[data->i]))
		data->floor[0] = ft_atoi(&data->linea[data->i]);
	else
		rgb_error();
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
	
	
	if (data->linea[data->i] == ',')
		data->i++;

	if  (ft_isdigit(data->linea[data->i]))
		data->floor[1] = ft_atoi(&data->linea[data->i]);
	else 
		rgb_error();
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
	if (data->linea[data->i] == ',')
		data->i++;
	
	if (ft_isdigit(data->linea[data->i]))
		data->floor[2] = ft_atoi(&data->linea[data->i]);
	else
		rgb_error();
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
	if (data->linea[data->i] != '\0')
		rgb_error();
	if (data->floor[0] > 255)
		rgb_error();
	else if (data->floor[1] > 255)
		rgb_error();
	else if (data->floor[2] > 255)
		rgb_error();
}



void ceiling_color(t_data *data)
{
	data->i++;
	// error_check(data);	
	while (data->linea[data->i] == ' ')
		data->i++;		
	if (ft_isdigit(data->linea[data->i]))
		data->ceiling[0] = ft_atoi(&data->linea[data->i]);
	else
		rgb_error();
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
	if (data->linea[data->i] == ',')
		data->i++;
	if  (ft_isdigit(data->linea[data->i]))
		data->ceiling[1] = ft_atoi(&data->linea[data->i]);
	else 
		rgb_error();
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
	if (data->linea[data->i] == ',')
		data->i++;
	
	if (ft_isdigit(data->linea[data->i]))
		data->ceiling[2] = ft_atoi(&data->linea[data->i]);
	else
		rgb_error();
	while (ft_isdigit(data->linea[data->i]))
		data->i++;
	if (data->linea[data->i] != '\0')
		rgb_error();
	if (data->ceiling[0] > 255 || data->ceiling[1] > 255 || data->ceiling[2] > 255)
		rgb_error();
}

int invalid_map_chars(int c)
{
	if (ft_strchr("012NSEW ", c))
		return(0);
	else
		return(1);
}
void map_error()
{
	ft_putstr_fd("Error\nMap is Invalid", 2);
	exit(0);
}

void map_parser(t_data *data)
{
	char *trim;
	int i;

	i = 0;
	trim = ft_strdup(data->linea);

	while (trim[i])
	{
		if (invalid_map_chars(trim[i]))
			map_error();
		if (trim[i] == ' ')
			trim[i] = '%';
		if (ft_strchr("NSEW", trim[i]))
			data->coord_check++;
		i++;
	}
	
	data->mapY++;
	if (i > data->mapX)
		data->mapX = i;
	// printf("%s\n",trim);
	// free(trim);

}

void map_store(t_data *data)
{

		data->map[data->c] = ft_strdup(data->linea);
		data->c++;

}

int main(int argc, char *argv[])
{
	t_data data;
	int fd;
	char *line = 0;
	int i = 0;
	data.arg1 = argv[1];
	data.arg2 = argv[2];
	data.mapY = 0;
	data.mapX = 0;
	data.coord_check = 0;
	data.c = 0;



	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr_fd("Error\nError opening map\n", 2);
		exit(0);
	}
	if (!data.arg1)
	{
		ft_putstr_fd("Error\nNo map provided\n", 2);
		exit(0);
	}

	if (argc > 3 || argc < 2)
	{
		ft_putstr_fd("Error\nNumber of arguments is invalid\n",2);
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
		else if (data.linea[data.i] == 'N' && data.linea[data.i + 1] == 'O')
			north_texture(&data);
		else if (data.linea[data.i] == 'S' && data.linea[data.i + 1] == ' ')
			sprite_texture(&data);
		else if (data.linea[data.i] == 'S' && data.linea[data.i + 1] != ' ' && 
			data.linea[data.i + 1] != 'O')
				texture_error();
		else if (data.linea[data.i] == 'S' && data.linea[data.i + 1] == 'O')
			south_texture(&data);
		else if (data.linea[data.i] == 'E' && data.linea[data.i + 1] == 'A')
			east_texture(&data);
		else if (data.linea[data.i] == 'W' && data.linea[data.i + 1] == 'E')
			west_texture(&data);
		else if (data.linea[data.i] == 'F')
			floor_color(&data);
		else if (data.linea[data.i] == 'C')
			ceiling_color(&data);	
		else if (data.linea[data.i] == '1' || data.linea[data.i] == '2')
			map_parser(&data);
		
	
	}
	if (data.coord_check != 1)
			map_error();

	close(fd);
	data.map = (char**)malloc(data.mapY * (sizeof(char*)));

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr_fd("Error\nError opening map\n", 2);
		exit(0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		data.linea = line;
		if (data.linea[data.i] == '1' || data.linea[data.i] == '2')
			map_store(&data);
	}
	close(fd);
	printf("\nla x es: %d\n", data.x);
	printf("la y es: %d\n", data.y);
	printf("Norte:%s\n", data.north);
	printf("Sur:%s\n", data.south);
	printf("Este:%s\n", data.east);
	printf("Oeste:%s\n", data.west);
	printf("Sprite:%s\n", data.sprite);
	printf("Floor 1:%d\n", data.floor[0]);
	printf("Floor 2:%d\n", data.floor[1]);
	printf("Floor 3:%d\n", data.floor[2]);
	printf("Ceiling 1:%d\n", data.ceiling[0]);
	printf("Ceiling 2:%d\n", data.ceiling[1]);
	printf("Ceiling 3:%d\n", data.ceiling[2]);
	printf("\nMapX: %d\n",data.mapX);
	printf("MapY: %d\n",data.mapY);
	while (i < data.mapY)
	{
		printf("%s\n", data.map[i]);
		i++;
	}
	free(data.map);
	return (0);
}