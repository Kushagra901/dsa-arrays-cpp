/**
 * ============================================================================
 * PROBLEM: Determine Whether Matrix Can Be Obtained By Rotation (LeetCode 1886)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given two `n x n` binary matrices `mat` and `target`, return `true` if 
 *    it is possible to make `mat` equal to `target` by rotating `mat` in 
 *    90-degree increments, or `false` otherwise.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. In-Place Rotation Approach (Transpose + Row Reversal):
 *        • Time Complexity:  O(N^2) - At most 4 rotations of size N x N
 *        • Space Complexity: O(1) - Modifies matrix in-place without extra memory
 *    - 2. Direct Coordinate Comparison (Single-Pass Flag Check):
 *        • Time Complexity:  O(N^2) - Single traversal checking 0°, 90°, 180°, and 270° simultaneously
 *        • Space Complexity: O(1) - Only 4 boolean variables
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How is a 90-degree clockwise matrix rotation performed in-place?
 *    - Step 1: Transpose matrix (`swap(matrix[i][j], matrix[j][i])` for all `j > i`).
 *    - Step 2: Reverse each row (`reverse(matrix[i].begin(), matrix[i].end())`).
 * 
 * 2. Why are at most 4 rotations needed?
 *    - Four 90-degree rotations equal 360 degrees, restoring the matrix to its original state.
 *      Checking 0°, 90°, 180°, and 270° tests all possible orientations.
 * 
 * 3. How do the coordinate mappings work for direct single-pass checking?
 *    - 0°:   `mat[i][j] == target[i][j]`
 *    - 90°:  `mat[i][j] == target[j][n - 1 - i]`
 *    - 180°: `mat[i][j] == target[n - 1 - i][n - 1 - j]`
 *    - 270°: `mat[i][j] == target[n - 1 - j][i]`
 * 
 * 4. What if the matrices have different dimensions?
 *    - The problem constraints specify `n x n` square matrices of identical size.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 1886: Determine Whether Matrix Can Be Obtained By Rotation (Easy)
 * 2. LeetCode 48: Rotate Image (Medium)
 * 3. LeetCode 867: Transpose Matrix (Easy)
 * 4. LeetCode 73: Set Matrix Zeroes (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// 1. IN-PLACE TRANSPOSE + REVERSE ROTATION APPROACH
// Time Complexity: O(N^2) | Space Complexity: O(1)
// ============================================================================

void rotateMatrix90(vector<vector<int>> &matrix) {
    int n = matrix.size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

bool findRotationInPlace(vector<vector<int>> mat, const vector<vector<int>> &target) {
    // Check 0, 90, 180, and 270 degrees
    for (int i = 0; i < 4; i++) {
        if (mat == target) return true;
        rotateMatrix90(mat);
    }
    return false;
}

// ============================================================================
// 2. DIRECT COORDINATE MAPPING (Single-Pass Check)
// Time Complexity: O(N^2) | Space Complexity: O(1)
// ============================================================================

bool findRotationDirect(const vector<vector<int>> &mat, const vector<vector<int>> &target) {
    int n = mat.size();
    bool r0 = true, r90 = true, r180 = true, r270 = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != target[i][j])                 r0 = false;
            if (mat[i][j] != target[j][n - 1 - i])         r90 = false;
            if (mat[i][j] != target[n - 1 - i][n - 1 - j]) r180 = false;
            if (mat[i][j] != target[n - 1 - j][i])         r270 = false;
        }
    }

    return r0 || r90 || r180 || r270;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<vector<int>> mat1 = {{0, 1}, {1, 0}};
    vector<vector<int>> target1 = {{1, 0}, {0, 1}};

    vector<vector<int>> mat2 = {{0, 1}, {1, 1}};
    vector<vector<int>> target2 = {{1, 0}, {0, 1}};

    cout << "Test 1 (Can rotate): " 
         << (findRotationInPlace(mat1, target1) ? "true" : "false") 
         << " (Direct Check: " << (findRotationDirect(mat1, target1) ? "true" : "false") << ")" << endl;

    cout << "Test 2 (Cannot rotate): " 
         << (findRotationInPlace(mat2, target2) ? "true" : "false") 
         << " (Direct Check: " << (findRotationDirect(mat2, target2) ? "true" : "false") << ")" << endl;

    return 0;
}