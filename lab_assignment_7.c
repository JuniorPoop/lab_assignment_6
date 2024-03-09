#include <stdio.h>

struct Element {
    int value;
    int swaps;
};

void bubbleSort(struct Element arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].value > arr[j + 1].value) {
                struct Element temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                arr[j].swaps++;
                arr[j + 1].swaps++;
            }
        }
    }
}
//bubble sort
void selectionSort(struct Element arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].value < arr[min].value) {
                min = j;
            }
        }
        struct Element temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        arr[i].swaps++;
        arr[min].swaps++;
    }
}
//selection sort
int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = sizeof(array1) / sizeof(array1[0]);
    struct Element bubble1[n];
    struct Element selection1[n];
    struct Element bubble2[n];
    struct Element selection2[n];

    for (int i = 0; i < n; i++) {
        bubble1[i].value = array1[i];
        bubble1[i].swaps = 0;

        selection1[i].value = array1[i];
        selection1[i].swaps = 0;

        bubble2[i].value = array2[i];
        bubble2[i].swaps = 0;

        selection2[i].value = array2[i];
        selection2[i].swaps = 0;
    }
    bubbleSort(bubble1, n);
    printf("array1 Bubble Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d \n", bubble1[i].value, bubble1[i].swaps);
    }
    int totalSwaps1 = 0;
    for (int i = 0; i < n; i++) {
        totalSwaps1 += bubble1[i].swaps;
    }
    printf("%d\n\n", totalSwaps1/2);
    bubbleSort(bubble2, n);
    printf("array2 Bubble Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d \n", bubble2[i].value, bubble2[i].swaps);
    }
    int totalSwaps2 = 0;
    for (int i = 0; i < n; i++) {
        totalSwaps2 += bubble2[i].swaps;
    }
    printf("%d\n\n", totalSwaps2/2);
    selectionSort(selection1, n);
    printf("array1 Selection Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d \n", selection1[i].value, selection1[i].swaps);
    }
    int totalSwaps1_selection = n - 1; 
    printf("%d\n\n", totalSwaps1_selection);

    selectionSort(selection2, n);
    printf("array2 Selection Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d \n", selection2[i].value, selection2[i].swaps);
    }
    int totalSwaps2_selection = n - 1;
    printf("%d\n\n", totalSwaps2_selection/2);
  //prints everything out

    return 0;
}

