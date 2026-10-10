# Group 23 Matrix Transformations

Our goal for this project was to build a set of statistical and arithmetic matrix transformations in C++, essentially creating our own lightweight version of a data processing library.

## Our Team

| Name | Role / Branch |
| :---- | :---- |
| Chemisto Jairus | Group Leader / Project Coordination |
| Batte Derrick Calvin and Aogon Sharon Shon | Row Normalize (`row_normalize`) |
| Wasswa George Mpanga and Bakalu Valeria | Matrix Differences (`differences`) |
| Muwanguzi Samuel and Mwanje Ian | Matrix Percentages (`percentages`) |

## What We Built

We implemented five specific matrix operations assigned to Group 23:

* **Row Normalize:** We applied Min-Max scaling to map the values of each row to a clean \[0, 1\] range.  
* **Row Difference:** A function that subtracts the previous element from the current one, moving across a row.  
* **Column Difference:** Similar to the above, but it calculates the difference between adjacent elements going down a column.  
* **Row Percentage:** We calculated what percentage each individual element contributes to its row's total sum.  
* **Column Percentage:** We did the same thing vertically, finding each element's percentage relative to its column's total.

## Our Approach and Key Decisions

Instead of cramming everything into one giant file, we split the workload using a modular Object-Oriented Programming (OOP) approach. This was crucial for our team workflow because it meant we could all work on our separate branches without overriding each other's code during Git merges.

* **Modular Design:** We divided the operations into three distinct classes (`RowNormalize`, `MatrixDifferences`, and `MatrixPercentages`). Every person got their own `.hpp` and `.cpp` files to manage.  
* **Memory Management:** We chose to use `std::vector` rather than messing with manual raw pointers. It gave us better memory safety and made handling dynamic grid sizes much easier.  
* **Data Protection:** To follow good encapsulation practices, we locked our matrix data inside a `private` 2D vector. The transformation methods never actually mutate this original data; instead, they allocate a fresh matrix, do the math, and return a brand-new object.  
* **Crash Prevention:** We realized early on that division-by-zero was a real threat (e.g., if a row's sum is zero, or all values in a row are identical). We baked in explicit safeguards like `if (range != 0)` to catch these edge cases and prevent the program from crashing with `NaN` errors.  
* **Seeing the Output:** Because our data was private, `main.cpp` couldn't just print it. We solved this by writing a shared `print()` utility inside every class to handle terminal formatting (locked to two decimal places).

## How to Build and Run in VS Code

To get this project running locally, we pulled everyone's individual branches into a single directory. From there, we used the VS Code terminal to compile and execute the combined program.

**1\. Compile the code:** We linked all the separate source files together into a single executable using the `g++` compiler.

g++ main.cpp row\_normalize.cpp differences.cpp percentages.cpp \-o group23\_app

**2\. Run the executable:** Once it finished compiling without errors, we ran the generated file to see our matrices in the terminal.

* **On Windows:**  
    
  .\\group23\_app.exe  
    
* **On Mac/Linux:**  
    
  ./group23\_app

## The Math Behind the Magic

### A. Row Normalize

The algorithm sweeps through a row to find the minimum and maximum numbers, calculating the total range. It then makes a second pass, subtracting the minimum from each element and dividing by that range. We hid all this min/max search logic behind a single `row_normalize()` method call to keep the front-end clean.

### B. Row and Column Differences

For row differences, we iterate across starting from the second column (index 1), subtracting `data[i][j-1]` from `data[i][j]`. The column version does the exact same thing but shifts the focus to the rows (`data[i-1][j]`). We included a quick ternary check in the constructor to ensure the matrix isn't entirely empty before trying to access these indexes.

### C. Row and Column Percentages

The row version is straightforward: find the row sum, then divide each element by it. For the column percentages, however, we wanted to be efficient. Rather than recalculating column sums over and over, we pre-calculated them all at once and stored them in a private 1D vector. This dramatically cut down on the memory overhead before we did the final division.

## Working Example

Here is how we set up the central `main.cpp` file to test everyone's code on a shared dataset.

**Input Data:**

std::vector\<std::vector\<double\>\> raw\_data \= {

    {10.0, 20.0, 30.0},

    {5.0,  15.0, 5.0},

    {100.0, 200.0, 300.0}

};

// 1\. Setup and Print Original

RowNormalize rn(raw\_data);

rn.print("Original Data");

// 2\. Row Normalize

rn.row\_normalize().print("Row Normalize");

// 3\. Differences

MatrixDifferences md(raw\_data);

md.row\_difference().print("Row Difference");

md.column\_difference().print("Column Difference");

// 4\. Percentages

MatrixPercentages mp(raw\_data);

mp.row\_percentage().print("Row Percentage");

mp.column\_percentage().print("Column Percentage");

**Expected Console Output:**

\--- Group 23 Matrix Transformations \---

Original Data:

10.00   20.00   30.00   

5.00    15.00   5.00    

100.00  200.00  300.00  

\---------------------------------

Row Normalize:

0.00    0.50    1.00    

0.00    1.00    0.00    

0.00    0.50    1.00    

\---------------------------------

Row Difference:

0.00    10.00   10.00   

0.00    10.00   \-10.00  

0.00    100.00  100.00  

\---------------------------------

Column Difference:

0.00    0.00    0.00    

\-5.00   \-5.00   \-25.00  

95.00   185.00  295.00  

\---------------------------------

Row Percentage:

16.67   33.33   50.00   

20.00   60.00   20.00   

16.67   33.33   50.00   

\---------------------------------

Column Percentage:

8.70    8.51    8.96    

4.35    6.38    1.49    

86.96   85.11   89.55   

\---------------------------------

## AI Usage Policy

For transparency, our team used ChatGPT to assist with this assignment. We used it to help formulate the prompts needed to build out the full C++ program structure. We also utilized it as a learning tool to understand how to navigate our Git workflow—specifically, how to create individual branches, and how to properly pull and push our code to the shared repository.
