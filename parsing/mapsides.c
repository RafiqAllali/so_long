#include "../so_long.h"

void check_map_sides2(t_mlx_data *inf)
{
    int i = 0;

    while (inf -> map[i])
    {
            if (inf ->map[i][0] != '1' || inf -> map[i][inf -> collums] != '1')
            {
                write(1,"Error :invalid map",18);
                exit(0);
            }
        i++;
    }
}
void check_map_sides(t_mlx_data *inf)
{
    int j = 0;

        while (inf -> map[0][j])
        {
            if (inf ->map[0][j] != '1' || inf -> map[inf ->rows][j] != '1')
            {
                write(1,"Error :invalid map",18);
                exit(0);
            }
            j++;
        }
    check_map_sides2(inf);
}