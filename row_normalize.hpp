#pragma once
#include <vector>
#include <string>

class RowNormalize {
private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;

public:
    RowNormalize(const std::vector<std::vector<double>>& input_data);
    RowNormalize row_normalize() const;
    void print(const std::string& title) const;
};