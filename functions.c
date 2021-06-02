#include <stdlib.h>
#include <stdio.h>

#define n_sector 3

/* Fill in the functions and define helper functions if you need to */

float*** create_sector_times(unsigned int* n_drivers, unsigned int* n_laps){
    int i, j, k;
    float ***sector_times;
    scanf("%u %u", n_drivers, n_laps);
    sector_times = (float ***) malloc(sizeof(float **)*(*n_drivers));
    for (i = 0; i < *n_drivers; i++)
    {
        float temp;
        *(sector_times + i) = (float **) malloc(sizeof(float *)*(*n_laps));
        for (j = 0; j < *n_laps; j ++)
        {
            *(*(sector_times + i) + j) = (float *) malloc(sizeof(float)*3);
            for (k = 0; k < 3; k++)
            {
                scanf(" %f",&temp);
                *(*(*(sector_times + i) + j) + k) = temp;
                /* printf("%f ", drivers[i][j][k]); */
            }
            /* printf("\n"); */
        }
    }

    return sector_times;
}


unsigned int** create_positions(unsigned int* p_drivers, unsigned int* n_races){
    unsigned int **positions;
    int i,j;
    scanf("%u %u", p_drivers, n_races);
    positions = (unsigned int **) malloc(sizeof(unsigned int **)*(*p_drivers));
    for (i = 0; i < *p_drivers; i++)
    {
        *(positions + i) = (unsigned int *) malloc(sizeof(unsigned int)*(*n_races));
        for (j = 0; j < *n_races; j++)
        {
            unsigned int temp;
            scanf("%u ",&temp);
            *(*(positions+i)+j) = temp;
        }
    }
    return positions;
}

/*
float** calculate_lap_times(float*** sector_times, unsigned int n_drivers, unsigned int n_laps){
    return NULL;
}


unsigned int find_fastest_lap(float** lap_times, unsigned int n_drivers, unsigned int n_laps){
    return 0;
}


unsigned int find_driver_fastest_lap(float **sector_times_of_driver, unsigned int n_laps){
    return 0;
}


float* selection_sort(float* arr, unsigned int len, char ord){
    return NULL;
}


unsigned int* find_finishing_positions(float** lap_times, unsigned int n_drivers, unsigned int n_laps){
    return NULL;
}


float* find_time_diff(float** lap_times, unsigned int n_drivers, unsigned int n_laps, unsigned int driver1,
    unsigned int driver2){
    return NULL;
}


unsigned int* calculate_total_points(unsigned int** positions, unsigned int p_drivers, unsigned int n_races){
    return NULL;
}


unsigned int find_season_ranking(unsigned int* total_points, unsigned int p_drivers, unsigned int id){
    return 0;
}
*/