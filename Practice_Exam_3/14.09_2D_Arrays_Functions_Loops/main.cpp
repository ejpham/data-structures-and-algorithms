#include <iostream>
#include <climits>

using namespace std;

const int MAX_SIZE = 100;

int highestRowSumValue(const int myMatrix[MAX_SIZE][MAX_SIZE], const int& nrows, const int& ncols) {
    /* Input your code here */
    int max = INT_MIN, index = -1;
    for (int i = 0; i < nrows; i++) {
        int sum = 0;
        for (int j = 0; j < ncols; j++)
            sum += myMatrix[i][j];
        if (i == 0 || sum > max) {
            max = sum;
            index = i;
        }
    }
    return index;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE], rows, cols;
    cin >> rows >> cols;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];
    cout << highestRowSumValue(matrix, rows, cols);
}