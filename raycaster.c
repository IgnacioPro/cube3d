#include "cubelib.h"
#include "./getnextline/get_next_line_bonus.h"

int worldMap[mapWidth][mapHeight] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 2, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 2, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 2, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 2, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void my_mlx_pixel_put(t_img *imagen, int x, int y, int color)
{
	char *dst;
	int offset = (y * imagen->line_length + x *(imagen->bits_per_pixel / 8));
	dst = imagen->addr + (y * imagen->line_length + x * (imagen->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void sprite_dimensions(t_vars *vars)
{
	while (vars->counter-- > 0)
	{
		vars->sprite[vars->counter].x = vars->sprite[vars->counter].coordX - vars->posX + 0.5;
		vars->sprite[vars->counter].y = vars->sprite[vars->counter].coordY - vars->posY + 0.5;
		vars->invDet = 1 / (vars->planeX * vars->dirY - vars->dirX * vars->planeY);
		vars->transformX = vars->invDet * (vars->dirY * vars->sprite[vars->counter].x - vars->dirX * vars->sprite[vars->counter].y);
		vars->transformY = vars->invDet * (-vars->planeY * vars->sprite[vars->counter].x + vars->planeX * vars->sprite[vars->counter].y);
		vars->spriteScreenX = (int)((vars->screenwidth / 2) * (1 + vars->transformX / vars->transformY));

		//calcular altura sprites en pantalla
		vars->spriteHeight = abs((int)(vars->screenheight / (vars->transformY)));
		//calcular lineas
		vars->drawStartY = -vars->spriteHeight / 2 + vars->screenheight / 2;
		if (vars->drawStartY < 0)
			vars->drawStartY = 0;
		vars->drawEndY = vars->spriteHeight / 2 + vars->screenheight / 2;
		if (vars->drawEndY >= vars->screenheight)
			vars->drawEndY = vars->screenheight - 1;
		//calcular anchura sprite
		vars->spriteWidth = abs((int)(vars->screenheight / (vars->transformY)));
		vars->drawStartX = -vars->spriteWidth / 2 + vars->spriteScreenX;
		if (vars->drawStartX < 0)
			vars->drawStartX = 0;
		vars->drawEndX = vars->spriteWidth / 2 + vars->spriteScreenX;
		if (vars->drawEndX >= vars->screenwidth)
			vars->drawEndX = vars->screenwidth - 1;
		draw_sprite(0, vars);
	}
}

void load_textures(t_vars *vars)
{
	vars->norte.img = mlx_xpm_file_to_image(vars->mlx, "./srcs/textures/mossy.xpm", &vars->norte.height, &vars->norte.width);
	vars->sur.img = mlx_xpm_file_to_image(vars->mlx, "./srcs/textures/redbrick.xpm", &vars->sur.height, &vars->sur.width);
	vars->este.img = mlx_xpm_file_to_image(vars->mlx, "./srcs/textures/wood.xpm", &vars->este.height, &vars->este.width);
	vars->oeste.img = mlx_xpm_file_to_image(vars->mlx, "./srcs/textures/greystone.xpm", &vars->oeste.height, &vars->oeste.width);
	vars->suelo.img = mlx_xpm_file_to_image(vars->mlx, "./srcs/textures/colorstone.xpm", &vars->suelo.height, &vars->suelo.width);
	vars->columna.img = mlx_xpm_file_to_image(vars->mlx, "./srcs/textures/pillar.xpm", &vars->columna.height, &vars->columna.width);
}

int move_player_press(int keycode, t_vars *vars)
{
	if (keycode == 13)// W
		vars->w = 1;	
   	if (keycode == 1) // S
		vars->s = 1;
   	if (keycode == 0) // a
		vars->a = 1;
   	if (keycode == 2)
   		vars->d = 1; // D
	if (keycode == 124)
		vars->right = 1;
	if (keycode == 123)
		vars->left = 1;	
	// printf("%d\n", vars->w);

	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int move_player_release(int keycode, t_vars *vars)
{
	if (keycode == 13)
		vars->w = 0;	
   	if (keycode == 1) 
		vars->s = 0;
   	if (keycode == 0) 
		vars->a = 0;
   	if (keycode == 2)
   		vars->d = 0; 
	if (keycode == 124)
		vars->right = 0;
	if (keycode == 123)
		vars->left = 0;	
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->sprite);
		exit(0);
	}
	return (0);
}

// double ft_abs(double n)
// {
// 	if (n < 0)
// 		return (-n);
// 	return (n);
// }

void calculate_sprite_dist(t_vars *vars)
{
	int i;

	i = vars->num_sprites;
	while (i-- > 0)
		vars->sprite[i].distance = ((vars->posX - vars->sprite[i].coordX) * (vars->posX - vars->sprite[i].coordX) + 
			(vars->posY - vars->sprite[i].coordY) * (vars->posY - vars->sprite[i].coordY));
}

void sort_sprites(t_vars *vars)
{
	t_sprite tmp;

	int i;
	int j;

	i = 0;
	j = vars->num_sprites;
	while(j > 0)
	{
		while (i < vars->num_sprites - 1)
		{
			if (vars->sprite[i].distance > vars->sprite[i + 1].distance)
			{
				tmp = vars->sprite[i];
				vars->sprite[i] = vars->sprite [i +1];
				vars->sprite[i + 1] = tmp;
			}
			i++;
		}
		j--;
	}
}

void calculate_sprites(t_vars *vars)
{
	int x;
	int y;
	int i;

	i = 0;
	x = 0;
	while (x < mapWidth)
	{
		y = 0;
		while (y < mapHeight)
		{
			if (worldMap[x][y] == 2)
				i++;
			y++;
		}
		x++;
	}
	vars->num_sprites = i;
	vars->sprite = (t_sprite *)malloc(i * sizeof(t_sprite));
	x = 0;
	i = 0;
	while (x < mapWidth)
	{
		y = 0;

		while (y < mapHeight)
		{
			if (worldMap[x][y] == 2)
			{
				vars->sprite[i].coordX = x;
				vars->sprite[i].coordY = y;
				i++;
			}
			y++;
		}
		x++;
	}
}


void textures_to_struc(t_vars *vars)
{
	if (vars->side == 0 && vars->stepX == -1)
		vars->buffer = (int *)mlx_get_data_addr(vars->norte.img, &vars->norte.bits_per_pixel, &vars->norte.line_length, &vars->norte.endian);

	else if (vars->side == 0 && vars->stepX == 1)
		vars->buffer = (int *)mlx_get_data_addr(vars->sur.img, &vars->sur.bits_per_pixel, &vars->sur.line_length, &vars->sur.endian);

	else if (vars->side == 1 && vars->stepY == 1)
		vars->buffer = (int *)mlx_get_data_addr(vars->este.img, &vars->este.bits_per_pixel, &vars->este.line_length, &vars->este.endian);

	else if (vars->side == 1 && vars->stepY == -1)
		vars->buffer = (int *)mlx_get_data_addr(vars->oeste.img, &vars->oeste.bits_per_pixel, &vars->oeste.line_length, &vars->oeste.endian);
}

int		quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
}

int render_frame(t_vars *vars)
{
	vars->imagen.img = mlx_new_image(vars->mlx, vars->screenwidth, vars->screenheight);
	vars->imagen.addr = mlx_get_data_addr(vars->imagen.img, &vars->imagen.bits_per_pixel, &vars->imagen.line_length, &vars->imagen.endian);
	vars->i = 0;


	while (vars->i < vars->screenwidth)
	{
		vars->cameraX = 2 * vars->i / (double)vars->screenwidth - 1;
		vars->rayDirX = vars->dirX + vars->planeX * vars->cameraX;
		vars->rayDirY = vars->dirY + vars->planeY * vars->cameraX;
		vars->mapX = (int)vars->posX; // casteado a int
		vars->mapY = (int)vars->posY; // casteado a int
		
		vars->deltaDistX = fabs(1 / vars->rayDirX);
		vars->deltaDistY = fabs(1 / vars->rayDirY);

		// vars->deltaDistX = (vars->rayDirY == 0) ? 0 : ((vars->rayDirX == 0) ? 1 : fabs(1 / vars->rayDirX));
      	// vars->deltaDistY = (vars->rayDirX == 0) ? 0 : ((vars->rayDirY == 0) ? 1 : fabs(1 / vars->rayDirY));
		vars->hit = 0;
		// double texPos;
		// int texX;

		if (vars->rayDirX < 0)
		{
			vars->stepX = -1;
			vars->sideDistX = (vars->posX - vars->mapX) * vars->deltaDistX;
		}
		else
		{
			vars->stepX = 1;
			vars->sideDistX = (vars->mapX + 1.0 - vars->posX) * vars->deltaDistX;
		}
		if (vars->rayDirY < 0)
		{
			vars->stepY = -1;
			vars->sideDistY = (vars->posY - vars->mapY) * vars->deltaDistY;
		}
		else
		{
			vars->stepY = 1;
			vars->sideDistY = (vars->mapY + 1.0 - vars->posY) * vars->deltaDistY;
		}
		while (vars->hit == 0)
		{
			if (vars->sideDistX < vars->sideDistY)
			{
				vars->sideDistX += vars->deltaDistX;
				vars->mapX += vars->stepX;
				vars->side = 0;
			}
			else
			{
				vars->sideDistY += vars->deltaDistY;
				vars->mapY += vars->stepY;
				vars->side = 1;
			}
			if (worldMap[vars->mapX][vars->mapY] == 1)
				vars->hit = 1;
		}
		if (vars->side == 0)
			vars->perpWallDist = (vars->mapX - vars->posX + (1 - vars->stepX) / 2) / vars->rayDirX;
		else
			vars->perpWallDist = (vars->mapY - vars->posY + (1 - vars->stepY) / 2) / vars->rayDirY;

		vars->lineHeight = (int)(vars->screenheight / vars->perpWallDist);
		vars->drawStart = -vars->lineHeight / 2 + vars->screenheight / 2;
		if (vars->drawStart < 0)
			vars->drawStart = 0;
		vars->drawEnd = vars->lineHeight / 2 + vars->screenheight / 2;
		if (vars->drawEnd >= vars->screenheight)
			vars->drawEnd = vars->screenheight - 1;

		textures_to_struc(vars);

		if (vars->side == 0)
			vars->wallX = vars->posY + vars->perpWallDist * vars->rayDirY;
		else
			vars->wallX = vars->posX + vars->perpWallDist * vars->rayDirX;
		vars->wallX -= floor(vars->wallX);

		vars->texX = (int)(vars->wallX * ((double)texWidth));
		if (vars->side == 0 && vars->rayDirX > 0)
			vars->texX = texWidth - vars->texX - 1;
		if (vars->side == 1 && vars->rayDirY < 0)
			vars->texX = texWidth - vars->texX - 1;

		draw_walls(vars->i, vars->drawStart, vars->drawEnd, 0, &vars->imagen, vars);
		draw_sky_floor(vars->i, vars->drawStart, vars->drawEnd,&vars->imagen, vars);
		vars->ZBuffer[vars->i] = vars->perpWallDist;
		vars->i++;
	}
	vars->buffer = (int *)mlx_get_data_addr(vars->columna.img, &vars->columna.bits_per_pixel, &vars->columna.line_length, &vars->columna.endian);
	calculate_sprite_dist(vars);
	sort_sprites(vars);
	vars->counter = vars->num_sprites;
	sprite_dimensions(vars);

	move_up(vars);
	move_down(vars);
	move_left(vars);
	move_right(vars);
	move_camera(vars);
	
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imagen.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->imagen.img);
	return (0);
}


int main(int argc, char *argv[] )
{
	t_vars vars;
	vars.i = 0;
	// t_vars textura_norte;
	vars.screenheight = 480;
	vars.screenwidth = 640;
	
	vars.moveSpeed = 0.1;
	vars.rotSpeed = 0.1;
	vars.posX = 22;
	vars.posY = 11;
	vars.dirX = -1;
	vars.dirY = 0;
	vars.planeX = 0;
	vars.planeY = 0.66;
	vars.a = 0;
	vars.d = 0;
	vars.w = 0;
	vars.s = 0;
	vars.left = 0;
	vars.right = 0;
	// int x = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.screenwidth, vars.screenheight, "Cube");

	int fd;
	char *line = 0;
	char	*lineadress[66];
	int j = 0;
	int i;
	if (!(fd = open("map.cub", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		// lineadress[j - 1] = line;
		j++;
	}
	// get_next_line(1, )
	//cambiar variables de texturas en la estructura
	load_textures(&vars);
	calculate_sprites(&vars);
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_hook(vars.win, 2, 1L << 0, move_player_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, move_player_release, &vars);

	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.win);
	free(vars.sprite);
	// mlx_hook(vars.win, 33, 1L << 17, quit, &vars);
}
