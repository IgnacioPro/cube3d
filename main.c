#include "mlx.h"
#include <stdio.h>

#include <mlx.h>

typedef struct s_vars
{
	void *img;
    void *mlx;
    void *win;
	int coord_x;
	int coord_y;
	char *addr;
	int bits_per_pixel;
    int line_length;
	int endian;
} t_vars;

int close(int keycode, t_vars *vars)
{
    if (keycode == 53)
    	mlx_destroy_window(vars->mlx, vars->win);
	return(0);
}

int print_pixel_clicked(int keycode, int coord_x, int coord_y, t_vars *vars)
{
	printf("Mouse: %d used on coordinates: %d, %d\n", keycode, coord_x, coord_y);
	return(0);
}

int color_pixel()
{

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

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	mlx_mouse_hook(vars.win, print_pixel_clicked, &vars);
    mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	// mlx_hook(vars.win, 2, 1L<<2, color_pixel, &vars);
	// mlx_pixel_put ( vars.win, void *win_ptr, int x, int y, int color );

	mlx_pixel_put(vars.mlx,vars.win, 1, 1, 0);



    // img.img = mlx_new_image(vars.mlx, 1920, 1080);
    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
    //                              &img.endian);
    // print_pixel_clicked(&img, 3, 5, 0x00FF0000);
    // mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

    mlx_loop(vars.mlx);
}
