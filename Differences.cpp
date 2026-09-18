#include "differences.hpp"
#include <iostream>
#include <iomanip>

MatrixDifferences::MatrixDifferences(const std::vector<std::vector<double>>& input_data) {
    data = input_data;
    rows = data.size();
    cols = rows > 0 ? data[0].size() : 0;
}

MatrixDifferences MatrixDifferences::row_difference() const {
    std::vector<std::vector<double>> res(rows, std::vector<double>(cols, 0.0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            res[i][j] = data[i][j] - data[i][j-1];
        }
    }
    return MatrixDifferences(res);
}

MatrixDifferences MatrixDifferences::column_difference() const {
    std::vector<std::vector<double>> res(rows, std::vector<double>(cols, 0.0));
    for (int i = 1; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            res[i][j] = data[i][j] - data[i-1][j];
        }
    }
    return MatrixDifferences(res);
}

void MatrixDifferences::print(const std::string& title) const {
    std::cout << title << ":\n";
    for (const auto& row : data) {
        for (double val : row) {
            std::cout << std::fixed << std::setprecision(2) << val << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "---------------------------------\n";
}