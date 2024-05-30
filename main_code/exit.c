/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallali <rallali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 02:58:11 by rallali           #+#    #+#             */
/*   Updated: 2024/05/30 15:53:16 by rallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_collectibles(t_mlx_data *inf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (inf -> map[i])
	{
		j = 0;
		while (inf -> map[i][j])
		{
			if (inf -> map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_door_place1(t_mlx_data *inf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (inf -> map[i])
	{
		j = 0;
		while (inf -> map[i][j])
		{
			if (inf -> map[i][j] == 'E')
			{
				inf -> doorx = i;
				inf -> doory = j;
			}
			j++;
		}
		i++;
	}
	check_player_place(inf);
	inf -> map[inf -> doorx][inf -> doory] = '0';
	if (inf -> doorx == inf ->x && inf -> doory == inf -> y)
		close_map(inf);
}

void	draw_map(t_mlx_data *inf)
{
	int	i;
	int	j;

	i = 0;
	while (inf->map[i])
	{
		j = 0;
		while (inf->map[i][j])
		{
			put_images(inf, i, j);
			j++;
		}
		i++;
	}
}
