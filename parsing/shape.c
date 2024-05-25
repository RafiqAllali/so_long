#include "../so_long.h"

void rows_collums(t_mlx_data *inf)
{
    inf ->rows = 0;
        while (inf->map[inf -> rows])
    {
        inf->rows++;
    }
    inf ->rows--;
    inf -> collums = 0;
    
    while (inf -> map[0][inf -> collums] != '\0')
    {
        inf -> collums++;
    }
    inf -> collums--;

}
void check_shape(t_mlx_data *inf)
{
    int i = 0;
    int j = 0;

    while (inf -> map[i])
    {
        j = 0;
        while (inf -> map[i][j])
        {
            j++;
        }
        if (inf -> collums != j - 1 )
            {
                write(1,"Error in map shape", 19);
                exit(0);
            }
        i++;
    }

}
