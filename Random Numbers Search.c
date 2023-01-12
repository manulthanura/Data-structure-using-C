#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(void)
{

    // Allocates memory for the array using malloc function
    int *array = malloc (sizeof(int)*2000000);
    for(int i=0;i<2000000;i++)
    {
        array[i]=rand();
    }
    // Enter the value to search
    int value,found=0;
    printf("Enter the value to search : ");
    scanf("%i",&value);

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    while(value!=0)
    {
        for(int i=0;i<2000000;i++)
        {
            // checked array content entered value
            if(array[i]==value)
            {
                found=1;
                break;
            }
        }
        if(found==1)
        {
            printf("Searched data found! \n");
            break;
        }else
        {
            printf("Searched data not found! \n");
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%fcpu_time_used : ",cpu_time_used);
    // free memory
    free(array);
    return 0;
}
