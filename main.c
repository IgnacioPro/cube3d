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


int paint_all_window(t_vars *vars)
{
	int x = 0;
	int y = 0;
	while (x++ <= vars->win_x)
	{
//		mlx_pixel_put(vars->mlx, vars->win, x, y, 0x00ff0000);
		y = 0;
		while (y++ <= vars->win_y)
			mlx_pixel_put(vars->mlx, vars->win, x, y, vars->color);
	}
	return(0);
}

// int render_next_frame(t_vars *vars)
// {
// 	paint_all_window(vars);
// 	vars->color += 10;
// 	printf("%x\n", vars->color);

// 	// mlx_clear_window(vars->mlx, vars->win);
// 	return(0);
// }



// int print_while_clicked(int coord_x, int coord_y, t_vars *vars)
// {
// 	mlx_pixel_put(vars->mlx, vars->win, coord_x, coord_y, 0x00ff0000);
// 	printf("Mouse: %d, %d\n", coord_x, coord_y);
// 	mlx_clear_window(vars->mlx, vars->win);

// 	return(0);
// }

int square (t_vars *vars)
{
    int x = 0;
	int y = 0;
    
	while (x++ <= 20)
	{
		y = 0;
		while (y++ <= 20)
			mlx_pixel_put(vars->mlx, vars->win, x, y, 0x00ff0000);
	}

    // mlx_pixel_put(vars->mlx, vars->win, 15, 15, 0x00ff0000);
    return(0);
}

// void            color_pixel(t_vars *vars, int x, int y, int color)
// {
//     char    *dst;

//     dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }

int main(void)
{
    t_vars vars;
	t_vars img;
	vars.win_x = 500;
	vars.win_y = 500;
	vars.color = 0x00ff0000;

    vars.mlx = mlx_init();
	// img.img = mlx_new_image(vars.mlx, 500, 500);
    vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	// mlx_mouse_hook(vars.win, print_pixel_clicked, &vars);
    mlx_hook(vars.win, 2, 1L<<0, close, &vars);
    // mlx_hook(vars.win, 2, 1L<<0, square, &vars);
	// mlx_hook(vars.win, 6, 1L<<8, print_while_clicked, &vars);
	// paint_all_window(&vars);
	// mlx_loop_hook(vars.mlx,render_next_frame, &vars);
	mlx_loop_hook(vars.mlx,square, &vars);
    mlx_loop(vars.mlx);
}

