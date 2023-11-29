#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int MATRIX_SIZE; // Size of the matrices

int matrix_A[100][100];
int matrix_B[100][100];
int result_matrix_addition[100][100];
int result_matrix_subtraction[100][100];
int result_matrix_multiplication[100][100];

// Function to perform matrix addition
void *matrix_addition(void *arg)
{
    int *args = (int *)arg;
    int row = args[0];
    int col = args[1];

    result_matrix_addition[row][col] = matrix_A[row][col] + matrix_B[row][col];
    pthread_exit(NULL);
}

// Function to perform matrix subtraction
void *matrix_subtraction(void *arg)
{
    int *args = (int *)arg;
    int row = args[0];
    int col = args[1];

    result_matrix_subtraction[row][col] = matrix_A[row][col] - matrix_B[row][col];
    pthread_exit(NULL);
}

// Function to perform matrix multiplication
void *matrix_multiply(void *arg)
{
    int *args = (int *)arg;
    int row = args[0];
    int col = args[1];

    int sum = 0;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        sum += matrix_A[row][i] * matrix_B[i][col];
    }

    result_matrix_multiplication[row][col] = sum;
    pthread_exit(NULL);
}

// Function to input a matrix from the user
void input_matrix(int matrix[100][100], const char *matrix_name)
{
    printf("Enter values for %s matrix:\n", matrix_name);
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            printf("%s[%d][%d]: ", matrix_name, i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main()
{
    // Input the matrix size from the user
    printf("Enter the size of the matrices: ");
    scanf("%d", &MATRIX_SIZE);

    // Input matrices A and B from the user
    input_matrix(matrix_A, "Matrix A");
    input_matrix(matrix_B, "Matrix B");

    // Create threads for matrix addition
    pthread_t threads_addition[100][100];
    int thread_args_addition[100][100][2];

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            thread_args_addition[i][j][0] = i;
            thread_args_addition[i][j][1] = j;
            pthread_create(&threads_addition[i][j], NULL, matrix_addition, thread_args_addition[i][j]);
        }
    }

    // Create threads for matrix subtraction
    pthread_t threads_subtraction[100][100];
    int thread_args_subtraction[100][100][2];

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            thread_args_subtraction[i][j][0] = i;
            thread_args_subtraction[i][j][1] = j;
            pthread_create(&threads_subtraction[i][j], NULL, matrix_subtraction, thread_args_subtraction[i][j]);
        }
    }

    // Create threads for matrix multiplication
    pthread_t threads_multiplication[100][100];
    int thread_args_multiplication[100][100][2];

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            thread_args_multiplication[i][j][0] = i;
            thread_args_multiplication[i][j][1] = j;
            pthread_create(&threads_multiplication[i][j], NULL, matrix_multiply, thread_args_multiplication[i][j]);
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            pthread_join(threads_addition[i][j], NULL);
            pthread_join(threads_subtraction[i][j], NULL);
            pthread_join(threads_multiplication[i][j], NULL);
        }
    }

    // Print the result matrices for addition, subtraction, and multiplication
    // Print the result matrices for addition
    printf("Result Matrix Addition:\n");
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            printf("%d ", result_matrix_addition[i][j]);
        }
        printf("\n");
    }

    // Print the result matrices for subtraction
    printf("Result Matrix Subtraction:\n");
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            printf("%d ", result_matrix_subtraction[i][j]);
        }
        printf("\n");
    }

    // Print the result matrices for multiplication
    printf("Result Matrix Multiplication:\n");
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            printf("%d ", result_matrix_multiplication[i][j]);
        }
        printf("\n");
    }
    return 0;
}
