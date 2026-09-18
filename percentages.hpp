#pragma once
#include <vector>
#include <string>

class MatrixPercentages {
private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;

public:
    MatrixPercentages(const std::vector<std::vector<double>>& input_data);
    MatrixPercentages row_percentage() const;
    MatrixPercentages column_percentage() const;
    void print(const std::string& title) const;
};