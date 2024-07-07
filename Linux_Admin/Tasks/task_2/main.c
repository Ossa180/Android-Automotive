#include <stdio.h>

// Function to perform binary search
int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;
        
        // If target is greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;
        
        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }
    
    // Target is not present in the array
    return -1;
}

int main() {
    // Declare and initialize the array
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Element to search
    int target = 10;
    
    // Call binary search function
    int result = binary_search(arr, size, target);
    
    // Print the output
    if (result != -1)
        printf("Element %d is present at index %d\n", target, result);
    else
        printf("Element %d is not present in the array\n", target);
    
    return 0;
}

