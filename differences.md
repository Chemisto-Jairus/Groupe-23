# Documentation: Row and Column Differences

## OOP Concepts Used

*   **Encapsulation:** The 2D vector `data`, along with the `rows` and `cols` integers, are kept `private` within the `MatrixDifferences` class. They can only be read and processed through the designated `public` methods.
*   **Data Abstraction:** The user interacting with `df.row_difference()` or `df.column_difference()` does not need to understand how the nested loops are structured or how the matrix index boundaries are handled. The complexity is abstracted away.
*   **Object Return Types (Immutability):** The operations do not permanently alter the original matrix. Instead, a new `MatrixDifferences` object is allocated, filled with the calculated differences, and returned, preserving the original dataset's integrity.

## Algorithm

The algorithms calculate the difference between adjacent elements across specific axes. 

**Row Difference ($\Delta x_{i,j} = x_{i,j} - x_{i,j-1}$):**
1.  Initialize a result matrix (`res`) of the exact same dimensions filled with `0.0`.
2.  Iterate through every row.
3.  Within each row, iterate through the columns starting from index `1` (skipping the first element since it has no predecessor).
4.  Subtract the value at the previous column `data[i][j-1]` from the current column `data[i][j]` and store it in `res[i][j]`. The first column remains `0.0`.
5.  Return the new object.

**Column Difference ($\Delta x_{i,j} = x_{i,j} - x_{i-1,j}$):**
1.  Initialize a zero-filled result matrix (`res`) of the exact same dimensions.
2.  Iterate through the columns.
3.  Iterate through the rows starting from index `1` (skipping the first row since it has no predecessor above it).
4.  Subtract the value at the previous row `data[i-1][j]` from the current row `data[i][j]` and store it in `res[i][j]`. The first row remains `0.0`.
5.  Return the new object.

## Possible Error Points

*   **1D Vectors / Single Rows:** If a matrix consisting of only one column is passed into `row_difference()`, or a matrix with only one row is passed into `column_difference()`, the inner loops will naturally bypass execution. The result will be a matrix of zeros, which is mathematically correct but might surprise a user expecting an error or different behavior.
*   **Empty Matrix Initialization:** If an entirely empty vector is passed during class construction, `data[0].size()` would attempt to access a non-existent index. The constructor includes a ternary check `rows > 0 ? data[0].size() : 0` to prevent an out-of-bounds segmentation fault.
*   **Jagged Arrays:** Both algorithms assume a uniform rectangular matrix. If a jagged matrix is provided (where rows have unequal column lengths), iterating up to the length of the first row's `cols` limit will cause out-of-bounds memory access crashes on shorter rows.