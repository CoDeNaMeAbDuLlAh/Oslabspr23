#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 100

int arr[SIZE];
float array[SIZE];
int temp[SIZE];

typedef struct {
    int start;
    int end;
} thread_args_t;

//==================================================================================//

		void merge(int start, int mid, int end) {
			int i = start, j = mid + 1, k = start;
			while (i <= mid && j <= end) {
				if (arr[i] <= arr[j]) {
					temp[k++] = arr[i++];
				} else {
					temp[k++] = arr[j++];
				}
			}
			while (i <= mid) {
				temp[k++] = arr[i++];
			}
			while (j <= end) {
				temp[k++] = arr[j++];
			}
			for (i = start; i <= end; i++) {
				arr[i] = temp[i];
			}
		}
//==================================================================================//

			void* merge_sort(void* args) {
				thread_args_t* thread_args = (thread_args_t*) args;
				int start = thread_args->start;
				int end = thread_args->end;

				if (start >= end) {
					return NULL;
				}

				int mid = (start + end) / 2;

				pthread_t left_thread, right_thread;
				thread_args_t left_args = {start, mid};
				thread_args_t right_args = {mid + 1, end};

				pthread_create(&left_thread, NULL, merge_sort, &left_args);
				pthread_create(&right_thread, NULL, merge_sort, &right_args);

				pthread_join(left_thread, NULL);
				pthread_join(right_thread, NULL);

				merge(start, mid, end);

				return NULL;
			}
//==================================================================================//


int main() {
    int n;
    int n2 ; 
    printf("SPECIFY number of elements you want to enter ");
    scanf("%d", &n);
    
    printf("ARE THEY INTEGER OR FLOATING POINT");
    scanf("%d", &n2);
   
   
   if (n2==1) {
			printf("Enter %d elemetnts \n",n);
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		thread_args_t args = {0, n-1};
		merge_sort(&args);

		printf("21k-4783-------------ABDULLAH---------------------------------------- \n");
		 printf("\n\n");
		printf("Sorted array: ");
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	   printf("21k-4783-------------ABDULLAH---------------------------------------- ");
		   
   }else{
	         printf("Enter %d elemetnts \n",n);
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &array[i]);
		}

		thread_args_t args = {0, n-1};
		merge_sort(&args);

		printf("21k-4783-------------ABDULLAH---------------------------------------- \n");
		 printf("\n\n");
		printf("Sorted array: ");
		for (int i = 0; i < n; i++) {
			printf("%d ", array[i]);
		}
		printf("\n\n\n");
	   printf("21k-4783-------------ABDULLAH---------------------------------------- ");
	   
	
	
	
    }
   
   
   
   
   
   
    return 0;
}
