#pragma once
#include <vector>

class MatrixPercentages {
private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;

public:
    // Constructor declaration
    MatrixPercentages(const std::vector<std::vector<double>>& input_data);

    // Function declarations
    MatrixPercentages row_percentage() const;
    MatrixPercentages column_percentage() const;
};