/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallali <rallali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 02:52:50 by rallali           #+#    #+#             */
/*   Updated: 2024/05/30 16:55:28 by rallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_new_line(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '\n')
	{
		write(2, "Error :empty line\n", 19);
		exit(0);
	}
	while (s[i])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
		{
			write(2, "Error :empty line\n", 19);
			exit(0);
		}
		i++;
	}
	if (s[i - 1] == '\n')
	{
		write(2, "Error :empty line\n", 19);
		exit(0);
	}
}

void	parsing(t_mlx_data *inf)
{
	rows_collums(inf);
	if (inf -> rows > 135 || inf -> collums > 135)
	{
		write(2, "Error :invalid map\n", 19);
		exit(1);
	}
	check_shape(inf);
	check_map_sides(inf);
	check_valid_characters(inf);
	check_characters_num(inf);
	check_player_place(inf);
	copy_map(inf);
	flood_fill(inf, inf -> x, inf -> y);
	check_path(inf);
	free_map(inf -> copy);
}
