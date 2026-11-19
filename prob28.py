"""
============================================================================
PROBLEM: Spiral Matrix Traversal
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an `n x m` matrix `mat`, return all elements of the matrix 
   in spiral order (clockwise starting from the top-left corner `[0][0]`).

💡 COMPLEXITY ANALYSIS:
   - Optimal Approach (4 Boundary Pointers Traversal):
       • Time Complexity:  O(N * M) - Every cell is visited exactly once
       • Space Complexity: O(1) auxiliary memory (excluding returned result list)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why are the inner boundary checks `if top <= bottom:` and `if left <= right:` essential?
   - In single-row or single-column matrices (e.g. `1 x M` or `N x 1`), or after completing the outer ring,
     `top` may exceed `bottom` (or `left` may exceed `right`). 
     Without these checks, already-visited elements would be traversed and duplicated in reverse!

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 54: Spiral Matrix (Medium)
2. LeetCode 59: Spiral Matrix II (Medium)
3. GeeksforGeeks: Spirally traversing a matrix (Medium)
============================================================================
"""

from typing import List


# ============================================================================
# OPTIMAL APPROACH: 4 Boundary Pointers (Top, Bottom, Left, Right)
# Time Complexity: O(n * m) | Space Complexity: O(1) auxiliary
# ============================================================================

def print_spiral(mat: List[List[int]]) -> List[int]:
    """Returns elements of matrix in spiral clockwise order."""
    ans: List[int] = []
    if not mat or not mat[0]:
        return ans

    n = len(mat)
    m = len(mat[0])

    top = 0
    left = 0
    bottom = n - 1
    right = m - 1

    while top <= bottom and left <= right:
        # 1. Traverse Left to Right along top row
        for i in range(left, right + 1):
            ans.append(mat[top][i])
        top += 1

        # 2. Traverse Top to Bottom along rightmost column
        for i in range(top, bottom + 1):
            ans.append(mat[i][right])
        right -= 1

        # 3. Traverse Right to Left along bottom row
        if top <= bottom:
            for i in range(right, left - 1, -1):
                ans.append(mat[bottom][i])
            bottom -= 1

        # 4. Traverse Bottom to Top along leftmost column
        if left <= right:
            for i in range(bottom, top - 1, -1):
                ans.append(mat[i][left])
            left += 1

    return ans


# C++ Alias
printSpiral = print_spiral


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    mat = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 15, 16]
    ]

    print("Original Matrix:")
    for row in mat:
        print(*row)

    ans = print_spiral(mat)

    print("\nSpiral Traversal Order:", *ans)
