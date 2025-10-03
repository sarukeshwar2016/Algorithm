#include <stdio.h>
#include <stdlib.h>

void sum_of_subsets(int arr[], int index, int current_sum, int target, int subset[], int subset_size) {
    // If current sum equals target, print the subset
    if (current_sum == target) {
        printf("Subset: ");
        for (int i = 0; i < subset_size; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    // If we reach the end of the array or exceed the target sum, return
    if (index == 0 || current_sum > target) {
        return;
    }

    // Include the current element in the subset
    subset[subset_size] = arr[index];
    sum_of_subsets(arr, index + 1, current_sum + arr[index], target, subset, subset_size + 1);

    // Exclude the current element from the subset and move to the next index
    sum_of_subsets(arr, index + 1, current_sum, target, subset, subset_size);
}

int main() {
    int n, target_sum;

    // Prompt user for array size and elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Prompt user for the target sum
    printf("Enter the target sum: ");
    scanf("%d", &target_sum);

    // Validate inputs
    if (n <= 0) {
        printf("Array cannot be empty.\n");
        free(arr);
        return 0;
    }

    if (target_sum <= 0) {
        printf("Target sum must be a positive integer.\n");
        free(arr);
        return 0;
    }

    // Initialize an array to hold the current subset
    int *subset = (int *)malloc(n * sizeof(int));

    // Call the sum_of_subsets function to start finding subsets
    printf("\nFinding subsets of the array that sum to %d...\n", target_sum);
    sum_of_subsets(arr, 0, 0, target_sum, subset, 0);

    // Free dynamically allocated memory
    free(arr);
    free(subset);

    return 0;
}
