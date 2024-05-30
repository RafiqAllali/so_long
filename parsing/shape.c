/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallali <rallali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:31:51 by rallali           #+#    #+#             */
/*   Updated: 2024/05/30 16:54:55 by rallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	rows_collums(t_mlx_data *inf)
{
	inf ->rows = 0;
	while (inf->map[inf -> rows])
	{
		inf->rows++;
	}
	inf ->rows--;
	inf -> collums = 0;
	while (inf -> map[0][inf -> collums] != '\0')
	{
		inf -> collums++;
	}
	inf -> collums--;
}

void	check_shape(t_mlx_data *inf)
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
			j++;
		}
		if (inf -> collums != j - 1)
		{
			write(2, "Error in map shape\n", 20);
			exit(0);
		}
		i++;
	}
}
