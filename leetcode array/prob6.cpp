/**
 * ============================================================================
 * PROBLEM: Spiral Matrix II (LeetCode 59)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given a positive integer `n`, generate an `n x n` matrix filled with 
 *    elements from `1` to `n^2` in spiral order.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Boundary Simulation:
 *        • Time Complexity:  O(N^2) - Exactly fills all N * N cells once
 *        • Space Complexity: O(1) auxiliary space (excluding the output N x N matrix)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How does the 4-pointer boundary traversal prevent overwriting cells?
 *    - Four boundary indices delineate the active layer: `top`, `bottom`, `left`, `right`.
 *    - We traverse:
 *        • Top boundary from `left` to `right`, then shrink `top++`.
 *        • Right boundary from `top` to `bottom`, then shrink `right--`.
 *        • Bottom boundary from `right` to `left`, then shrink `bottom--`.
 *        • Left boundary from `bottom` to `top`, then shrink `left++`.
 * 
 * 2. Why are boundary guards (`if (top <= bottom)` and `if (left <= right)`) critical?
 *    - When traversing non-square matrices or completing inner layers, boundary indices
 *      may cross during intermediate traversal passes. Guards prevent re-traversing cells.
 * 
 * 3. What is the difference between LeetCode 54 (Spiral Matrix I) and 59 (Spiral Matrix II)?
 *    - Spiral Matrix I reads an existing (possibly non-square M x N) matrix.
 *    - Spiral Matrix II generates and fills a square N x N matrix with sequential values 1..N^2.
 * 
 * 4. Can this be solved using direction vectors and visited matrix?
 *    - Yes, using `dx = {0, 1, 0, -1}` and `dy = {1, 0, -1, 0}`, turning 90 degrees when
 *      hitting an edge or an already filled cell. However, boundary pointers use O(1) extra space.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 59: Spiral Matrix II (Medium)
 * 2. LeetCode 54: Spiral Matrix (Medium)
 * 3. LeetCode 885: Spiral Matrix III (Medium)
 * 4. LeetCode 2326: Spiral Matrix IV (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: 4-Boundary Pointer Simulation
// Time Complexity: O(N^2) | Space Complexity: O(1) auxiliary
// ============================================================================

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        // Step 1: Traverse left to right across top boundary
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;

        // Step 2: Traverse top to bottom down right boundary
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;

        // Step 3: Traverse right to left across bottom boundary
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }

        // Step 4: Traverse bottom to top up left boundary
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }

    return matrix;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    int n = 4;
    cout << "Generated Spiral Matrix of size " << n << " x " << n << ":\n\n";

    vector<vector<int>> result = generateMatrix(n);

    for (const auto &row : result) {
        for (int val : row) {
            cout << setw(4) << val;
        }
        cout << "\n";
    }

    return 0;
}