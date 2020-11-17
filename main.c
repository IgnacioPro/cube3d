#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

typedef struct s_vars
{
	void *img;
    void *mlx;
    void *win;
	int win_x;
	int win_y;
	int coord_x;
	int coord_y;
	char *addr;
	int bits_per_pixel;
    int line_length;
	int endian;
	int color;
	void *prueba;

} t_vars;

int close(int keycode, t_vars *vars)
{
    if (keycode == 53)
    	mlx_destroy_window(vars->mlx, vars->win);
	return(0);
}

int print_pixel_clicked(int keycode, int coord_x, int coord_y, t_vars *vars)
{
	mlx_pixel_put(vars->mlx, vars->win, coord_x, coord_y, 0x00ff0000);
	printf("Mouse: %d used on coordinates: %d, %d\n", keycode, coord_x, coord_y);
	return(0);
}

int square (t_vars *vars)
{
    // vars->coord_x = 0;
	// vars->coord_y = 0;
	int square_x = 0;
	int square_y = 0;
    
	while (vars->coord_x + square_x++ <= vars->coord_x + 25)
	{
		square_y = 0;
		while (vars->coord_y + square_y++ <= vars->coord_y + 25)
			mlx_pixel_put(vars->mlx, vars->win, vars->coord_x + square_x, vars->coord_y + square_y, vars->color);
	}
    return(0);
}

int sync_to_image(t_vars *vars)
{
	mlx_sync(1,vars->prueba);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->prueba, vars->coord_x, vars->coord_y);	
	mlx_sync(3, vars->win);
	return(0);
}
int put_texture(t_vars *vars)
{
	// while (vars->coord_x++ <= 2000)
	// {
	// 	vars->coord_y = 0;
	// 	while (vars->coord_y++ <= 2000)
	// 		mlx_put_image_to_window(vars->mlx, vars->win, vars->prueba, vars->coord_x, vars->coord_y);
	// }
	while (vars->coord_x <= 2000)
	{
		vars->coord_y = 0;
		while (vars->coord_y <= 2000)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->prueba, vars->coord_x, vars->coord_y);
			vars->coord_y += 1024;
		}
		vars->coord_x += 1024;
	}
    return(0);
}

// int dot (t_vars *vars)
// {
// 	mlx_pixel_put(vars->mlx, vars->win, vars->coord_x, vars->coord_y, vars->color);
// }

int move_square(int keycode, t_vars *vars)
{
	printf("Has presionado la tecla: %d\n", keycode);
	if(keycode == 123)
		vars->coord_x -= 30;
	if(keycode == 124)
		vars->coord_x += 30;
	if(keycode == 125)
		vars->coord_y += 30;
	if(keycode == 126)
		vars->coord_y -= 30;
	if (keycode == 53)
	{
    	mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}

	// mlx_sync(3, vars->win);
	// mlx_clear_window(vars->mlx, vars->win);
	return(0);
}

// int print_while_clicked(int coord_x, int coord_y, t_vars *vars)
// {
// 	mlx_pixel_put(vars->mlx, vars->win, coord_x, coord_y, 0x00ff0000);
// 	printf("Mouse: %d, %d\n", coord_x, coord_y);
// 	mlx_clear_window(vars->mlx, vars->win);

// 	return(0);
// }

// void            color_pixel(t_vars *vars, int x, int y, int color)
// {
//     char    *dst;

//     dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }

// int cursor(int x, int y, t_vars *vars)
// {
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->prueba, x, y);
// 	return(0);
// }


// int main(void)
// {
//     t_vars vars;
// 	t_vars img;
// 	vars.coord_x = 0;
// 	vars.coord_y = 0;
// 	vars.win_x = 500;
// 	vars.win_y = 500;
// 	vars.color = 0x00ff0000;
// 	int     img_width;
//     int     img_height;
// 	char    *path = "./texture.xpm";

// 	vars.mlx = mlx_init();
// 	// mlx_sync(1, vars.prueba);
// 	vars.prueba = mlx_xpm_file_to_image(vars.mlx, path, &img_width, &img_height);
// 	// mlx_sync(1, vars.prueba);

//     vars.win = mlx_new_window(vars.mlx, 1000, 500, "Iñaki");

// 	// // mlx_put_image_to_window(vars.mlx, vars.win, vars.prueba, vars.coord_x, vars.coord_y);
// 	// mlx_hook(vars.win, 2, 1L<<6, cursor, &vars );
// 	// mlx_loop_hook(vars.mlx, put_texture, &vars);
// 	mlx_hook(vars.win, 2, 1L<<0, move_square, &vars);
// 	// sync_to_image(&vars);
// 	// mlx_loop_hook(vars.mlx,square, &vars);
// 	mlx_loop_hook(vars.mlx,sync_to_image, &vars);
// 	// mlx_put_image_to_window(vars.mlx, vars.win, vars.prueba, vars.coord_x, vars.coord_y);

// 	// mlx_mouse_hook(vars.win, print_pixel_clicked, &vars);
// 	mlx_loop(vars.mlx);
// }

int main(void)
{
	t_vars vars;
	int img_width;
	int img_height;
	char *path = "./texture.xpm";

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 500, "Iñaki");
	vars.prueba = mlx_xpm_file_to_image(vars.mlx, path, &img_width, &img_height);
	mlx_hook(vars.win, 2, 1L<<0, move_square, &vars);
	mlx_loop_hook(vars.mlx,sync_to_image, &vars);
	mlx_loop(vars.mlx);
}
