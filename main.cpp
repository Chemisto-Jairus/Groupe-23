#include <iostream>
#include <vector>


#include "row_normalize.hpp"
#include "differences.hpp"
#include "percentages.hpp"

int main() {
    
    std::vector<std::vector<double>> raw_data = {
        {10.0, 20.0, 30.0},
        {5.0,  15.0, 5.0},
        {100.0, 200.0, 300.0}
    };

    std::cout << "--- Group 23 Matrix Transformations ---\n\n";

   
    RowNormalize rn(raw_data);
    rn.row_normalize().print("Row Normalize");

   
    MatrixDifferences md(raw_data);
    md.row_difference().print("Row Difference");
    md.column_difference().print("Column Difference");


    MatrixPercentages mp(raw_data);
    mp.row_percentage().print("Row Percentage");
    mp.column_percentage().print("Column Percentage");

    return 0;
}
