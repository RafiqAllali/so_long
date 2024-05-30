/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapsides.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallali <rallali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:50:04 by rallali           #+#    #+#             */
/*   Updated: 2024/05/30 16:54:47 by rallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_sides2(t_mlx_data *inf)
{
	int	i;

	i = 0;
	while (inf -> map[i])
	{
		if (inf ->map[i][0] != '1' || inf -> map[i][inf -> collums] != '1')
		{
			write(2, "Error :invalid map\n", 19);
			exit(0);
		}
		i++;
	}
}

void	check_map_sides(t_mlx_data *inf)
{
	int	j;

	j = 0;
	while (inf -> map[0][j])
	{
		if (inf ->map[0][j] != '1' || inf -> map[inf ->rows][j] != '1')
		{
			write(2, "Error :invalid map\n", 19);
			exit(0);
		}
		j++;
	}
	check_map_sides2(inf);
}
