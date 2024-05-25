#include "../so_long.h"

void check_new_line(char *s)
{
    int i = 0;
    if (s[0] == '\n')
    {
        write(1,"Error :empty line",17);
        exit(0);
    }
    while (s[i])
    {
        if (s[i] == '\n' && s[i + 1] == '\n')
        {
            write(1,"Error :empty line",10);
            exit(0);
        }
        i++;
    }
     if (s[i - 1] == '\n')
    {
         write(1,"Error :empty line",10);
            exit(0);
    }
}
void parsing(t_mlx_data *inf)
{
    rows_collums(inf);
    check_shape(inf);
    check_map_sides(inf);
    check_valid_characters(inf);
    check_characters_num(inf);
    check_player_place(inf);
    copy_map(inf);
    flood_fill(inf , inf -> x , inf -> y);
    check_path(inf);
    free_map(inf -> copy);
}

void free_map(char **map)
{
    int i;

    if (map == NULL)
        return;
    
    i = 0;
    while (map[i] != NULL)
    {
        free(map[i]);
        i++;
    }
    free(map);
}
