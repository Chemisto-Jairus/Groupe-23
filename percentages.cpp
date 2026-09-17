#include "percentages.hpp"

// Constructor implementation
MatrixPercentages::MatrixPercentages(const std::vector<std::vector<double>>& input_data) {
    data = input_data;
    rows = data.size();
    cols = rows > 0 ? data[0].size() : 0;
}

// Logic for row_percentage
MatrixPercentages MatrixPercentages::row_percentage() const {
    std::vector<std::vector<double>> res(rows, std::vector<double>(cols, 0.0));
    
    for (int i = 0; i < rows; ++i) {
        double row_sum = 0;
        // Calculate the sum of the current row
        for (int j = 0; j < cols; ++j) {
            row_sum += data[i][j];
        }
        
        // Prevent division by zero
        if (row_sum != 0) {
            for (int j = 0; j < cols; ++j) {
                res[i][j] = (data[i][j] / row_sum) * 100.0;
            }
        }
    }
    return MatrixPercentages(res);
}

// Logic for column_percentage
MatrixPercentages MatrixPercentages::column_percentage() const {
    std::vector<std::vector<double>> res(rows, std::vector<double>(cols, 0.0));
    std::vector<double> col_sums(cols, 0.0);
    
    // Pre-calculate all column sums to improve efficiency
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            col_sums[j] += data[i][j];
        }
    }
    
    for (int j = 0; j < cols; ++j) {
        // Prevent division by zero
        if (col_sums[j] != 0) {
            for (int i = 0; i < rows; ++i) {
                res[i][j] = (data[i][j] / col_sums[j]) * 100.0;
            }
        }
    }
    return MatrixPercentages(res);
}