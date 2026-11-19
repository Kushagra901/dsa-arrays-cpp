"""
============================================================================
PROBLEM: Rotate Image / Matrix by 90 Degrees Clockwise
============================================================================

📌 PROBLEM DESCRIPTION:
   You are given an `n x n` 2D matrix representing an image. Rotate the image 
   by 90 degrees clockwise in-place (without allocating another 2D matrix).

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (Transpose + Row Reversal):
       • Time Complexity:  O(N^2) - Transpose takes O(N^2 / 2), reversing rows takes O(N^2 / 2)
       • Space Complexity: O(1) - Pure in-place modification
   - Brute Force Approach:
       • Time Complexity:  O(N^2)
       • Space Complexity: O(N^2) - Auxiliary output matrix `ans[j][n - 1 - i] = mat[i][j]`

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why does Transpose + Row Reversal yield a 90° clockwise rotation?
   - Transpose maps `(i, j) -> (j, i)`.
   - Reversing each row maps `(j, i) -> (j, n - 1 - i)`.
   - The combined transformation is `(i, j) -> (j, n - 1 - i)`, which is exact 90° clockwise rotation!

2. How do you rotate 90° COUNTER-CLOCKWISE in-place?
   - Transpose the matrix, then reverse each COLUMN (or reverse each row, then transpose).

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 48: Rotate Image (Medium)
2. GeeksforGeeks: Rotate by 90 degree (Medium)
3. Coding Ninjas: Rotate Matrix (Medium)
============================================================================
"""

from typing import List


# ============================================================================
# OPTIMAL APPROACH: Transpose Matrix + Reverse Each Row (In-Place)
# Time Complexity: O(N^2) | Space Complexity: O(1)
# ============================================================================

def rotate_matrix(mat: List[List[int]]) -> None:
    """Rotates an n x n 2D matrix 90 degrees clockwise in-place."""
    n = len(mat)

    # Step 1: Transpose matrix (swap mat[i][j] with mat[j][i])
    for i in range(n - 1):
        for j in range(i + 1, n):
            mat[i][j], mat[j][i] = mat[j][i], mat[i][j]

    # Step 2: Reverse each individual row
    for i in range(n):
        mat[i].reverse()


# C++ Alias
rotateMatrix = rotate_matrix


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    arr = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]

    print("Original Matrix:")
    for row in arr:
        print(*row)

    rotate_matrix(arr)

    print("\nMatrix after 90 Degree Clockwise Rotation:")
    for row in arr:
        print(*row)
