
#include <stdio.h>
#include <stdlib.h>

// Function to generate Pascal's Triangle and return it as a 2D array
int** generatePascalsTriangle(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;

    // Allocate memory for the result
    int** result = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++) {
        // Allocate memory for each row
        result[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;

        // Set the first and last elements of each row to 1
        result[i][0] = result[i][i] = 1;

        // Calculate the middle elements based on the values above them
        for (int j = 1; j < i; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }

    return result;
}

// Function to print Pascal's Triangle
void printPascalsTriangle(int** triangle, int numRows, int* columnSizes) {
	printf("[");
    for (int i = 0; i < numRows; i++) {
        printf("[");
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d", triangle[i][j]);
            if (j < columnSizes[i] - 1) {
                printf(",");
            }
        }
        if(i<numRows-1)
           {
			   printf("],");
		   }
		   else
		   {
			   printf("]");
		   }
    }
    printf("]");
}

int main() {
    int numRows;

    // Input: Number of rows in Pascal's Triangle
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);

    int* returnSize;
    int** returnColumnSizes;

    // Generate Pascal's Triangle and get the result
    int** result = generatePascalsTriangle(numRows, returnSize, &returnColumnSizes);

    // Print Pascal's Triangle
    printf("Output:\n");
    printPascalsTriangle(result, numRows, returnColumnSizes);

    // Free allocated memory
    for (int i = 0; i < numRows; i++) {
        free(result[i]);
    }
    free(result);
    free(returnSize);
    free(returnColumnSizes);

    return 0;
}
