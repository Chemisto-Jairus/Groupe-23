#pragma once
#include <vector>

class MatrixDifferences {
private:

    std::vector<std::vector<double>> data;
    int rows;
    int cols;

public:
    // Constructor declaration
    MatrixDifferences(const std::vector<std::vector<double>>& input_data);

    // Function declarations
    MatrixDifferences row_difference() const;
    MatrixDifferences column_difference() const;
};