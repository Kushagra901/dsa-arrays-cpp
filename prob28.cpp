/**
 * ============================================================================
 * PROBLEM: Spiral Matrix Traversal
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an `n x m` matrix `mat`, return all elements of the matrix 
 *    in spiral order (clockwise starting from the top-left corner `[0][0]`).
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (4 Boundary Pointers Traversal):
 *        • Time Complexity:  O(N * M) - Every cell is visited and pushed to output exactly once
 *        • Space Complexity: O(N * M) to return the result vector, O(1) auxiliary memory
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why are the inner boundary boundary checks `if (top <= bottom)` and `if (left <= right)` essential?
 *    - In single-row or single-column matrices (e.g. `1 x M` or `N x 1`), or after completing the outer ring,
 *      `top` may exceed `bottom` (or `left` may exceed `right`). 
 *      Without these checks, already-visited elements would be traversed and duplicated in reverse!
 * 
 * 2. How do you generate a Spiral Matrix given integer `n`? (LeetCode 59: Spiral Matrix II)
 *    - Initialize an `n x n` empty matrix and run the exact same 4-boundary pointer algorithm,
 *      filling values `1, 2, 3... n*n` sequentially into `mat[row][col]`.
 * 
 * 3. What is Spiral Matrix III (LeetCode 885) and IV (LeetCode 2326)?
 *    - Spiral III: Walk in an expanding spiral starting from an internal coordinate `(rStart, cStart)` out of bounds.
 *    - Spiral IV: Populate matrix from a linked list head.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 54: Spiral Matrix (Medium)
 * 2. LeetCode 59: Spiral Matrix II (Medium)
 * 3. LeetCode 885: Spiral Matrix III (Medium)
 * 4. GeeksforGeeks: Spirally traversing a matrix (Medium)
 * 5. Coding Ninjas: Spiral Matrix (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: 4 Boundary Pointers (Top, Bottom, Left, Right)
// Time Complexity: O(n * m) | Space Complexity: O(1) auxiliary
// ============================================================================

vector<int> printSpiral(const vector<vector<int>> &mat) {
    vector<int> ans;
    if (mat.empty() || mat[0].empty()) return ans;

    int n = mat.size();       // Number of rows
    int m = mat[0].size();    // Number of columns

    // Initialize boundary pointers
    int top = 0, left = 0;
    int bottom = n - 1, right = m - 1;

    // Loop until all boundary layers are processed
    while (top <= bottom && left <= right) {

        // 1. Traverse from Left to Right along the top row
        for (int i = left; i <= right; i++) {
            ans.push_back(mat[top][i]);
        }
        top++; // Top row processed

        // 2. Traverse from Top to Bottom along the rightmost column
        for (int i = top; i <= bottom; i++) {
            ans.push_back(mat[i][right]);
        }
        right--; // Right column processed

        // 3. Traverse from Right to Left along the bottom row (check if row still valid)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(mat[bottom][i]);
            }
            bottom--; // Bottom row processed
        }

        // 4. Traverse from Bottom to Top along the leftmost column (check if col still valid)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(mat[i][left]);
            }
            left++; // Left column processed
        }
    }

    return ans;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Original Matrix:\n";
    for (const auto &row : mat) {
        for (int val : row) cout << val << "\t";
        cout << "\n";
    }

    vector<int> ans = printSpiral(mat);

    cout << "\nSpiral Traversal Order: ";
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}