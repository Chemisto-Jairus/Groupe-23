#include "percentages.hpp"
#include <iostream>
#include <iomanip>

MatrixPercentages::MatrixPercentages(const std::vector<std::vector<double>>& input_data) {
    data = input_data;
    rows = data.size();
    cols = rows > 0 ? data[0].size() : 0;
}

MatrixPercentages MatrixPercentages::row_percentage() const {
    std::vector<std::vector<double>> res(rows, std::vector<double>(cols, 0.0));
    for (int i = 0; i < rows; ++i) {
        double row_sum = 0;
        for (int j = 0; j < cols; ++j) {
            row_sum += data[i][j];
        }
        
        if (row_sum != 0) {
            for (int j = 0; j < cols; ++j) {
                res[i][j] = (data[i][j] / row_sum) * 100.0;
            }
        }
    }
    return MatrixPercentages(res);
}

MatrixPercentages MatrixPercentages::column_percentage() const {
    std::vector<std::vector<double>> res(rows, std::vector<double>(cols, 0.0));
    std::vector<double> col_sums(cols, 0.0);
    
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            col_sums[j] += data[i][j];
        }
    }
    
    for (int j = 0; j < cols; ++j) {
        if (col_sums[j] != 0) {
            for (int i = 0; i < rows; ++i) {
                res[i][j] = (data[i][j] / col_sums[j]) * 100.0;
            }
        }
    }
    return MatrixPercentages(res);
}

void MatrixPercentages::print(const std::string& title) const {
    std::cout << title << ":\n";
    for (const auto& row : data) {
        for (double val : row) {
            std::cout << std::fixed << std::setprecision(2) << val << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "---------------------------------\n";
}