#include <stdio.h>
#include <stdlib.h>

// Function to read a matrix from a file
void readMatrixFromFile(const char *filename, int rows, int cols, int matrix[rows][cols]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fscanf(file, "%d", &matrix[i][j]) != 1) {
                perror("Error reading file");
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
}

// Function to write a matrix to a file
void writeMatrixToFile(const char *filename, int rows, int cols, int matrix[rows][cols]) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

// Function to add two matrices
void addMatrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main() {
    int rows, cols;

    // Input matrix dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Declare matrices
    int matrix1[rows][cols];
    int matrix2[rows][cols];
    int result[rows][cols];

    // Read matrices from files
    readMatrixFromFile("D:/SNUMTECH/HPC/matrix1.txt", rows, cols, matrix1);
    readMatrixFromFile("D:/SNUMTECH/HPC/matrix2.txt", rows, cols, matrix2);

    // Perform matrix addition
    addMatrices(rows, cols, matrix1, matrix2, result);

    // Write the result to a file
    writeMatrixToFile("result.txt", rows, cols, result);

    printf("Matrix addition completed. Result written to 'result.txt'.\n");

    return 0;
}
