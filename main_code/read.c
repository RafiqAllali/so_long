/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallali <rallali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:37:13 by rallali           #+#    #+#             */
/*   Updated: 2024/05/30 16:51:22 by rallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	split_map(char *file_content, t_mlx_data *inf)
{
	check_new_line(file_content);
	inf -> map = ft_split(file_content, '\n');
	if (!inf->map)
	{
		free_map(inf->map);
		write(2, "Error :map can t be splitted\n", 29);
		exit(1);
	}
	free(file_content);
}

void	protect_fd(int fd)
{
	if (fd == -1)
	{
		write(2, "Error :file descriptor\n", 24);
		exit(1);
	}
}

void	read_it(t_mlx_data *inf)
{
	int		fd;
	char	*content;
	int		bytes;
	char	buffer[2];

	fd = open(inf->av, O_RDONLY);
	protect_fd(fd);
	content = NULL;
	bytes = read(fd, buffer, sizeof(buffer) - 1);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		content = ft_strjoin(content, buffer);
		bytes = read(fd, buffer, sizeof(buffer) - 1);
	}
	if (!content)
	{
		write(2, "Error :can't be joined\n", 23);
		exit(1);
	}
	split_map(content, inf);
	close(fd);
}
