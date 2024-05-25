#include "../so_long.h"

void check_valid_characters(t_mlx_data *inf)
{
    int i;
    int j;
    
    i = 0;
    while (inf -> map[i])
    {
        j = 0;
        while (inf -> map[i][j])
        {
            if (inf -> map[i][j] != '1' && inf -> map[i][j] != 'P' && inf -> map[i][j] != 'E' && inf->map[i][j] != '0' && inf -> map[i][j] != 'C')
            {
                write(1,"Error :invalid character", 24);
                exit(0);
            }
            j++;
        }
        i++;
    }
}

void check_error(int player , int door , int collectibles)
{
    if (player < 1)
    {
        write(1,"Error :missing player",21);
        exit(0);
    }
    if (door < 1)
    {
        write(1,"Error :missing door",19);
        exit(0);
    }
    if (collectibles < 1)
    {
        write(1,"Error :add collectibles",23);
        exit(0);
    }
    if (player > 1)
    {
        write(1,"Error :multiple players", 23);
        exit(0);
    }
    if (door > 1)
    {
        write(1,"Error :multiple doors" ,21);
        exit(0);
    }
}
void check_characters_num(t_mlx_data *inf)
{
    int i;
    int j;
    int player;
    int  door;
    int collectibles;

    i = 0;
    player = 0;
    door = 0;
    collectibles = 0;
    while (inf -> map[i])
    {
        j = 0;
        while (inf -> map[i][j])
        {
            if (inf -> map[i][j] == 'P')
                player++;
            if (inf -> map[i][j] == 'E')
                door++;
            if (inf -> map[i][j] == 'C')
                collectibles = 1;
            j++;
        }
        i++;
    }
        check_error(player, door , collectibles);
}
