#include<stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};  
    int n = 5, i, max;

    printf("Array elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    max = arr[0]; 
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("\nLargest element: %d\n", max);

    return 0;
}
