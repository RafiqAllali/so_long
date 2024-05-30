/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallali <rallali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 03:14:11 by rallali           #+#    #+#             */
/*   Updated: 2024/05/30 16:50:28 by rallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_images(t_mlx_data *inf)
{
	if (inf->img)
	{
		mlx_destroy_image(inf->mlx, inf->img);
	}
	if (inf->p_img)
	{
		mlx_destroy_image(inf->mlx, inf->p_img);
	}
	if (inf->c_img)
	{
		mlx_destroy_image(inf->mlx, inf->c_img);
	}
	if (inf->g_img)
	{
		mlx_destroy_image(inf->mlx, inf->g_img);
	}
	if (inf->d_img)
	{
		mlx_destroy_image(inf->mlx, inf->d_img);
	}
}

void	free_map(char **map)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	close_map(t_mlx_data *inf)
{
	mlx_destroy_window(inf->mlx, inf->win);
	free_images(inf);
	free_map(inf->map);
	exit (0);
}

void	protect_image(t_mlx_data *inf)
{
	if (!inf -> img || !inf -> p_img || !inf -> c_img
		|| !inf -> d_img || !inf -> g_img)
	{
		write(2, "Error: picture\n", 16);
		free_images(inf);
		free_map(inf->map);
		exit(1);
	}
}
