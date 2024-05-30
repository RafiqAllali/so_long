/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallali <rallali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:54:17 by rallali           #+#    #+#             */
/*   Updated: 2024/05/30 16:52:21 by rallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_valid_characters(t_mlx_data *inf)
{
	int	i;
	int	j;

	i = 0;
	while (inf -> map[i])
	{
		j = 0;
		while (inf -> map[i][j])
		{
			if (inf -> map[i][j] != '1' && inf -> map[i][j] != 'P' &&
			inf -> map[i][j] != 'E' && inf->map[i][j]
			!= '0' && inf -> map[i][j] != 'C')
			{
				write(2, "Error :invalid character\n", 25);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	check_error(int player, int door, int collectibles)
{
	if (player < 1)
	{
		write(2, "Error :missing player\n", 22);
		exit(0);
	}
	if (door < 1)
	{
		write(2, "Error :missing door\n", 20);
		exit(0);
	}
	if (collectibles < 1)
	{
		write(2, "Error :add collectibles\n", 24);
		exit(0);
	}
	if (player > 1)
	{
		write(2, "Error :multiple players\n", 24);
		exit(0);
	}
	if (door > 1)
	{
		write(2, "Error :multiple doors\n", 22);
		exit(0);
	}
}

void	check_characters_num(t_mlx_data *inf)
{
	int	i;
	int	j;
	int	player;
	int	door;
	int	collectibles;

	i = 0;
	player = 0;
	door = 0;
	collectibles = 0;
	while (inf -> map[i])
	{
		j = 0;
		while (inf -> map[i][j++])
		{
			if (inf -> map[i][j] == 'P')
				player++;
			if (inf -> map[i][j] == 'E')
				door++;
			if (inf -> map[i][j] == 'C')
				collectibles = 1;
		}
		i++;
	}
	check_error(player, door, collectibles);
}
