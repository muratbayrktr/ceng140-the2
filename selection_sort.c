#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *selection_sort(float* arr, unsigned int len, char ord);
    float arr[] = {3.0, 2.0, 7.0, 9.0, 4.0};
    /* 'A' = Ascending order || 'D' = Descending order */
    float *sorted_arr;

    int j;

    sorted_arr = selection_sort(arr, 5, 'A');

    for (j = 0; j < 5; j++)
    {
        printf("%.2f\n", sorted_arr[j]);
    }

    return 0;
}

float* selection_sort(float* arr, unsigned int len, char ord){
    float *sorted = (float *) malloc(sizeof(float)*len);
    unsigned int i = 0, j = 0;
    float *current_ult;
    float *current_item;
    float temp;
    float *end = arr + len - 1; /* element after the last index */
    while(i < len)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%.2f\n", arr[j]);
        }
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
        printf("ultimate found: %.2f\n",*current_ult);
        printf("swapped %.2f with %.2f\n\n",arr[i], *current_ult);
        /* swap & add to sorted list */
        temp = *(arr + i);
        arr[i] = *current_ult;
        *current_ult = temp;
        sorted[i] = arr[i];
        i++;
    }
    return sorted;
}


