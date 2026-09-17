#pragma once
#include <vector>

class RowNormalize {
private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;

public:
    // Constructor declaration
    RowNormalize(const std::vector<std::vector<double>>& input_data);

    // Your specific function declaration
    RowNormalize row_normalize() const;
};