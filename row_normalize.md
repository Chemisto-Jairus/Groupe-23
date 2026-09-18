# README: Group 23 — Row/Column Transformations

## 1. Task Requirements
The objective of this task was to implement statistical and arithmetic matrix transformations from Group 23, mirroring operations found in data processing engines like Polars or Pandas. The implemented operations include:
*   **Row Difference:** Calculates the difference between adjacent elements within a row.
*   **Column Difference:** Calculates the difference between adjacent elements within a column.
*   **Row Percentage:** Expresses each element as a percentage of its row's total sum.
*   **Column Percentage:** Expresses each element as a percentage of its column's total sum.
*   **Row Normalize:** Applies Min-Max scaling to each row, mapping values to a [0, 1] range.

## 2. Implementation Strategy
The solution is structured using an Object-Oriented Programming (OOP) approach. 
*   **Data Structure:** The matrix is encapsulated within a `DataFrame` class using a 2D standard vector (`std::vector<std::vector<double>>`). 
*   **Encapsulation:** The internal matrix is kept `private`, preventing unsafe direct access.
*   **Immutability:** Transformation methods (like `row_normalize()`) do not mutate the original object. Instead, they allocate a new 2D vector, perform the calculations, and return a completely new `DataFrame` instance.

## 3. Key Decisions
*   **Standard Libraries vs. Raw Pointers:** While low-level memory allocation and manual pointer manipulation (e.g., using `double**` arrays) offer granular control over memory layout, standard libraries (`std::vector`) were chosen for this implementation. This ensures memory safety, provides automatic deallocation, and simplifies managing dynamic sizes without the overhead of manual memory tracking.
*   **Handling Division by Zero:** Mathematical transformations like percentages and Min-Max scaling are vulnerable to division by zero. Explicit safeguards were added. For example, in `row_normalize()`, if a row's maximum and minimum values are identical (making the range 0), the algorithm checks `if (range != 0)` before dividing, leaving the normalized value as `0.0` to prevent program crashes or `NaN` outputs.

## 4. Testing Approach
Edge cases and standard inputs were tested to ensure robustness:
*   **Standard Matrices:** Verified the logic using standard 3x3 matrices with positive integers.
*   **Zero-Variance Rows:** Tested rows with identical elements (e.g., `[5.0, 5.0, 5.0]`) to ensure the division-by-zero checks successfully caught exceptions during Min-Max scaling and percentage calculations.
*   **Varying Magnitudes:** Included a mix of small numbers and hundreds (e.g., 100.0, 200.0) to ensure scaling correctly compresses the values relative to their specific row constraints.

## 5. Working Example
Below is a snapshot of the input data and the expected output for the operations.

**Input Data Setup:**
```cpp
std::vector<std::vector<double>> raw_data = {
    {10.0, 20.0, 30.0},
    {5.0,  15.0, 5.0},
    {100.0, 200.0, 300.0}
};
DataFrame df(raw_data);
```

**Executing the Transformation:**
```cpp
df.row_normalize().print("Row Normalize");
```

**Expected Console Output:**
```text
Original Data:
10.00   20.00   30.00   
5.00    15.00   5.00    
100.00  200.00  300.00  
---------------------------------
Row Normalize:
0.00    0.50    1.00    
0.00    1.00    0.00    
0.00    0.50    1.00    
---------------------------------
```
