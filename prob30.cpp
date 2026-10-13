/**
 * ============================================================================
 * PROBLEM: Pascal's Triangle (All 3 Variations)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Pascal's Triangle is a triangular array of integers where each number 
 *    is the sum of the two numbers directly above it.
 *    This file implements all three standard interview variations:
 *      1. Given row `r` and column `c`, find the element at position (r, c).
 *      2. Given row number `n`, print the entire n-th row in O(n) time.
 *      3. Given `numRows`, generate the entire Pascal's Triangle up to `numRows`.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Variation 1 (Element at r, c):
 *        • Formula: `(r - 1) C (c - 1)`
 *        • Time Complexity:  O(c) - Linear loop computing combination
 *        • Space Complexity: O(1) - Constant auxiliary space
 *    - Variation 2 (Generate n-th Row):
 *        • Time Complexity:  O(N) - Direct iterative formula `ans = ans * (row - col) / col`
 *        • Space Complexity: O(N) - Result vector
 *    - Variation 3 (Generate Full Triangle):
 *        • Time Complexity:  O(N^2) - Generating all N rows
 *        • Space Complexity: O(N^2) - 2D matrix storage for triangle
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How is combinatorics `nCr` computed in O(r) time without factorial overflow?
 *    - `nCr = (n * (n - 1) * ... * (n - r + 1)) / (1 * 2 * ... * r)`
 *    - By multiplying and dividing iteratively, intermediate numbers stay small:
 *      `res = res * (n - i) / (i + 1)`.
 * 
 * 2. Why does the naive recursive approach `val(r, c) = val(r-1, c-1) + val(r-1, c)` have exponential complexity?
 *    - Without memoization, it branches into overlapping subproblems like Fibonacci,
 *      resulting in O(2^N) time. Iterative combinatorics reduces it to O(c).
 * 
 * 3. What is the relation between Pascal's Triangle and Binomial Theorem?
 *    - The n-th row represents the coefficients of the polynomial expansion of `(a + b)^n`.
 * 
 * 4. Can row generation be done in-place with O(1) extra auxiliary space?
 *    - Yes, each row can be computed directly from the previous row or generated in O(N) independently.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 118: Pascal's Triangle (Easy)
 * 2. LeetCode 119: Pascal's Triangle II (Easy)
 * 3. GeeksforGeeks: Pascal Triangle (Easy)
 * 4. Coding Ninjas: Pascal's Triangle (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// VARIATION 1: Find Element at Position (r, c)
// Time Complexity: O(c) | Space Complexity: O(1)
// ============================================================================

long long nCr(int n, int r) {
    long long res = 1;
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

// 1-indexed row and column
long long pascalTriangleElement(int r, int c) {
    return nCr(r - 1, c - 1);
}

// ============================================================================
// VARIATION 2: Generate the N-th Row of Pascal's Triangle in O(N) Time
// Time Complexity: O(N) | Space Complexity: O(N)
// ============================================================================

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); // 1st element is always 1

    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back((int)ans);
    }
    return ansRow;
}

// ============================================================================
// VARIATION 3: Generate Full Pascal's Triangle (up to n rows)
// Time Complexity: O(N^2) | Space Complexity: O(N^2)
// ============================================================================

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    // Variation 1: Element at (5, 3)
    int r = 5, c = 3;
    cout << "Variation 1: Element at row " << r << ", col " << c << " is: " 
         << pascalTriangleElement(r, c) << "\n\n";

    // Variation 2: Row 5
    int nRow = 5;
    cout << "Variation 2: Row " << nRow << " is: ";
    vector<int> row5 = generateRow(nRow);
    for (int val : row5) cout << val << " ";
    cout << "\n\n";

    // Variation 3: Full Triangle (first 5 rows)
    int n = 5;
    cout << "Variation 3: Full Pascal's Triangle (first " << n << " rows):\n";
    vector<vector<int>> triangle = pascalTriangle(n);
    for (const auto &row : triangle) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}