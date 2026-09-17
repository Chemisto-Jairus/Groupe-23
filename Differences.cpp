#include "differences.hpp"

// Constructor implementation
MatrixDifferences::MatrixDifferences(const std::vector<std::vector<double>>& input_data) {
    data = input_data;
    rows = data.size();
    cols = rows > 0 ? data[0].size() : 0;
}

// Logic for row_difference
MatrixDifferences MatrixDifferences::row_difference() const {
    // Initialize a result matrix with 0.0
    std::vector<std::vector<double>> res(rows, std::vector<double>(cols, 0.0));
    
    for (int i = 0; i < rows; ++i) {
        // Start j at 1 because the first element has no left neighbor
        for (int j = 1; j < cols; ++j) {
            res[i][j] = data[i][j] - data[i][j-1];
        }
    }
    return MatrixDifferences(res);
}

// Logic for column_difference
MatrixDifferences MatrixDifferences::column_difference() const {
    // Initialize a result matrix with 0.0
    std::vector<std::vector<double>> res(rows, std::vector<double>(cols, 0.0));
    
    // Start i at 1 because the first row has no top neighbor
    for (int i = 1; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            res[i][j] = data[i][j] - data[i-1][j];
        }
    }
    return MatrixDifferences(res);
}