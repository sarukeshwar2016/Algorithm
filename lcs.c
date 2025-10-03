#include <stdio.h>
#include <string.h>

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char X[100], Y[100]; // Arrays to store the two strings
    int m, n;

    // Take input for the two strings
    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    // Find the lengths of the two strings
    m = strlen(X);
    n = strlen(Y);

    // Declare the DP table to store the length of LCS
    int L[m + 1][n + 1];

    // Building the DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // Base case: if either string is empty, LCS length is 0
            if (i == 0 || j == 0)
                L[i][j] = 0;
            // If characters match, take the value from the diagonal + 1
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = 1 + L[i - 1][j - 1];
            // Otherwise, take the maximum of the value from above or left
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // The length of LCS is in the bottom-right cell of the table
    printf("Length of LCS = %d\n", L[m][n]);

    // Traceback to find the actual LCS string
    int index = L[m][n];
    char lcs[100]; // Array to store the LCS
    lcs[index] = '\0'; // Null-terminate the string

    int i = m, j = n;
    // Backtrack to construct the LCS string
    while (i > 0 && j > 0) {
        // If characters match, it's part of the LCS
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        // If not, move in the direction of the larger value in the DP table
        else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Output the LCS
    printf("LCS: %s\n", lcs);

    return 0;
}
