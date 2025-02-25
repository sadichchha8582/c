#include <stdio.h>

void findSecondAndThirdLargest(int arr[], int size, int *secondLargest, int *thirdLargest) {
    if (size < 3) {
        printf("Array should have at least 3 elements.\n");
        return;
    }
    
    int first = arr[0], second = -2147483648, third = -2147483648;
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] < first) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third && arr[i] < second) {
            third = arr[i];
        }
    }
    
    *secondLargest = second;
    *thirdLargest = third;
}

int main() {
    int arr[] = {12, 45, 1, -1, 90, 45, 60};
    int size = sizeof(arr) / sizeof(arr[0]);
    int secondLargest, thirdLargest;
    
    findSecondAndThirdLargest(arr, size, &secondLargest, &thirdLargest);
    
    if (size >= 3) {
        printf("Second Largest: %d\n", secondLargest);
        printf("Third Largest: %d\n", thirdLargest);
    }
    
    return 0;
}
