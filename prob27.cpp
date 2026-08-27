/**
 * ============================================================================
 * PROBLEM: Rotate Image / Matrix by 90 Degrees Clockwise
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    You are given an `n x n` 2D matrix representing an image. Rotate the image 
 *    by 90 degrees in a clockwise direction in-place (without allocating another 2D matrix).
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Transpose + Reverse Each Row):
 *        • Time Complexity:  O(N^2) - Transpose takes O(N^2/2), reversing rows takes O(N^2/2)
 *        • Space Complexity: O(1) - Pure in-place modification
 *    - Brute Force Approach (Using Dummy Matrix):
 *        • Time Complexity:  O(N^2)
 *        • Space Complexity: O(N^2) - Extra matrix where `ans[j][n - 1 - i] = mat[i][j]`
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How does the 2-step Transpose & Reverse technique achieve 90° Clockwise Rotation?
 *    - Step 1: Transpose matrix (swap `mat[i][j]` with `mat[j][i]`). Row `i` becomes Column `i`.
 *    - Step 2: Reverse each row. Reversing changes column indices from `j` to `n - 1 - j`.
 *    - Combined: `mat[i][j]` moves to `mat[j][n - 1 - i]`, which is exactly a 90° clockwise rotation!
 * 
 * 2. How do you rotate 90° COUNTER-CLOCKWISE (Anticlockwise)?
 *    - Method 1: Transpose matrix, then reverse each COLUMN (reverse column-wise).
 *    - Method 2: Reverse each ROW first, then Transpose the matrix.
 * 
 * 3. How do you rotate 180 degrees in-place?
 *    - Reverse each row, then reverse each column (or reverse the entire 1D flattened array).
 * 
 * 4. What if the matrix is rectangular (`n x m` where `n != m`)?
 *    - In-place rotation is only possible for square matrices (`n x n`).
 *      For rectangular matrices, a new `m x n` matrix must be allocated.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 48: Rotate Image (Medium)
 * 2. LeetCode 867: Transpose Matrix (Easy)
 * 3. GeeksforGeeks: Rotate by 90 degree (Medium)
 * 4. Coding Ninjas: Rotate The Matrix (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Transpose Matrix + Reverse Each Row (In-Place)
// Time Complexity: O(N^2) | Space Complexity: O(1)
// ============================================================================

void rotateMatrix(vector<vector<int>> &mat) {
    int n = mat.size();

    // Step 1: Transpose the matrix (swap mat[i][j] with mat[j][i])
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Step 2: Reverse each individual row
    for (int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    for (const auto &row : arr) {
        for (int val : row) cout << val << "\t";
        cout << "\n";
    }

    rotateMatrix(arr);

    cout << "\nMatrix after 90 Degree Clockwise Rotation:\n";
    for (const auto &row : arr) {
        for (int val : row) cout << val << "\t";
        cout << "\n";
    }

    return 0;
}