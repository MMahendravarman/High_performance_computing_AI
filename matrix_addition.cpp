
/**
 * Code for 16*16 matrix addition
 * Mahendravarman
 * 2411501012
 * Mtech AI&DS
 * SNU , Chennai
 * 
 */

#include <iostream>

// Function to display a matrix
void displayMatrix(int matrix[16][16]) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices and store result 
void addMatrices(int matrix1[16][16], int matrix2[16][16], int result[16][16]) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main() {
    // Initialize two 16x16 input matrices and the result matrix
    int matrix1[16][16];
    int matrix2[16][16];
    int result[16][16];

    // Initialize input matrix 1
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            matrix1[i][j] = i + j; // Example initialization
        }
    }

    // Initialize input matrix 2
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            matrix2[i][j] = i * j; // Example initialization
        }
    }

    // Display input matrix 1
    std::cout << "Matrix 1:" << std::endl;
    displayMatrix(matrix1);

    // Display input matrix 2
    std::cout << "\nMatrix 2:" << std::endl;
    displayMatrix(matrix2);

    // Matrix Addition
    addMatrices(matrix1, matrix2, result);

    // Display the result of matrix addition
    std::cout << "\nResult of Matrix Addition:" << std::endl;
    displayMatrix(result);

    return 0;
}
