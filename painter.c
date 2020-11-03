#include "mlx.h"
#include <stdio.h>

typedef struct s_data
{
	int mlx;
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

int print_pixel_clicked(int keycode, int coord_x, int coord_y, t_data *vars)
{
	printf("Mouse: %d used on coordinates: %d, %d\n", keycode, coord_x, coord_y);
	return(0);
}

int main()
{
	void *mlx;
	void *mlx_win;
	t_data img;
	int i;
	int size = 100;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, size + 1, size + 1, "hola");
	img.img = mlx_new_image(mlx, size + 1, size + 1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	while (i++ < size)
	{
		my_mlx_pixel_put(&img, i, 1, 0x00FF0000);
		my_mlx_pixel_put(&img, i, 2, 0x00FF0000);
		my_mlx_pixel_put(&img, 2, i, 0x00FF0000);
		my_mlx_pixel_put(&img, 1, i, 0x00FF0000);
		my_mlx_pixel_put(&img, i, 100, 0x00FF0000);
		my_mlx_pixel_put(&img, i, 101, 0x00FF0000);
		my_mlx_pixel_put(&img, 100, i, 0x00FF0000);
		my_mlx_pixel_put(&img, 101, i, 0x00FF0000);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
