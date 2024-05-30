/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallali <rallali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 03:28:47 by rallali           #+#    #+#             */
/*   Updated: 2024/05/30 16:56:13 by rallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_hook(int keycode, t_mlx_data *inf)
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
	{
		mlx_destroy_window(inf->mlx, inf->win);
		free_images(inf);
		free_map(inf->map);
		exit(0);
	}
	return (0);
}

void	put_images(t_mlx_data *inf, int i, int j)
{
	mlx_put_image_to_window(inf->mlx, inf->win, inf->g_img, j * 60, i * 60);
	if (inf->map[i][j] == '1')
		mlx_put_image_to_window(inf->mlx, inf->win, inf->img, j * 60, i * 60);
	else if (inf->map[i][j] == 'P')
		mlx_put_image_to_window(inf->mlx, inf->win, inf->p_img, j * 60, i * 60);
	else if (inf->map[i][j] == 'C')
		mlx_put_image_to_window(inf->mlx, inf->win, inf->c_img, j * 60, i * 60);
	else if (inf->map[i][j] == 'E')
		mlx_put_image_to_window(inf->mlx, inf->win, inf->d_img, j * 60, i * 60);
}

void	initialize_mlx_and_load_images(t_mlx_data *inf)
{
	int	img_width;
	int	img_height;

	inf->mlx = mlx_init();
	if (!inf->mlx)
	{
		free(inf->mlx);
		write(2, "Error: picture\n", 15);
		exit(1);
	}
	inf->win = mlx_new_window(inf->mlx, (inf->collums + 1) * 60,
			(inf->rows + 1) * 60, "hello");
	inf->img = mlx_xpm_file_to_image(inf->mlx, "images/wall.xpm",
			&img_width, &img_height);
	inf->p_img = mlx_xpm_file_to_image(inf->mlx, "images/hero.xpm",
			&img_width, &img_height);
	inf->c_img = mlx_xpm_file_to_image(inf->mlx, "images/window.xpm",
			&img_width, &img_height);
	inf->g_img = mlx_xpm_file_to_image(inf->mlx, "images/floor.xpm",
			&img_width, &img_height);
	inf->d_img = mlx_xpm_file_to_image(inf->mlx, "images/door1.xpm",
			&img_width, &img_height);
	protect_image(inf);
}

int	check_ber(char *s)
{
	char	*ber;
	int		i;
	int		j;

	ber = ".ber";
	j = 0;
	i = 0;
	i = ft_strlen(s);
	i = i - 4;
	while (s[i])
	{
		if (s[i] == ber[j])
		{
			i++;
			j++;
		}
		else
		{
			return (1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx_data	inf;

	inf.av = av[1];
	if (ac != 2)
	{
		write(2, "Error: number of arguments\n", 27);
		return (0);
	}
	if (check_ber(av[1]) == 1)
	{
		write(2, "Error: wrong file name\n", 23);
		exit(1);
	}
	read_it(&inf);
	parsing(&inf);
	initialize_mlx_and_load_images(&inf);
	draw_map(&inf);
	mlx_key_hook(inf.win, &ft_hook, &inf);
	mlx_hook(inf.win, 17, 0, &close_map, &inf);
	mlx_loop(inf.mlx);
}
