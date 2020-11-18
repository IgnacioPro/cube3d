#include "mlx.h"

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

#include <math.h>
#include <stdio.h>
typedef struct s_vars
{
	void *mlx;
	void *win;
	double moveSpeed;
	int key;

} t_vars;

int worldMap[mapWidth][mapHeight] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void draw_line(int x, int drawStart, int drawEnd, int color, t_vars *vars)
{
	while (drawStart <= drawEnd)
	{
		mlx_pixel_put(vars->mlx, vars->win, x, drawStart, color);
		drawStart++;
	}

}

void move_player(int keycode, t_vars *vars) //
{
	double moveSpeed = 0.6;
	keycode = vars->key;
}



double ft_abs(double n)
{
	if (n < 0)
		return(-n);
	return(n);
}

int main()
{
	t_vars vars;
	vars.mlx = mlx_init();
	double posX = 22, posY = 12;	  //x and y start position
	double dirX = -1, dirY = 0;		  //initial direction vector
	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	double time = 0;	//time of current frame
	double oldTime = 0; //time of previous frame

	vars.win = mlx_new_window(vars.mlx, screenWidth, screenHeight, "Cube");
	double moveSpeed = 0.6;
	double rotSpeed = 0.6;
	int trex = 0;
	int x = 0;

	while (trex++ < 1000)
	{
		
		while (x < screenWidth)
		{
			double cameraX = 2 * x / (double)screenWidth - 1;
			double rayDirX = dirX + planeX * cameraX;
			double rayDirY = dirY + planeY * cameraX;
			int mapX = posX;
			int mapY = posY;
			double sideDistX;
			double sideDistY;
			double deltaDistX = ft_abs(1 / rayDirX);
			double deltaDistY = ft_abs(1 / rayDirY);
			double perpWallDist;

			int stepX;
			int stepY;
			int hit = 0;
			int side;

			double rotSpeed = 0.6;
			double moveSpeed = 0.6;

			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (posX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - posX) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (posY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
			}
			while (hit == 0)
			{
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				if (worldMap[mapX][mapY] > 0)
					hit = 1;
			}
			if (side == 0)
				perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
			else
				perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

			int lineHeight = (int)(screenHeight / perpWallDist);
			int drawStart = -lineHeight / 2 + screenHeight / 2;
			if (drawStart < 0)
				drawStart = 0;
			int drawEnd = lineHeight / 2 + screenHeight / 2;
			if (drawEnd >= screenHeight)
				drawEnd = screenHeight - 1;
			int color = 0x000000;
			if (worldMap[mapX][mapY] == 1)
				color = 0xD63E1E;
			else if (worldMap[mapX][mapY] == 2)
				color = 0x30D61C;
			else if (worldMap[mapX][mapY] == 3)
				color = 0x16E8E5;
			else if (worldMap[mapX][mapY] == 3)
				color = 0xF958E1;
			else
				color = 0x050405;
			if (side == 1)
				color /= 2;

			draw_line(x, drawStart, drawEnd, color, &vars);
			x++;
		}

		if (vars.key == 126) //up
		{
			printf("%d\n", vars.key);
			if (worldMap[(int)(posX + dirX * moveSpeed)][(int)posY] == 0)
				posX += dirX * moveSpeed;
			if (worldMap[(int)posX][(int)(posY + dirY * moveSpeed)] == 0)
				posY += dirY * moveSpeed;
		}
		if (vars.key == 125) //down
		{
			if (worldMap[(int)(posX - dirX * moveSpeed)][(int)posY] == 0)
				posX -= dirX * moveSpeed;
			if (worldMap[(int)posX][(int)(posY - dirY * moveSpeed)] == 0)
				posY -= dirY * moveSpeed;
		}
		if (vars.key == 124) //right
		{
			double oldDirX = dirX;
			dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
			dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
			double oldPlaneX = planeX;
			planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
			planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
		}
		if (vars.key == 123) //left
		{
			double oldDirX = dirX;
			dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
			dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
			double oldPlaneX = planeX;
			planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
			planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
		}
	}
	mlx_loop(vars.mlx);
}