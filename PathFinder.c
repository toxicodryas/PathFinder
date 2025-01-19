#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to apply each operation
int apply_operation(int value, const char* operation) {
    int number;
    char op = operation[0];  // The operator (+, -, *, /)
    sscanf(operation + 1, "%d", &number);  // Get the number after the operator

    switch (op) {
        case '+': return value + number;
        case '-': return value - number;
        case '*': return value * number;
        case '/': return value / number;  // Assuming non-zero division
        default: return value;  // Should never happen if input is valid
    }
}

// Function to generate permutations of operations
void permute(char** operations, int num_operations, int* used, int* path, int depth, int current_value, int* max_value, int* best_path, int* best_path_length) {
    // If we've used all operations, evaluate the result
    if (depth == num_operations) {
        if (current_value > *max_value) {
            *max_value = current_value;
            memcpy(best_path, path, num_operations * sizeof(int));
            *best_path_length = num_operations;
        }
        return;
    }

    // Try each operation that has not been used yet
    for (int i = 0; i < num_operations; ++i) {
        if (!used[i]) {
            // Mark this operation as used
            used[i] = 1;
            path[depth] = i;

            // Apply the operation and recurse
            int new_value = apply_operation(current_value, operations[i]);
            permute(operations, num_operations, used, path, depth + 1, new_value, max_value, best_path, best_path_length);

            // Backtrack and mark the operation as unused
            used[i] = 0;
        }
    }
}

int main() {
    // Input the initial starting value
    int start_value;
    printf("Enter the initial starting value: ");
    scanf("%d", &start_value);

    // Input the number of operations
    int num_operations;
    printf("Enter the number of operations: ");
    scanf("%d", &num_operations);

    // Dynamically allocate memory for operations
    char** operations = (char**)malloc(num_operations * sizeof(char*));
    for (int i = 0; i < num_operations; ++i) {
        operations[i] = (char*)malloc(10 * sizeof(char));  // Assuming each operation string is not more than 10 characters
        printf("Enter operation %d (e.g., +5, -50, *10): ", i + 1);
        scanf("%s", operations[i]);
    }

    // Track the best path
    int max_value = start_value;
    int best_path[100]; // Assuming no more than 100 operations
    int path[100];
    int best_path_length = 0;

    // Array to track which operations have been used
    int used[100] = {0};  // Assuming no more than 100 operations

    // Start the recursive search for the best path
    permute(operations, num_operations, used, path, 0, start_value, &max_value, best_path, &best_path_length);
    
    // Output the best path and its resulting value
    printf("Best path results in value: %d\n", max_value);
    printf("Operations to reach this value:\n");
    for (int i = 0; i < best_path_length; ++i) {
        printf("%s ", operations[best_path[i]]);
    }
    printf("\n");

    // Free dynamically allocated memory
    for (int i = 0; i < num_operations; ++i) {
        free(operations[i]);
    }
    free(operations);
    
    return 0;
}

