#include "../so_long.h"
int ft_hook(int keycode,t_mlx_data *inf)
{
    if (keycode == 126 || keycode == 13)
		move_up(inf);
	else if (keycode == 124 || keycode == 2)
		move_right(inf);
	else if (keycode == 125 || keycode == 1)
		move_down(inf);
	else if (keycode == 123 || keycode == 0)
		move_left(inf);
	else if (keycode == 53)
		exit(0);
		
		return (0);
}
void draw_map(t_mlx_data *inf)
{
    int i;
    int j;

    i = 0;
        while (inf-> map[i])
        {
        j = 0;
        while (inf-> map[i][j])
        {
            mlx_put_image_to_window(inf->mlx, inf->win, inf->g_img, j * 60, i * 60);
            if (inf-> map[i][j] == '1')
                mlx_put_image_to_window(inf->mlx, inf->win, inf->img, j * 60, i * 60);
            else if (inf -> map[i][j] == 'P')
                mlx_put_image_to_window(inf->mlx, inf->win, inf->p_img, j * 60, i * 60);
            else if (inf -> map[i][j] == 'C')
                mlx_put_image_to_window(inf->mlx, inf->win, inf->c_img, j * 60, i * 60);
            else if (inf ->map[i][j] == 'E')
                mlx_put_image_to_window(inf->mlx, inf->win, inf->d_img, j * 60, i * 60);
            j++;
        }
        i++;
    }
}
void initialize_mlx_and_load_images(t_mlx_data *inf)
{

    int img_width, img_height;

    inf->mlx = mlx_init();
    inf->win = mlx_new_window(inf->mlx, (inf -> collums + 1) * 60, (inf -> rows + 1) * 60, "hello");

    inf->img = mlx_xpm_file_to_image(inf->mlx, "images/wall.xpm", &img_width, &img_height);
    inf->p_img = mlx_xpm_file_to_image(inf->mlx, "images/hero.xpm", &img_width, &img_height);
    inf->c_img = mlx_xpm_file_to_image(inf->mlx, "images/window.xpm", &img_width, &img_height);
    inf->g_img = mlx_xpm_file_to_image(inf->mlx, "images/floor.xpm", &img_width, &img_height);
    inf->d_img = mlx_xpm_file_to_image(inf->mlx, "images/door1.xpm", &img_width, &img_height);
}
int close_map(t_mlx_data *inf)
{
    free(inf -> map);
    exit(0);
}
int main (int ac , char **av)
{
    t_mlx_data inf;
    int fd;
    inf.count = 0;
    char buffer[2];
    char *file_content;
    int bytes_read;
    inf.av = av[1];
    if (ac != 2)
    {
        return (0);
    }
    fd = open(av[1], O_RDONLY);
    file_content = NULL;
    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0)
    {
        buffer[bytes_read] = '\0';
        file_content = ft_strjoin(file_content, buffer);
    }

    inf.fd = fd;
    check_new_line(file_content);
    close(fd);
    inf.map = ft_split(file_content, '\n');
    free(file_content);
    parsing(&inf);
    initialize_mlx_and_load_images(&inf);
    draw_map(&inf);
    mlx_key_hook(inf.win, &ft_hook, &inf);
    mlx_hook(inf.win,17,0,&close_map,&inf);
    mlx_loop(inf.mlx);
    free_map(inf.map);
}
