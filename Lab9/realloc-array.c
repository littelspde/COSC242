#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

static void array_print(int *a, int n){
    int i;

    for (i = 0; i < n; i++){
        printf("%d\n", a[i]);
    }
}

void array_sort(int* a, int n){

    int i, j;
    int min, temp;

    for(i=0; i<n; i++){

        min = i;
        /* Finding the smallest element to the right of element
           currently being sorted */
        for(j=i+1; j<n; j++){
            if (a[j] < a[min]){
                min = j;
            }
        }
        /* Swapping element currently being sorted and the smallest element */
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }    
}



int main(void){
    
    int capacity = 2;
    int itemcount = 0;
    int item;
    int *my_array = emalloc(capacity * sizeof my_array[0]);


    while (1 == scanf("%d", &item)){
        if (itemcount == capacity){
            capacity += capacity;
            my_array = erealloc(my_array, capacity * sizeof my_array[0]);
        }
        my_array[itemcount++] = item;
    }

    array_sort(my_array, itemcount);
    array_print(my_array, itemcount);
    free(my_array);

    return EXIT_SUCCESS;
}
