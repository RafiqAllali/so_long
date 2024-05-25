#include "../so_long.h"

void	move_up(t_mlx_data * inf)
{
        int  i = 0;
		int l = 60;

		check_player_place(inf);
	if (inf->map[inf->x - 1][inf->y] != 49 && inf->map[inf->x - 1][inf->y] != 'E')
	{
		inf->map[inf->x][inf->y] = 48;
		inf->map[inf->x - 1][inf->y] = 80;


		inf->p_img = mlx_xpm_file_to_image(inf->mlx, "images/heroup.xpm", &l, &l);
	
		mlx_put_image_to_window(inf -> mlx , inf-> win,inf->g_img,inf->y * 60 , (inf-> x) * 60);
		mlx_put_image_to_window(inf->mlx,inf->win,inf->p_img,(inf->y) * 60 , (inf->x -1) * 60);
	}
    	if (check_collectibles(inf) == 0)
	 {
		check_door_place1(inf);
	 }
     i++;
    inf -> count  = i + inf ->count;
	ft_putnbr(inf -> count);
	write(1,"\n",1);
}

void	move_down(t_mlx_data * inf)
{		
		int  i = 0;
		int l = 60;
		check_player_place(inf);
	if (inf->map[inf->x + 1][inf->y] != 49 && inf->map[inf->x + 1][inf->y] != 'E')
	{
		inf->map[inf->x][inf->y] = 48;
		inf->map[inf->x + 1][inf->y] = 80;


		inf->p_img = mlx_xpm_file_to_image(inf->mlx, "images/herodown.xpm", &l, &l);
	
		mlx_put_image_to_window(inf -> mlx , inf-> win,inf->g_img,inf->y * 60 , (inf-> x) * 60);
		mlx_put_image_to_window(inf->mlx,inf->win,inf->p_img,(inf->y) * 60 , (inf->x + 1) * 60);
	}
    	if (check_collectibles(inf) == 0)
	 {
		check_door_place1(inf);
	 }
	  i++;
    inf -> count  = i + inf ->count;
	ft_putnbr(inf -> count);
	write(1,"\n",1);
}
void	move_right(t_mlx_data *inf)
{		
		int i = 0;
		int l = 60;
		check_player_place(inf);
	if (inf->map[inf->x][inf->y + 1] != 49 && inf->map[inf->x][inf->y + 1] != 'E')
	{
		inf->map[inf->x][inf->y] = 48;
		inf->map[inf->x][inf->y +1] = 80;


		inf->p_img = mlx_xpm_file_to_image(inf->mlx, "images/hero.xpm", &l, &l);
	
		mlx_put_image_to_window(inf -> mlx , inf-> win,inf->g_img,inf->y * 60 , (inf-> x) * 60);
		mlx_put_image_to_window(inf->mlx,inf->win,inf->p_img,(inf->y + 1) * 60 , (inf->x) * 60);
	}
    	if (check_collectibles(inf) == 0)
	 {
		check_door_place1(inf);
	 }
	  i++;
    inf -> count  = i + inf ->count;
	ft_putnbr(inf -> count);
	write(1,"\n",1);
}
void	move_left(t_mlx_data * inf)
{		
		int i = 0;
		int l = 60;
		check_player_place(inf);
	if (inf->map[inf->x][inf->y - 1] != 49 && inf->map[inf->x][inf->y - 1] != 'E')
	{
		inf->map[inf->x][inf->y] = 48;
		inf->map[inf->x][inf->y -1] = 80;


		inf->p_img = mlx_xpm_file_to_image(inf->mlx, "images/heroleft.xpm", &l, &l);
	
		mlx_put_image_to_window(inf -> mlx , inf-> win,inf->g_img,inf->y * 60 , (inf-> x) * 60);
		mlx_put_image_to_window(inf->mlx,inf->win,inf->p_img,(inf->y - 1) * 60 , (inf->x) * 60);
	}
    	if (check_collectibles(inf) == 0)
	 {
		check_door_place1(inf);
	 }
	  i++;
    inf -> count  = i + inf ->count;
	ft_putnbr(inf -> count);
	write(1,"\n",1);
}
