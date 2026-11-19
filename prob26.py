"""
============================================================================
PROBLEM: Set Matrix Zeroes
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an `m x n` integer matrix, if an element is 0, set its entire row 
   and column to 0's. You must do it in-place with O(1) auxiliary space.

💡 COMPLEXITY ANALYSIS:
   - 1. Optimal Approach (O(1) Space In-Place Row & Column Markers):
       • Time Complexity:  O(2 * N * M) = O(N * M) - Two passes over the matrix
       • Space Complexity: O(1) - Using 1st row and 1st column as marker storage + 1 variable `col0`
   - 2. Better Approach (Auxiliary Row and Col Dummy Arrays):
       • Time Complexity:  O(N * M)
       • Space Complexity: O(N + M) - Auxiliary row and column lists

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why does cell `matrix[0][0]` overlap for both Row 0 and Column 0?
   - `matrix[0][0]` is used as the marker for Row 0.
   - An independent variable `col0` tracks whether Column 0 itself needs to be zeroed.

2. Why must we update the inner submatrix `[1..n-1][1..m-1]` first before row 0 and col 0?
   - If row 0 or column 0 were updated first, the marker information for the rest of the
     matrix would be overwritten and corrupted!

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 73: Set Matrix Zeroes (Medium)
2. GeeksforGeeks: Set Matrix Zeroes (Medium)
3. Coding Ninjas: Zero Matrix (Medium)
============================================================================
"""

from typing import List


# ============================================================================
# OPTIMAL APPROACH: O(1) Space In-Place Row & Column Markers
# Time Complexity: O(n * m) | Space Complexity: O(1)
# ============================================================================

def zero_matrix(matrix: List[List[int]], n: int, m: int) -> List[List[int]]:
    """Sets entire row and col to 0 in-place using O(1) extra space."""
    col0 = 1  # Tracks whether 0th column needs to be zeroed

    # Step 1: Traverse matrix and mark 1st row & 1st column as markers
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 0:
                matrix[i][0] = 0
                if j != 0:
                    matrix[0][j] = 0
                else:
                    col0 = 0

    # Step 2: Update inner matrix cells from (1, 1) to (n - 1, m - 1)
    for i in range(1, n):
        for j in range(1, m):
            if matrix[i][j] != 0:
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

    # Step 3: Handle 1st row
    if matrix[0][0] == 0:
        for j in range(m):
            matrix[0][j] = 0

    # Step 4: Handle 1st column
    if col0 == 0:
        for i in range(n):
            matrix[i][0] = 0

    return matrix


# C++ Alias
zeroMatrix = zero_matrix


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    matrix = [
        [1, 1, 1],
        [1, 0, 1],
        [1, 1, 1]
    ]
    n = len(matrix)
    m = len(matrix[0])

    print("Original Matrix:")
    for row in matrix:
        print(*row)

    zero_matrix(matrix, n, m)

    print("\nMatrix after setting zeroes (Optimal O(1) Space):")
    for row in matrix:
        print(*row)
