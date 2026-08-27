/**
 * ============================================================================
 * PROBLEM: Pascal's Triangle (3 Key Variations)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Variation 1: Given row number r and column number c, find the element at position (r, c).
 *    Variation 2: Given row number n, generate and print the entire n-th row of Pascal's triangle.
 *    Variation 3: Given integer n, generate all rows of Pascal's triangle up to row n.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Variation 1 (Element at r, c):
 *        • Time Complexity:  O(c) - Calculating nCr(r-1, c-1) in linear time
 *        • Space Complexity: O(1)
 *    - Variation 2 (N-th row generation):
 *        • Time Complexity:  O(N) - Calculating elements iteratively in single pass
 *        • Space Complexity: O(N) to store row
 *    - Variation 3 (Full Pascal's Triangle):
 *        • Time Complexity:  O(N^2) - Generating 1 + 2 + 3 + ... + N = N*(N+1)/2 elements
 *        • Space Complexity: O(N^2) to return the 2D triangle
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. What mathematical formula gives the element at row r and column c (1-indexed)?
 *    - The element is nCr(r - 1, c - 1) = (r - 1)! / ((c - 1)! * (r - c)!).
 * 
 * 2. How do we compute nCr(n, r) in O(r) time without factorial overflow?
 *    - Multiply (n - i) and divide by (i + 1) incrementally in a loop from i = 0 to r - 1.
 * 
 * 3. How do we generate an entire row in O(N) time without recomputing full combinations?
 *    - The next element is derived from current element: next = curr * (row - col) / col.
 * 
 * 4. What are some properties of Pascal's Triangle?
 *    - Sum of elements in row n (0-indexed) is 2^n.
 *    - Each row is symmetric: row[i] == row[n - 1 - i].
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
    // Variation 1
    int r = 5, c = 3;
    cout << "Variation 1: Element at (" << r << ", " << c << ") is: " 
         << pascalTriangleElement(r, c) << "\n\n";

    // Variation 2
    int nRow = 5;
    cout << "Variation 2: Row " << nRow << " is: ";
    vector<int> row5 = generateRow(nRow);
    for (int val : row5) cout << val << " ";
    cout << "\n\n";

    // Variation 3
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