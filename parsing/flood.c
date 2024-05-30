/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallali <rallali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:03:42 by rallali           #+#    #+#             */
/*   Updated: 2024/05/30 16:52:53 by rallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_player_place(t_mlx_data *inf)
{
	int	i;
	int	j;

	i = 0;
	while (inf->map[i])
	{
		j = 0;
		while (inf->map[i][j])
		{
			if (inf->map[i][j] == 'P')
			{
				inf -> x = i;
				inf -> y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	check_path(t_mlx_data *inf)
{
	int	i;
	int	j;

	i = 0;
	while (inf ->copy[i])
	{
		j = 0;
		while (inf -> copy[i][j])
		{
			if (inf->copy[i][j] != '1' && inf -> copy[i][j] != 'T'
			&& inf -> copy[i][j] != 'F' && inf -> copy[i][j] != '0')
			{
				write(2, "Error :wrong path\n", 18);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	protect(int fd, int bytes_read, char *s, char **copy)
{
	if (fd == -1)
	{
		perror("Error");
		exit(1);
	}
	if (bytes_read == -1)
	{
		perror("Error");
		exit(1);
	}
	if (!s)
	{
		perror("Error");
		exit(1);
	}
	if (!copy)
	{
		perror("Error");
		exit(1);
	}
}

void	copy_map(t_mlx_data *inf)
{
	int		fd;
	char	buffer[2];
	char	*file_content;
	int		bytes_read;

	fd = open(inf -> av, O_RDONLY);
	file_content = NULL;
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		file_content = ft_strjoin(file_content, buffer);
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	}
	if (!file_content)
	{
		free(file_content);
		write(2, "Error :can t be joined\n", 24);
		exit(1);
	}
	inf->copy = ft_split(file_content, '\n');
	free(file_content);
	protect(fd, bytes_read, file_content, inf-> copy);
	close(fd);
}

void	flood_fill(t_mlx_data *inf, int x, int y)
{
	if (inf -> copy[x][y] == '1' || inf -> copy[x][y] == 'F'
		|| inf -> copy[x][y] == 'T')
		return ;
	if (inf -> copy[x][y] == 'E')
	{
		inf -> copy[x][y] = 'T';
		return ;
	}
	inf -> copy[x][y] = 'F';
	flood_fill(inf, x + 1, y);
	flood_fill(inf, x - 1, y);
	flood_fill(inf, x, y + 1);
	flood_fill(inf, x, y - 1);
}
