#include <stdlib.h>
#include <stdio.h>

#define n_sector 3

/* Fill in the functions and define helper functions if you need to */

float*** create_sector_times(unsigned int* n_drivers, unsigned int* n_laps){
    return NULL;
}


unsigned int** create_positions(unsigned int* p_drivers, unsigned int* n_races){
    return NULL;
}


float** calculate_lap_times(float*** sector_times, unsigned int n_drivers, unsigned int n_laps){
    return NULL;
}


unsigned int find_fastest_lap(float** lap_times, unsigned int n_drivers, unsigned int n_laps){
    return 0;
}


unsigned int find_driver_fastest_lap(float lap_times_of_driver[][3], unsigned int n_laps){
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


unsigned int find_season_ranking(int* total_points, unsigned int p_drivers, unsigned int id){
    return 0;
}
