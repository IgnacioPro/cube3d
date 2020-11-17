#include "mlx.h"

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

#include <math.h>

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

typedef struct s_vars
{
  void *mlx;
  void *win;

} t_vars;

int main()
{
  t_vars vars;
  double posX = 22, posY = 12;      //x and y start position
  double dirX = -1, dirY = 0;       //initial direction vector
  double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

  double time = 0;    //time of current frame
  double oldTime = 0; //time of previous frame

  vars.mlx = mlx_init();
  vars.win = mlx_new_window(vars.mlx, screenWidth, screenHeight, "Cube");
  mlx_loop(vars.mlx);

  while (1)
  {
	 int x = 0;
   while( x++ < w)
   {
	   double cameraX = 2 * x / double(w) - 1;
	   double rayDirX = dirX + planeX * cameraX;
	   double rayDirY = dirY + planeY * cameraX;
	   int mapX = int(posX);
	   int mapY = int(posY);
	   double sideDistX;
	   double sideDistY;
	   double deltaDistX = abs(1 / rayDirX);
	   double deltaDistY = abs(1 / rayDirY);
	   double perpWallDist;
	   
	   int stepX;
	   int stepY;
	   int hit = 0;
	   int side;
	   
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
			   sideDistX += destaDistX;
			   mapX += stepX;
			   side = 0;
		   }
		   else
		   {
			   sideDisty += deltaDistY;
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
	   int lineHeight = (int)(h / perpWallDist);
	   int drawStart = -lineheight / 2 + h / 2;
	   if (drawStart < 0)
		   drawStart = 0;
	   int drawEnd = lineHeight / 2 + h /2;
	   if (drawEnd >= h)
		   drawEnd = h - 1;
	   int color = 0x000000;
	   if (worldMap[mapX][mapY] = 1)
		   color == rojo;
	   else if (worldMap[mapX][mapY] = 2)
		   color == azul; 
	   else if (worldMap[mapX][mapY] = 3)
		   color == verde;
	   else if (worldMap[mapX][mapY] = 3)
		   color == blanco;
	   else
		   color == negro;
	   
	   if (side == 1)
		   color /= 2;
	   
	   draw_line(int x, int drawStart, int drawEnd, int color, t_vars *vars)
	   {
		   while (drawStart++ <= drawEnd)
			   mlx_pixel_put(vars->mlx, vars->win, x, drawStart, color);
	   }//pixel_put

   }



}
