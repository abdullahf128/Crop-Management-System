/* Purpose: Lab 4: Find The Maximum Number of Boxes Each Truck Can Hold
 * Author: Abdullah Faisal
 * Date: Oct 9th 2023
 * References: 
 *      Lab Instructions
 *      Binary Search Function modeled from examples in: https://www.geeksforgeeks.org/binary-search/
 *      Quick Sort Function modeled from examples in: https://www.geeksforgeeks.org/quick-sort/
 */

#include <stdio.h>
#include <stdlib.h>

// Swap two double values
void swap(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

// Finds the new pivot position for quick_sort
int pivot_position(double arr[], int low, int high) {
    double pivot = arr[high];  // Choose the rightmost element as the pivot
    int i = (low - 1);        // Initialize the index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment the index of the smaller element
            swap(&arr[i], &arr[j]);
        }
    }

    // Swap the pivot element with the element at the (i+1) position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Recursive quick_sort function
void quick_sort(double arr[], int low, int high) {
    if (low < high) {
        // Partition the array into two subarrays and get the pivot index
        int pivot_index = pivot_position(arr, low, high);

        // Recursively sort the subarrays
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

// Binary search to find the closest number <= target in sorted array arr
double binary_search(double arr[], int size, double target, int* index) {
    int left = 0;
    int right = size - 1;
    double closest = arr[0]; // Initialize closest to the first element
    *index = 0;

    while (left <= right) {
        int mid_point = left + (right - left) / 2;

        if (arr[mid_point] == target) {
            *index = mid_point; // Found an exact match
            return arr[mid_point];
        } else if (arr[mid_point] < target) {
            closest = arr[mid_point]; // Update closest
            *index = mid_point;
            left = mid_point + 1;
        } else {
            right = mid_point - 1;
        }
    }

    return closest;
}

int main() {
    int n; // Number of weights
    scanf("%d", &n);

    double weights[n]; // To store the array of weights

    // Read the array of weights
    for (int i = 0; i < n; i++) {
        scanf("%lf", &weights[i]);
    }

    // Sort the weights in ascending order
    quick_sort(weights, 0, n - 1);
    
    double cumulative_sum = 0;
    double cumulative_weights[n];

    // Calculate cumulative weights and store them in a new array
    for (int i = 0; i < n; i++) {
        cumulative_sum += weights[i];
        cumulative_weights[i] = cumulative_sum;
    }
    
    // Process the rest of the numbers in the input
    double value;
    while (scanf("%lf", &value) == 1) {

        // Find the closest number in cumulative_weights <= value using binary search
        int index;
        binary_search(cumulative_weights, n, value, &index);
        printf("%d\n", index + 1);
    }

    return 0;
}
