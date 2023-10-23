#include <iostream>
#include <fstream>
#include <iomanip>

//max size of matrix
const int MAX_SIZE = 100;

//function to read matrix file
void read_matrix_file(int matrix_A[MAX_SIZE][MAX_SIZE], int matrix_B[MAX_SIZE][MAX_SIZE], int& size, const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }

    //first number is entered as the size
    file >> size;

    //assign rest of values to two matrices
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix_A[i][j];
        }
     }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix_B[i][j];
        }
    }

    file.close();
}

//function to print a matrix by looping through every value in the matrix
void print_matrix(const int matrix[MAX_SIZE][MAX_SIZE], int size, const char* matrixName) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//function to add two matrices and store into a result matrix
void matrix_addition(const int matrix_A[MAX_SIZE][MAX_SIZE], const int matrix_B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix_A[i][j] + matrix_B[i][j];
        }
    }
}

//function to multiply two matrices and store into a result matrix
void matrix_multiply(const int matrix_A[MAX_SIZE][MAX_SIZE], const int matrix_B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }
}

//function to subtract two matrices and store into a result matrix
void matrix_subtraction(const int matrix_A[MAX_SIZE][MAX_SIZE], const int matrix_B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix_A[i][j] - matrix_B[i][j];
        }
    }
}

//main function
int main() {

    //variables to store size of matrices and 3 matrices
    int size;
    int matrix_A[MAX_SIZE][MAX_SIZE];
    int matrix_B[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    //read matrices from file
    read_matrix_file(matrix_A, matrix_B, size, "matrix_input.txt");

    //print matrices
    std::cout << "Matrix A:\n";
    print_matrix(matrix_A, size, "A");
    std::cout << "\nMatrix B:\n";
    print_matrix(matrix_B, size, "B");

    //sum of matrices
    matrix_addition(matrix_A, matrix_B, result, size);
    std::cout << "\nMatrix Sum (A + B):\n";
    print_matrix(result, size, "Sum");

    //product of matrices
    matrix_multiply(matrix_A, matrix_B, result, size);
    std::cout << "\nMatrix Product (A * B):\n";
    print_matrix(result, size, "Product");

    //difference of matrices
    matrix_subtraction(matrix_A, matrix_B, result, size);
    std::cout << "\nMatrix Difference (A - B):\n";
    print_matrix(result, size, "Difference");

    return 0;
}