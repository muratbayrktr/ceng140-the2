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


float** calculate_lap_times(float*** sector_times, unsigned int n_drivers, unsigned int n_laps){
    float **lap_times = (float **) malloc(sizeof(float *)*(n_drivers));
    unsigned int i, j, k;
    for (i = 0; i < n_drivers; i++) *(lap_times+i) = (float *) malloc(sizeof(float)*(n_laps));

    for (i = 0; i < n_drivers; i++)
    {
        for (j = 0; j < n_laps; j ++)
        {
            float sum = 0;
            for (k = 0; k < 3; k++)
            {
                sum += sector_times[i][j][k];
            }
            lap_times[i][j] = sum;
        }
    }
    return lap_times;
}


unsigned int find_fastest_lap(float** lap_times, unsigned int n_drivers, unsigned int n_laps){
    unsigned int i = 0, j = 0;
    float fastest_lap = lap_times[i][j];
    unsigned int id = 0;
    for (i = 0; i < n_drivers; i++)
    {
        for (j = 0; j < n_laps; j ++)
        {
            float lap = lap_times[i][j];
            if (lap < fastest_lap) {
                fastest_lap = lap;
                id = i;
            }
        }
    }
    return id;
}


unsigned int find_driver_fastest_lap(float **sector_times_of_driver, unsigned int n_laps){
    unsigned int i = 0, j = 0;
    float fastest_lap = { sector_times_of_driver[i][j] + 
                        sector_times_of_driver[i][j+1] + 
                        sector_times_of_driver[i][j+2] }; 
    unsigned int lap_id = i;
    for (i = 0; i < n_laps; i++)
    {
        float lap = 0;
        for (j = 0; j < 3; j ++)
        {
            lap += sector_times_of_driver[i][j];
        }
        if (lap < fastest_lap) {
            fastest_lap = lap;
            lap_id = i;
        }
    }
    return lap_id;
}


float* selection_sort(float* arr, unsigned int len, char ord){
    float *sorted = (float *) malloc(sizeof(float)*len);
    unsigned int i = 0;
    float *current_ult;
    float *current_item;
    float temp;
    float *end = arr + len - 1; /* element after the last index */
    while(i < len)
    {
        /* initialize */
        current_ult = current_item = arr + i;
        /* Find the minimum/maximum in the unsorted list */
        while (current_item <= end)
        {
            switch (ord)
            {
                case 'A':
                {
                    if (*current_item < *current_ult) current_ult = current_item;
                    break;
                }
                        
                case 'D':
                {
                    if (*current_item > *current_ult) current_ult = current_item;
                    break;
                }
            }
            current_item++;
        }
        /* swap & add to sorted list */
        temp = *(arr + i);
        arr[i] = *current_ult;
        *current_ult = temp;
        sorted[i] = arr[i];
        i++;
    }
    return sorted;
}

/*
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