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
    struct Element elements1_bubble[n];
    struct Element elements1_selection[n];
    struct Element elements2_bubble[n];
    struct Element elements2_selection[n];
  
    for (int i = 0; i < n; i++) {
        elements1_bubble[i].value = array1[i];
        elements1_bubble[i].swaps = 0;

        elements1_selection[i].value = array1[i];
        elements1_selection[i].swaps = 0;

        elements2_bubble[i].value = array2[i];
        elements2_bubble[i].swaps = 0;

        elements2_selection[i].value = array2[i];
        elements2_selection[i].swaps = 0;
    }
    bubbleSort(elements1_bubble, n);
    printf("array1 Bubble Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d \n", elements1_bubble[i].value, elements1_bubble[i].swaps);
    }
    int totalSwaps1_bubble = 0;
    for (int i = 0; i < n; i++) {
        totalSwaps1_bubble += elements1_bubble[i].swaps;
    }
    printf("%d\n\n", totalSwaps1_bubble/2);
    bubbleSort(elements2_bubble, n);
    printf("array2 Bubble Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d \n", elements2_bubble[i].value, elements2_bubble[i].swaps);
    }
    int totalSwaps2_bubble = 0;
    for (int i = 0; i < n; i++) {
        totalSwaps2_bubble += elements2_bubble[i].swaps;
    }
    printf("%d\n\n", totalSwaps2_bubble/2);
    selectionSort(elements1_selection, n);
    printf("array1 Selection Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d \n", elements1_selection[i].value, elements1_selection[i].swaps);
    }
    int totalSwaps1_selection = n - 1; 
    printf("%d\n\n", totalSwaps1_selection);

    selectionSort(elements2_selection, n);
    printf("array2 Selection Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d \n", elements2_selection[i].value, elements2_selection[i].swaps);
    }
    int totalSwaps2_selection = n - 1;
    printf("%d\n\n", totalSwaps2_selection/2);
  //prints everything out

    return 0;
}
