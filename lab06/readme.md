
PROD.C
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <time.h>

#define SHM_SIZE 2<<17

int main() {
    // generate 2^18 random numbers
    srand(time(NULL));
    int numbers = (int)malloc(SHM_SIZE);
    for (int i = 0; i < SHM_SIZE/sizeof(int); i++) {
        numbers[i] = rand();
    }

    // create shared memory segment
    key_t key = ftok("shared_memory", 65);
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // attach shared memory segment
    int shm_ptr = (int)shmat(shmid, NULL, 0);
    if (shm_ptr == (int*)-1) {
        perror("shmat");
        exit(1);
    }

    // copy random numbers to shared memory
    for (int i = 0; i < SHM_SIZE/sizeof(int); i++) {
        shm_ptr[i] = numbers[i];
    }

    // detach shared memory segment
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        exit(1);
    }

    // start cons1 and cons2 programs
    pid_t pid1, pid2;
    pid1 = fork();
    if (pid1 < 0) {
        perror("fork");
        exit(1);
    } else if (pid1 == 0) {
        execlp("./cons1", "./cons1", NULL);
    }

    pid2 = fork();
    if (pid2 < 0) {
        perror("fork");
        exit(1);
    } else if (pid2 == 0) {
        execlp("./cons2", "./cons2", NULL);
    }

    // wait for cons1 and cons2 to finish
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    // delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    free(numbers);
    return 0;
}
------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE (1 << 18)

int main() {
    // Create a key for the shared memory
    key_t key = ftok("prod.c", 1);
    
    // Get the shared memory ID
    int shm_id = shmget(key, SHM_SIZE, 0666);
    if (shm_id == -1) {
        perror("shmget failed");
        exit(1);
    }
    
    // Attach to the shared memory
    int* shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (int*)-1) {
        perror("shmat failed");
        exit(1);
    }
    
    // Print the numbers assigned to this consumer
    printf("Cons1: ");
    for (int i = 0; i < SHM_SIZE/2; i++) {
        printf("%d ", shm_ptr[i]);
    }
    printf("\n");
    
    // Detach from the shared memory
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt failed");
        exit(1);
    }
    
    return 0;
}
-------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE (1 << 18)

int main() {
    // Create a key for the shared memory
    key_t key = ftok("prod.c", 1);
    
    // Get the shared memory ID
    int shm_id = shmget(key, SHM_SIZE, 0666);
    if (shm_id == -1) {
        perror("shmget failed");
        exit(1);
    }
    
    // Attach to the shared memory
    int* shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (int*)-1) {
        perror("shmat failed");
        exit(1);
    }
    
    // Print the numbers assigned to this consumer
    printf("Cons2: ");
    for (int i = SHM_SIZE/2; i < SHM_SIZE; i++) {
        printf("%d ", shm_ptr[i]);
    }
    printf("\n");
    
    // Detach from the shared memory
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt failed");
        exit(1);
    }
    
    return 0;
}
-----------------------------------------------
CONS1.C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE (1 << 18)

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    // Create a key for the shared memory
    key_t key = ftok("prod.c", 1);
    
    // Get the shared memory ID
    int shm_id = shmget(key, SHM_SIZE, 0666);
    if (shm_id == -1) {
        perror("shmget failed");
        exit(1);
    }
    
    // Attach to the shared memory
    int* shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (int*)-1) {
        perror("shmat failed");
        exit(1);
    }

    // Sort the numbers
    mergeSort(shm_ptr, 0, SHM_SIZE/2 - 1);
    
    // Detach from the shared memory
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt failed");
        exit(1);
    }
    
    return 0;
}

---------------------------------------------------------------------------

CONS2.C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE (1 << 18)

void merge(int* arr, int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
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
}

void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    // Create a key for the shared memory
    key_t key = ftok("prod.c", 1);
    
    // Get the shared memory ID
    int shm_id = shmget(key, SHM_SIZE, 0666);
    if (shm_id == -1) {
        perror("shmget failed");
        exit(1);
    }
    
    // Attach to the shared memory
    int* shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (int*)-1) {
        perror("shmat failed");
        exit(1);
    }
    
    // Sort the numbers received using merge sort
    mergeSort(shm_ptr, SHM_SIZE/2, SHM_SIZE-1);
    
    // Print the sorted numbers
    printf("Cons2: ");
    for (int i = SHM_SIZE/2; i < SHM_SIZE; i++) {
        printf("%d ", shm_ptr[i]);
    }
    printf("\n");
    
    // Detach from the shared memory
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt failed");
        exit(1);
    }
    
    return 0;
}

