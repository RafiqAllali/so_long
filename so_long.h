/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallali <rallali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:06:33 by rallali           #+#    #+#             */
/*   Updated: 2024/05/30 16:05:56 by rallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*p_img;
	void	*c_img;
	void	*g_img;
	void	*d_img;
	void	*open;
	char	**map;
	char	**copy;
	char	*av;
	int		doorx;
	int		doory;
	int		rows;
	int		collums;
	int		x;
	int		y;
	int		count;
}	t_mlx_data;

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *str, char *str1);
void	ft_putchar(char c);
void	ft_putnbr(int n);
char	**ft_split(char const *s, char c);
void	check_door_place1(t_mlx_data *inf);
int		check_collectibles(t_mlx_data *inf);
void	free_images(t_mlx_data *inf);
void	free_map(char **map);
int		ft_hook(int keycode, t_mlx_data *inf);
void	draw_map(t_mlx_data *inf);
void	initialize_mlx_and_load_images(t_mlx_data *inf);
int		check_ber(char *s);
void	move_up(t_mlx_data *inf);
void	move_down(t_mlx_data *inf);
void	move_right(t_mlx_data *inf);
void	move_left(t_mlx_data *inf);
void	split_map(char *file_content, t_mlx_data *inf);
void	read_it(t_mlx_data *inf);
void	check_valid_characters(t_mlx_data *inf);
void	check_error(int player, int door, int collectibles);
void	check_characters_num(t_mlx_data *inf);
void	check_player_place(t_mlx_data *inf);
void	check_path(t_mlx_data *inf);
void	protect(int fd, int bytes_read, char *s, char **copy);
void	copy_map(t_mlx_data *inf);
int		close_map(t_mlx_data *inf);
void	flood_fill(t_mlx_data *inf, int x, int y);
void	check_map_sides2(t_mlx_data *inf);
void	check_map_sides(t_mlx_data *inf);
void	rows_collums(t_mlx_data *inf);
void	check_shape(t_mlx_data *inf);
void	check_new_line(char *s);
void	parsing(t_mlx_data *inf);
void	protect_image(t_mlx_data *inf);
void	put_images(t_mlx_data *inf, int i, int j);
#endif