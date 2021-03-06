#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 100000

void merge(int *a, int *w, int n){

    int i = 0, j = n/2, count = 0;

    while (i < n/2 && j < n){
        if (a[i] <= a[j]){
            w[count] = a[i];
            i++;
        } else {
            w[count] = a[j];
            j++;
        }
        count++;
    }
    if(i >= n/2){
        while (j < n){
            w[count] = a[j];
            j++;
            count++;
        }
    }
    if(j >= n){
        while (i < n/2){
            w[count] = a[i];
            i++;
            count++;
        }
    }
}

void merge_sort(int *a, int *w, int n){

    int i;

    if (n < 2){
        return;
    } else {
        merge_sort(a, w, n/2);
        merge_sort(a + (n/2), w, n - (n/2));

        merge(a, w, n);

        for (i=0; i < n; i++){
            a[i] = w[i];
        }

        return;
    }
}


int main(void){

    int i, num_items = 0;
    int num_list[ARRAY_MAX];
    int sorted_list[ARRAY_MAX];

    while(num_items < ARRAY_MAX && 1 == scanf("%d", &num_list[num_items])){
        num_items++;
    }

    merge_sort(num_list, sorted_list, num_items);

    for(i = 0; i < num_items; i++){
        printf("%d\n", sorted_list[i]);
               
    }
    return EXIT_SUCCESS;
    
}

