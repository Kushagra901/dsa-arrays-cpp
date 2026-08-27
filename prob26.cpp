/**
 * ============================================================================
 * PROBLEM: Set Matrix Zeroes
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an `n x m` integer matrix, if an element is 0, set its entire 
 *    row and column to 0's in-place.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (In-Place 1st Row & 1st Column as Markers):
 *        • Time Complexity:  O(2 * n * m) = O(n * m)
 *        • Space Complexity: O(1) auxiliary space
 *    - Better Approach (Using dummy row and col tracking vectors):
 *        • Time Complexity:  O(2 * n * m) = O(n * m)
 *        • Space Complexity: O(n + m) auxiliary space
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why do we need a separate `col0` variable in the O(1) space approach?
 *    - `matrix[0][0]` is shared by both row 0 and column 0.
 *    - We use `matrix[0][0]` to track whether row 0 should be zeroed,
 *      and use a separate variable `col0` to track whether column 0 should be zeroed.
 * 
 * 2. Why do we update the inner matrix `(1,1)` to `(n-1, m-1)` before row 0 and col 0?
 *    - If we modified row 0 or col 0 first, their original marker states would be lost, 
 *      erroneously turning the entire matrix into zeroes.
 * 
 * 3. What is the brute force pitfall in this problem?
 *    - Directly changing rows/cols to 0 as soon as a 0 is found will cause subsequent 
 *      elements to be mistaken for original zeroes, propagating zeroes across the whole matrix.
 * 
 * 4. How does this apply to sparse matrix representations?
 *    - For very sparse matrices, storing coordinates of original zeroes in a hash set or 
 *      coordinate list requires O(K) memory where K is the number of zeroes.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 73: Set Matrix Zeroes (Medium)
 * 2. GeeksforGeeks: Set Matrix Zeroes (Medium)
 * 3. Coding Ninjas: Zero Matrix (Medium)
 * 4. LeetCode 289: Game of Life (Medium - In-place bit state encoding)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// 1. OPTIMAL APPROACH: O(1) Space In-Place Row & Column Markers
// Time Complexity: O(n * m) | Space Complexity: O(1)
// ============================================================================

vector<vector<int>>& zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
    int col0 = 1; // Tracks whether the 0th column needs to be zeroed

    // Step 1: Traverse matrix and mark 1st row & 1st column as markers
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // Mark i-th row marker
                matrix[i][0] = 0;

                // Mark j-th column marker
                if (j != 0) {
                    matrix[0][j] = 0;
                } else {
                    col0 = 0;
                }
            }
        }
    }

    // Step 2: Update inner matrix cells from (1, 1) to (n - 1, m - 1)
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // Step 3: Handle 1st row first, then 1st column
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

// ============================================================================
// 2. BETTER APPROACH: Using Dummy Row and Col Arrays
// Time Complexity: O(n * m) | Space Complexity: O(n + m)
// ============================================================================

vector<vector<int>> zeroMatrixBetter(vector<vector<int>> &matrix, int n, int m) {
    vector<int> row(n, 0);
    vector<int> col(m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Original Matrix:\n";
    for (const auto &row : matrix) {
        for (int val : row) cout << val << " ";
        cout << "\n";
    }

    zeroMatrix(matrix, n, m);

    cout << "\nFinal Matrix after zeroMatrix:\n";
    for (const auto &row : matrix) {
        for (int val : row) cout << val << " ";
        cout << "\n";
    }

    return 0;
}
