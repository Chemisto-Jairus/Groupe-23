# Documentation: Row and Column Percentages

## OOP Concepts Used

*   **Encapsulation:** The internal matrix state (`data`, `rows`, and `cols`) is shielded from external manipulation by keeping the variables `private` inside the `MatrixPercentages` class. They can only be interacted with via the specific percentage methods.
*   **Data Abstraction:** The user invoking `df.row_percentage()` does not need to manage intermediate arrays for column sums or worry about division-by-zero checks. The underlying arithmetic logic is fully hidden behind a simple method call.
*   **Object Return Types (Immutability):** The methods do not overwrite the base matrix data. Instead, they dynamically allocate a new 2D vector for the results and return a completely distinct `MatrixPercentages` instance, mimicking the immutable behavior of professional data engines like Pandas or Polars.

## Algorithm

The operations convert matrix values into percentages based on their respective axis totals.

**Row Percentage ($P_{i,j} = \left( \frac{x_{i,j}}{\sum_{k=1}^{n} x_{i,k}} \right) \times 100$):**
1.  Initialize a zero-filled result matrix (`res`).
2.  Iterate through each row `i`.
3.  Loop through the columns to compute the sum of all elements in the current row (`row_sum`).
4.  Verify the `row_sum` is not `0`.
5.  Loop through the columns again, dividing each element by `row_sum` and multiplying by `100.0`. Store the calculated result in `res[i][j]`.
6.  Return the new object.

**Column Percentage ($P_{i,j} = \left( \frac{x_{i,j}}{\sum_{k=1}^{m} x_{k,j}} \right) \times 100$):**
1.  Initialize a zero-filled result matrix (`res`) and a 1D vector (`col_sums`) to hold the total for each column.
2.  Pre-calculate the sum for every column by iterating through columns `j`, and nesting a loop through rows `i` to sum `data[i][j]`.
3.  Iterate through columns `j` again.
4.  Verify the specific `col_sums[j]` is not `0`.
5.  Iterate through rows `i`, dividing the target element by `col_sums[j]`, multiplying by `100.0`, and storing it in `res[i][j]`.
6.  Return the new object.

## Possible Error Points

*   **Division by Zero:** The sum of a row or column can easily be `0` (e.g., if all elements are `0`, or if positive and negative values perfectly cancel out). Both algorithms implement conditional checks (`if (row_sum != 0)`) to bypass the division step, safely leaving the output as `0.0` instead of crashing the program with `NaN` (Not a Number) or a fatal arithmetic exception.
*   **Memory Overhead:** Column percentage calculations require evaluating the column sums before processing the elements. A separate 1D array (`col_sums`) is allocated in memory to prevent recalculating the sum every single time a column element is processed, which improves runtime efficiency.
*   **Jagged Arrays:** Like most strict matrix operations, these algorithms assume a perfectly uniform 2D grid. Passing in jagged vectors (where rows have unequal lengths) will cause out-of-bounds access when attempting to calculate `col_sums` up to the width of the first row.