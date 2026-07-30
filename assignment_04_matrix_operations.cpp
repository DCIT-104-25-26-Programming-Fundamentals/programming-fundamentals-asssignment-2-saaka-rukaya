// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std

const int MAX_SIZE = 10;


void inputMatrix(int matrix[10][10], int rows, int columns, string matrix_name)
{
    cout << "\nEnter elements for Matrix " << matrix_name << ":" << endl;

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            cout << "Enter element [" << row << "][" << column << "]: ";
            cin >> matrix[row][column];
        }
    }
}


void displayMatrix(int matrix[10][10], int rows, int columns)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            cout << setw(6) << matrix[row][column];
        }

        cout << endl;
    }
}


void transposeMatrix(
    int original_matrix[10][10],
    int transposed_matrix[10][10],
    int rows,
    int columns
)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            transposed_matrix[column][row] = original_matrix[row][column];
        }
    }
}


void addMatrices(
    int first_matrix[10][10],
    int second_matrix[10][10],
    int result_matrix[10][10],
    int rows,
    int columns
)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            result_matrix[row][column] =
                first_matrix[row][column] + second_matrix[row][column];
        }
    }
}


void multiplyMatrices(
    int first_matrix[10][10],
    int second_matrix[10][10],
    int result_matrix[10][10],
    int first_rows,
    int first_columns,
    int second_columns
)
{
    for (int row = 0; row < first_rows; row++)
    {
        for (int column = 0; column < second_columns; column++)
        {
            result_matrix[row][column] = 0;

            for (int position = 0; position < first_columns; position++)
            {
                result_matrix[row][column] =
                    result_matrix[row][column]
                    + first_matrix[row][position]
                    * second_matrix[position][column];
            }
        }
    }
}


bool validDimensions(int rows, int columns)
{
    if (rows <= 0 || columns <= 0 || rows > MAX_SIZE || columns > MAX_SIZE)
    {
        return false;
    }

    return true;
}


int main()
{
    int matrix_a[10][10];
    int matrix_b[10][10];
    int result_matrix[10][10];
    int transposed_matrix[10][10];

    int rows;
    int columns;

    // Part A: Transpose
    cout << "================================" << endl;
    cout << "PART A - TRANSPOSE A MATRIX" << endl;
    cout << "================================" << endl;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> columns;

    if (!validDimensions(rows, columns))
    {
        cout << "Error: Matrix dimensions must be between 1 and 10." << endl;
        return 0;
    }

    inputMatrix(matrix_a, rows, columns, "A");

    transposeMatrix(matrix_a, transposed_matrix, rows, columns);

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix_a, rows, columns);

    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transposed_matrix, columns, rows);


    // Part B: Addition
    cout << "\n================================" << endl;
    cout << "PART B - ADD TWO MATRICES" << endl;
    cout << "================================" << endl;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> columns;

    if (!validDimensions(rows, columns))
    {
        cout << "Error: Matrix dimensions must be between 1 and 10." << endl;
        return 0;
    }

    inputMatrix(matrix_a, rows, columns, "A");
    inputMatrix(matrix_b, rows, columns, "B");

    addMatrices(matrix_a, matrix_b, result_matrix, rows, columns);

    cout << "\nMatrix A:" << endl;
    displayMatrix(matrix_a, rows, columns);

    cout << "\nMatrix B:" << endl;
    displayMatrix(matrix_b, rows, columns);

    cout << "\nSum of Matrix A and Matrix B:" << endl;
    displayMatrix(result_matrix, rows, columns);


    // Part C: Multiplication
    cout << "\n================================" << endl;
    cout << "PART C - MULTIPLY TWO MATRICES" << endl;
    cout << "================================" << endl;

    int matrix_a_rows;
    int matrix_a_columns;
    int matrix_b_rows;
    int matrix_b_columns;

    cout << "Enter number of rows for Matrix A: ";
    cin >> matrix_a_rows;

    cout << "Enter number of columns for Matrix A: ";
    cin >> matrix_a_columns;

    cout << "Enter number of rows for Matrix B: ";
    cin >> matrix_b_rows;

    cout << "Enter number of columns for Matrix B: ";
    cin >> matrix_b_columns;

    if (
        !validDimensions(matrix_a_rows, matrix_a_columns)
        || !validDimensions(matrix_b_rows, matrix_b_columns)
    )
    {
        cout << "Error: Matrix dimensions must be between 1 and 10." << endl;
        return 0;
    }

    if (matrix_a_columns != matrix_b_rows)
    {
        cout << "Error: The number of columns in Matrix A must equal "
             << "the number of rows in Matrix B." << endl;

        return 0;
    }

    inputMatrix(
        matrix_a,
        matrix_a_rows,
        matrix_a_columns,
        "A"
    );

    inputMatrix(
        matrix_b,
        matrix_b_rows,
        matrix_b_columns,
        "B"
    );

    multiplyMatrices(
        matrix_a,
        matrix_b,
        result_matrix,
        matrix_a_rows,
        matrix_a_columns,
        matrix_b_columns
    );

    cout << "\nMatrix A:" << endl;
    displayMatrix(matrix_a, matrix_a_rows, matrix_a_columns);

    cout << "\nMatrix B:" << endl;
    displayMatrix(matrix_b, matrix_b_rows, matrix_b_columns);

    cout << "\nProduct of Matrix A and Matrix B:" << endl;
    displayMatrix(result_matrix, matrix_a_rows, matrix_b_columns);

    return 0;
}