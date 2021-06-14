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
    float ***sector_times, **lap_times, *time_diff_arr;
    unsigned int n_drivers, n_laps;
    unsigned int **positions;
    unsigned int fastest_lap;
    unsigned int p_drivers, n_races;
    unsigned int *finishing_positions;
    unsigned int *total_points;
    int i, j, k;
    /* TESTING FUNCTIONS */
    {
        /* 1ST FUNCTION */
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
        printf("\n");
    }
    {
        /* 2ND FUNCTION */
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
        printf("\n");
    }
    {
        /* 3RD FUNCTION */
        unsigned int i, j;
        printf("----3rd Function----\n");
        lap_times = calculate_lap_times(sector_times, n_drivers, n_laps);
        for (i = 0; i < n_drivers; i++)
        {
            float sum = 0;
            for (j = 0; j < n_laps; j ++)
            {
                sum += lap_times[i][j];
                printf("Driver %u: Lap %u: %f\n", i, j, lap_times[i][j]);
            }
            printf("Total: %f\n",sum);
            printf("\n");
            
        }
        printf("\n");
    }
    {
        /* 4TH FUNCTION */
        printf("----4th Function----\n");
        fastest_lap = find_fastest_lap(lap_times, n_drivers, n_laps); 
        printf("ID of the driver that has the fastest lap: %u\n", fastest_lap);
        printf("\n");
    }
    {
        /* 5TH FUNCTION */
        unsigned int driver_fastest_lap;
        printf("----5th Function----\n");
        for (i = 0; i < n_drivers; i++)
        {
            driver_fastest_lap = find_driver_fastest_lap(sector_times[i], n_laps);
            printf("Fastest lap of the driver %u: lap %u\n",i, driver_fastest_lap);
        }
        printf("\n");
    }
    {
        /* 6TH FUNCTION */
        float arr[] = {3.0, 2.0, 7.0, 9.0, 4.0};
        /* 'A' = Ascending order || 'D' = Descending order */
        float *sorted_arr;

        int j;
        printf("----6th Function----\n");
        
        sorted_arr = selection_sort(arr, 5, 'A');

        for (j = 0; j < 5; j++)
        {
            printf("%.1f\n", sorted_arr[j]);
        }
        printf("\n");
    }
    {
        /* 7TH FUNCTION */
        unsigned int i;  
        printf("----7th Function----\n");
        finishing_positions = find_finishing_positions(lap_times, n_drivers, n_laps);
        for (i = 0; i < n_drivers; i++)
        {
            printf("%u ",finishing_positions[i]);
        }
        printf("\n\n");
    }
    {
        /* 8TH FUNCTION */
        unsigned int i;  
        printf("----8th Function----\n");
        time_diff_arr = find_time_diff(lap_times,n_drivers,n_laps,0,1);
        for (i = 0; i < n_laps; i++)
        {
            printf("Cumulative Time diff: %f\n", time_diff_arr[i]);
        }
        printf("\n\n");
        
    }
    {
        /* 9TH FUNCTION */
        unsigned int i = 0;
        printf("----9th Function----\n");
        total_points = calculate_total_points(positions,p_drivers,n_races);
        for (i = 0; i < p_drivers; i++)
        {
            printf("Total points of driver %u is %u\n",i,total_points[i]);
        }

        printf("\n\n");
    }
    {
        /* 10TH FUNCTION */
        unsigned int rank = find_season_ranking(total_points,p_drivers,1);
        printf("----10th Function----\n");
        printf("Season rank of the driver %u is %u\n",1,rank);
        printf("\n\n");
    }    
    return 0;
}
