#include "row_normalize.hpp"

// Constructor implementation
RowNormalize::RowNormalize(const std::vector<std::vector<double>>& input_data) {
    data = input_data;
    rows = data.size();
    cols = rows > 0 ? data[0].size() : 0;
}

// Your actual row_normalize logic
RowNormalize RowNormalize::row_normalize() const {
    std::vector<std::vector<double>> res(rows, std::vector<double>(cols, 0.0));
    for (int i = 0; i < rows; ++i) {
        double min_val = data[i][0];
        double max_val = data[i][0];
        
        // Find min and max in the current row
        for (int j = 1; j < cols; ++j) {
            if (data[i][j] < min_val) min_val = data[i][j];
            if (data[i][j] > max_val) max_val = data[i][j];
        }
        
        // Calculate range and normalize
        double range = max_val - min_val;
        if (range != 0) {
            for (int j = 0; j < cols; ++j) {
                res[i][j] = (data[i][j] - min_val) / range;
            }
        }
    }
    return RowNormalize(res);
}