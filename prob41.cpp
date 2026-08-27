/**
 * ============================================================================
 * PROBLEM: Find the Repeating and Missing Number (Missing and Repeating)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    You are given a read-only array of `n` integers from `1` to `n`. Each integer 
 *    from `1` to `n` appears exactly once except one integer `X` which appears twice 
 *    (repeating), and one integer `Y` which is missing.
 *    Find and return `[X, Y]` (repeating, missing).
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Approach 1 (Mathematical Equations S and S^2):
 *        • Time Complexity:  O(N) - Single pass to compute sum and sum of squares
 *        • Space Complexity: O(1) - Pure O(1) auxiliary memory using `long long`
 *    - Approach 2 (Bitwise XOR):
 *        • Time Complexity:  O(N) - Single pass XORing elements and indices
 *        • Space Complexity: O(1) - Pure O(1) memory without overflow risks
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How does the Mathematical Equation approach derive X and Y?
 *    - Let S_N = N * (N + 1) / 2 and S_2N = N * (N + 1) * (2 * N + 1) / 6.
 *    - Let S = sum of all elements in array, and S_2 = sum of squares of all elements in array.
 *    - Equation 1: S - S_N = X - Y (let this be val1).
 *    - Equation 2: S_2 - S_2N = X^2 - Y^2 = (X - Y) * (X + Y) = val1 * (X + Y).
 *    - Therefore: X + Y = (S_2 - S_2N) / val1 (let this be val2).
 *    - Solving: X = (val1 + val2) / 2 and Y = X - val1.
 * 
 * 2. Why is `long long` mandatory for the math approach?
 *    - For N = 10^5, sum of squares ≈ 10^15 / 3, which drastically exceeds 32-bit INT_MAX (≈ 2 * 10^9).
 * 
 * 3. How does the Bitwise XOR method work?
 *    - XOR all array elements and all numbers 1..N to get (X ^ Y).
 *    - Find the differentiating bit (rightmost set bit), divide numbers into two buckets, 
 *      and isolate X and Y in O(1) space without any multiplication overflow.
 * 
 * 4. What if the array can be modified (Index Negation / Array as Hash Table)?
 *    - Mark `arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1]`. If already negative, that's the duplicate!
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. GeeksforGeeks: Missing And Repeating (Medium)
 * 2. LeetCode 268: Missing Number (Easy)
 * 3. LeetCode 287: Find the Duplicate Number (Medium)
 * 4. LeetCode 448: Find All Numbers Disappeared in an Array (Easy)
 * 5. Coding Ninjas: Missing and repeating numbers (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// 1. OPTIMAL APPROACH: Mathematical Equations (S and S^2)
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

vector<int> findMissingAndRepeatingMath(const vector<int> &a) {
    long long n = a.size();

    // Sum of first N natural numbers: S_N = N * (N + 1) / 2
    long long SN = (n * (n + 1)) / 2;

    // Sum of squares of first N natural numbers: S_2N = N * (N + 1) * (2 * n + 1) / 6
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    // val1 = X - Y
    long long val1 = S - SN;

    // val2 = X^2 - Y^2 = (X - Y)(X + Y)
    long long val2 = S2 - S2N;

    // val2 = X + Y
    val2 = val2 / val1;

    // X = ((X - Y) + (X + Y)) / 2
    long long x = (val1 + val2) / 2;

    // Y = X - (X - Y)
    long long y = x - val1;

    return {(int)x, (int)y}; // {Repeating X, Missing Y}
}

// ============================================================================
// 2. ALTERNATIVE OPTIMAL APPROACH: Bitwise XOR
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

vector<int> findMissingAndRepeatingXOR(const vector<int> &a) {
    int n = a.size();
    int xr = 0;

    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    // Get rightmost set bit
    int number = (xr & ~(xr - 1));

    int zeroGroup = 0, oneGroup = 0;
    for (int i = 0; i < n; i++) {
        // Part of array
        if ((a[i] & number) != 0) oneGroup ^= a[i];
        else zeroGroup ^= a[i];

        // Part of 1..n
        if (((i + 1) & number) != 0) oneGroup ^= (i + 1);
        else zeroGroup ^= (i + 1);
    }

    // Identify which one is repeating
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == zeroGroup) count++;
    }

    if (count == 2) return {zeroGroup, oneGroup};
    return {oneGroup, zeroGroup};
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};

    cout << "Array elements: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    vector<int> ans = findMissingAndRepeatingMath(a);
    cout << "The repeating and missing numbers (Math) are: {Repeating: "
         << ans[0] << ", Missing: " << ans[1] << "}\n";

    vector<int> ansXOR = findMissingAndRepeatingXOR(a);
    cout << "The repeating and missing numbers (XOR)  are: {Repeating: "
         << ansXOR[0] << ", Missing: " << ansXOR[1] << "}\n";

    return 0;
}