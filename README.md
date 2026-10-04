# Group 23 Matrix Transformations

## Team Members

| Name | Role / Branch |
| :--- | :--- |
| Chemisto Jairus | Group Leader / Project Coordination |
| Batte Derrick Calvin & Aogon Sharon Shon | Row Normalize (`row_normalize`) |
| Wasswa George Mpanga & Bakalu Valeria | Matrix Differences (`differences`) |
| Muwanguzi Samuel & Mwanje Ian | Matrix Percentages (`percentages`) |

## Task Requirements
The objective of this project was to implement statistical and arithmetic matrix transformations from Group 23, mirroring operations found in data processing libraries. The implemented operations include:
*   **Row Normalize:** Applies Min-Max scaling to each row, mapping values to a [0, 1] range.
*   **Row Difference:** Calculates the difference between adjacent elements within a row.
*   **Column Difference:** Calculates the difference between adjacent elements within a column.
*   **Row Percentage:** Expresses each element as a percentage of its row's total sum.
*   **Column Percentage:** Expresses each element as a percentage of its column's total sum.

## Implementation Strategy
The solution is structured using a modular Object-Oriented Programming (OOP) approach to support collaborative development and avoid Git merge conflicts:
*   **Modular Classes:** The operations are divided into three distinct classes (`RowNormalize`, `MatrixDifferences`, and `MatrixPercentages`), each with their own header (`.hpp`) and source (`.cpp`) files. 
*   **Encapsulation:** Matrix data is stored in a `private` 2D standard vector (`std::vector<std::vector<double>>`) within each class, protecting it from unintended modifications.
*   **Immutability:** The transformation methods do not mutate the original matrix. They allocate a new 2D vector, perform calculations, and return a new class instance.
*   **Central Execution:** A central `main.cpp` file includes all team members' headers, initializes a shared dataset, and executes the operations sequentially.

## Key Decisions
*   **Standard Libraries vs. Raw Pointers:** `std::vector` was chosen over manual pointer manipulation (e.g., `double**`) to ensure memory safety, provide automatic memory deallocation, and simplify dynamic sizing.
*   **Handling Division by Zero:** Explicit safeguards (`if (range != 0)`, `if (row_sum != 0)`) were implemented in the normalization and percentage functions to prevent fatal arithmetic crashes or `NaN` outputs when dealing with zero-variance rows or zero-sum arrays.
*   **Shared Print Utility:** A standardized `print()` method was added to every class to format the floating-point output to two decimal places, bypassing the private data restriction for console visualization.

## Testing Approach
The integrated solution was tested by compiling all source files together using `g++ main.cpp row_normalize.cpp differences.cpp percentages.cpp -o group23_app`. 
*   **Standard Matrices:** Verified logic using a standard 3x3 matrix containing a mix of single-digit and triple-digit positive numbers.
*   **Output Validation:** The calculated differences, percentages, and normalized bounds were manually verified against expected mathematical limits.
*   **Edge Cases Check:** Verified that the algorithms bypassed division logic correctly when row or column sums equaled zero.

## Working Example

**Input Data:**
```cpp
std::vector<std::vector<double>> raw_data = {
    {10.0, 20.0, 30.0},
    {5.0,  15.0, 5.0},
    {100.0, 200.0, 300.0}
};



