#pragma once
#include <vector>
#include <string>

class MatrixDifferences {
private:

    std::vector<std::vector<double>> data;
    int rows;
    int cols;

public:
    MatrixDifferences(const std::vector<std::vector<double>>& input_data);
    MatrixDifferences row_difference() const;
    MatrixDifferences column_difference() const;
    void print(const std::string& title) const;
};