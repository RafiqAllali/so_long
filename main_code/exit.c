#include "../so_long.h"

int 	check_collectibles(t_mlx_data *inf)
{
int i = 0;
int j = 0;

while (inf -> map[i])
{

    j = 0;
     while(inf -> map[i][j])
        {
            if (inf -> map[i][j] == 'C')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
void check_door_place1(t_mlx_data *inf)
{
    int i = 0;
    int j = 0;
    while (inf -> map[i])
    {
        j = 0;
        while (inf -> map[i][j])
        {
            if (inf -> map[i][j] == 'E')
            {
                inf -> doorx = i;
                inf -> doory = j;
            }
            j++;
        }
        i++;
    }
    check_player_place(inf);
        inf -> map[inf -> doorx][inf -> doory] = '0';
    if (inf -> doorx == inf ->x && inf -> doory == inf -> y)
	 {
	 	exit(0);
	}
}