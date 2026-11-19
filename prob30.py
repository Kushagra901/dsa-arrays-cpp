"""
============================================================================
PROBLEM: Pascal's Triangle (All 3 Variations)
============================================================================

📌 PROBLEM DESCRIPTION:
   Pascal's Triangle is a triangular array of integers where each number 
   is the sum of the two numbers directly above it.
   This file implements all three standard interview variations:
     1. Given row `r` and column `c`, find the element at position (r, c).
     2. Given row number `n`, print the entire n-th row in O(n) time.
     3. Given `numRows`, generate the entire Pascal's Triangle up to `numRows`.

💡 COMPLEXITY ANALYSIS:
   - Variation 1 (Element at r, c):
       • Formula: `(r - 1) C (c - 1)`
       • Time Complexity:  O(c) - Linear loop computing combination
       • Space Complexity: O(1) - Constant auxiliary space
   - Variation 2 (Generate n-th Row):
       • Time Complexity:  O(N) - Direct iterative formula `ans = ans * (row - col) // col`
       • Space Complexity: O(N) - Result list
   - Variation 3 (Generate Full Triangle):
       • Time Complexity:  O(N^2) - Generating all N rows
       • Space Complexity: O(N^2) - 2D matrix storage for triangle

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. How is combinatorics `nCr` computed in O(r) time without factorial overflow?
   - `nCr = (n * (n - 1) * ... * (n - r + 1)) / (1 * 2 * ... * r)`
   - Iteratively: `res = res * (n - i) // (i + 1)`.

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 118: Pascal's Triangle (Easy)
2. LeetCode 119: Pascal's Triangle II (Easy)
3. GeeksforGeeks: Pascal Triangle (Easy)
============================================================================
"""

from typing import List


# ============================================================================
# VARIATION 1: Find Element at Position (r, c)
# Time Complexity: O(c) | Space Complexity: O(1)
# ============================================================================

def n_cr(n: int, r: int) -> int:
    """Calculates nCr (combination) in O(r) time."""
    res = 1
    for i in range(r):
        res = res * (n - i)
        res = res // (i + 1)
    return res


def pascal_triangle_element(r: int, c: int) -> int:
    """1-indexed row and column."""
    return n_cr(r - 1, c - 1)


# ============================================================================
# VARIATION 2: Generate the N-th Row of Pascal's Triangle in O(N) Time
# Time Complexity: O(N) | Space Complexity: O(N)
# ============================================================================

def generate_row(row: int) -> List[int]:
    """Generates the row-th row (1-indexed) in O(row) time."""
    ans = 1
    ans_row = [1]

    for col in range(1, row):
        ans = ans * (row - col)
        ans = ans // col
        ans_row.append(ans)

    return ans_row


# ============================================================================
# VARIATION 3: Generate Full Pascal's Triangle (up to n rows)
# Time Complexity: O(N^2) | Space Complexity: O(N^2)
# ============================================================================

def pascal_triangle(n: int) -> List[List[int]]:
    """Generates the first n rows of Pascal's Triangle."""
    ans: List[List[int]] = []
    for row in range(1, n + 1):
        ans.append(generate_row(row))
    return ans


# C++ Aliases
nCr = n_cr
pascalTriangleElement = pascal_triangle_element
generateRow = generate_row
pascalTriangle = pascal_triangle


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    # Variation 1: Element at (5, 3)
    r = 5
    c = 3
    print(f"Variation 1: Element at row {r}, col {c} is: {pascal_triangle_element(r, c)}\n")

    # Variation 2: Row 5
    n_row = 5
    row5 = generate_row(n_row)
    print(f"Variation 2: Row {n_row} is:", *row5, "\n")

    # Variation 3: Full Triangle (first 5 rows)
    n = 5
    print(f"Variation 3: Full Pascal's Triangle (first {n} rows):")
    triangle = pascal_triangle(n)
    for row in triangle:
        print(*row)
