#ifndef SO_LONG_H
#define SO_LONG_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct s_mlx_data
{
    void    *mlx;
    void    *win;
    void    *img;
    void    *p_img;
    void    *c_img;
    void    *g_img;
    void    *d_img;
    void    *open;
    char    **map;
    char    **copy;
    char    *copy_content;
    char    *av;
    int     fd;
    int     doorx;
    int     doory;
    int     rows;
    int     collums;
    int     x;
    int     y;
    int     count;

}  t_mlx_data;
char	*ft_strjoin(char *str, char *str1);
char	**ft_split(char const *s, char c);
void rows_collums(t_mlx_data *inf);
void check_shape(t_mlx_data *inf);
void check_valid_characters(t_mlx_data *inf);
void check_characters_num(t_mlx_data *inf);
void check_how_many(t_mlx_data *inf);
void check_map_sides(t_mlx_data *inf);
void check_map_side2(t_mlx_data *inf);
void check_new_line(char *s);
void check_player_place(t_mlx_data *inf);
void    copy_map(t_mlx_data *inf);
void check_path(t_mlx_data *inf);
void flood_fill(t_mlx_data *inf ,int x , int y);
void free_map(char **map);
void parsing(t_mlx_data *inf);
void free_map(char **map);
void check_new_line(char *s);
void	move_up(t_mlx_data * inf);
void	move_right(t_mlx_data * inf);
void	move_left(t_mlx_data * inf);
void	move_down(t_mlx_data * inf);
int 	check_collectibles(t_mlx_data *inf);
void check_door_place1(t_mlx_data *inf);
void	ft_putnbr(int n);
void ft_putchar(char c);
char	*ft_ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
#endif