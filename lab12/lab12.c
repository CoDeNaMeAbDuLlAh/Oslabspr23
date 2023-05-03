//important libraries for input output ,
//omp.h header for implementing openmp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>


//merge sort algorithm
void merge(int* arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        #pragma omp parallel shared(arr)
        {
            #pragma omp sections
            {
                #pragma omp section
                {
                    merge_sort(arr, l, m);
                }
                #pragma omp section
                {
                    merge_sort(arr, m + 1, r);
                }
            }
        }
        merge(arr, l, m, r);
    }
}

int main() {
    // constant number of random numbers 
    const int n = 1 << 18;
    int* arr = (int*)malloc(n * sizeof(int));
    srand(time(NULL));

    // Generate random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
// creating 20 threads 
    double start_time = omp_get_wtime(); 

    merge_sort(arr, 0, n - 1);

    double end_time = omp_get_wtime();

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Execution time: %f seconds\n", end_time - start_time);

    free(arr);

    return 0;
}
