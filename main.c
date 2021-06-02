#include <stdio.h>
#include "functions.h"

/*
You will not submit this file, just use for testing your code.
All your implementations should be in functions.c
*/

/*
To compile your code, use "make main"
Then "./main" to run.
If you want to compile again, you need to delete the previous executable.
You may do this by "make clean" or simply "rm main"
*/

int main(){
    /*
    ;
    unsigned int fastest_lap, **positions;
    float **laptimes;
    */
    
    int i, j, k;
    /* TESTING FUNCTIONS */
    {
        /* 1ST FUNCTION */
        float ***sector_times;
        unsigned int n_drivers, n_laps;
        sector_times = create_sector_times(&n_drivers, &n_laps);
        printf("----1st Function----\n");
        printf("%u %u\n", n_drivers, n_laps);
        for (i = 0; i < n_drivers; i++)
        {

            for (j = 0; j < n_laps; j ++)
            {

                for (k = 0; k < 3; k++)
                {
                    printf("%.2f ", sector_times[i][j][k]); 
                }
                printf("\n");
            }
        }
    }
    {
        /* 2ND FUNCTION */
        unsigned int **positions;
        unsigned int p_drivers, n_races;
        printf("----2nd Function----\n");
        positions = create_positions(&p_drivers,&n_races);
        printf("%u %u\n", p_drivers, n_races);
        for (i = 0; i < p_drivers; i++)
        {
            for (j = 0; j < n_races; j ++)
            {
                printf("%u ", positions[i][j]);
            }
            printf("\n");
        }
    }

    /*
    lap_times = calculate_lap_times();
    fastest_lap = find_fastest_lap(lap_times, ); 
    printf("Printing fastest lap to check the answer: %d\n", fastest_lap);*/

    return 0;
}
