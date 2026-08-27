/**
 * ============================================================================
 * PROBLEM: Find the Missing Number in an Array
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array `arr` containing `N - 1` distinct numbers in the range `[1, N]` 
 *    (or `[0, N]`), find the single missing number from the sequence.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - XOR Approach (Optimal & Overflow-Safe):
 *        • Time Complexity:  O(N) - Single pass over the array
 *        • Space Complexity: O(1) - Constant auxiliary space
 *    - Summation Formula Approach:
 *        • Time Complexity:  O(N)
 *        • Space Complexity: O(1) (Requires `long long` for large N to prevent integer overflow)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why is the XOR method preferred over the Gauss summation formula N*(N+1)/2?
 *    - For very large N (e.g. N = 10^6), N*(N+1)/2 exceeds the 32-bit signed integer limit (INT_MAX),
 *      causing integer overflow if not using 64-bit `long long`.
 *    - XOR never overflows regardless of the size of N.
 * 
 * 2. How does the XOR cancellation property work?
 *    - Properties of XOR:
 *        - a ^ a = 0 (Any number XORed with itself is 0)
 *        - a ^ 0 = a (Any number XORed with 0 is itself)
 *        - XOR is associative and commutative.
 *    - XORing all numbers in 1..N with all elements in `arr` cancels out every 
 *      number appearing in both sets, leaving ONLY the missing number!
 * 
 * 3. What if TWO numbers are missing instead of one? (LeetCode 260 / Missing Two)
 *    - Compute `XOR_total = xor1 ^ xor2` (which equals `missing1 ^ missing2`).
 *    - Find the rightmost set bit in `XOR_total` and divide numbers into two buckets 
 *      to isolate both missing values.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 268: Missing Number (Easy)
 * 2. LeetCode 448: Find All Numbers Disappeared in an Array (Easy)
 * 3. GeeksforGeeks: Missing number in array (Easy)
 * 4. Coding Ninjas: Missing Number (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// 1. OPTIMAL APPROACH: Bitwise XOR (Overflow-Safe)
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

// Function to find missing number in range [1, N]
int missingNumber(const vector<int> &a, int N) {
    int xor1 = 0; // Stores XOR of all numbers from 1 to N
    int xor2 = 0; // Stores XOR of all elements present in array

    int n = N - 1; // Array size is N - 1
    for (int i = 0; i < n; i++) {
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ N; // Include N in xor1

    return xor1 ^ xor2; // Missing number
}

// ============================================================================
// 2. MATHEMATICAL SUMMATION APPROACH
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

int missingNumberSum(const vector<int> &a, int N) {
    long long expectedSum = (1LL * N * (N + 1)) / 2;
    long long actualSum = 0;
    for (int x : a) {
        actualSum += x;
    }
    return (int)(expectedSum - actualSum);
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {1, 2, 4, 5};  
    int N = 5;  

    cout << "Array elements: ";
    for (int x : arr) cout << x << " ";
    cout << "\nRange: 1 to " << N << endl;

    int missing = missingNumber(arr, N);

    cout << "The missing number is: " << missing << endl;

    return 0;
}
