/**
 * ============================================================================
 * PROBLEM: Find Missing Number in an Array
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array containing `N - 1` distinct numbers in the range `[1, N]` 
 *    (or range `[0, N]`), find the one number from the range that is missing.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Brute Force (Exhaustive Linear Search):
 *        • Time Complexity:  O(N^2) - Search for each number 1..N linearly
 *        • Space Complexity: O(1)
 *    - 2. Hashing Approach (Frequency Array):
 *        • Time Complexity:  O(N) - Two linear passes
 *        • Space Complexity: O(N) - Hash array of size N + 1
 *    - 3. Mathematical Summation Formula:
 *        • Time Complexity:  O(N) - Single pass sum
 *        • Space Complexity: O(1) - Constant auxiliary space (use long long to prevent overflow)
 *    - 4. Optimal Bitwise XOR Approach:
 *        • Time Complexity:  O(N) - Single pass XOR traversal
 *        • Space Complexity: O(1) - Immune to integer overflow!
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why is the XOR approach superior to the Gauss Summation approach?
 *    - For large values of N (e.g. N = 10^5 or 10^9), `N * (N + 1) / 2` can easily
 *      exceed standard 32-bit (and potentially 64-bit) integer limits.
 *    - XOR never exceeds the maximum value in the range, eliminating integer overflow risks.
 * 
 * 2. What mathematical property powers the XOR solution?
 *    - Self-inverting identity: `X ^ X = 0` and `X ^ 0 = X`.
 *    - XORing all numbers from 1 to N with all numbers in the array cancels out all
 *      paired elements to 0, leaving strictly the missing number.
 * 
 * 3. How do you adapt this when the range is [0, N]? (LeetCode 268)
 *    - Simply initialize `xor1 = 0` and loop `i` from `0` to `n - 1`, XORing `i` and `arr[i]`,
 *      then finally XOR with `N`.
 * 
 * 4. Can this find multiple missing numbers?
 *    - To find two missing numbers, XOR partitions into two sets based on the rightmost set bit
 *      (similar to finding two non-repeating numbers).
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 268: Missing Number (Easy)
 * 2. GeeksforGeeks: Missing number in array (Easy)
 * 3. Coding Ninjas: Missing Number (Easy)
 * 4. LeetCode 448: Find All Numbers Disappeared in an Array (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// 1. BRUTE FORCE APPROACH: Exhaustive Search
// Time Complexity: O(N^2) | Space Complexity: O(1)
// ============================================================================

int missingNumberBruteForce(const vector<int> &arr) {
    int n = arr.size() + 1; // Range is 1 to n

    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < (int)arr.size(); j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) return i;
    }
    return -1;
}

// ============================================================================
// 2. BETTER APPROACH: Hashing with Frequency Array
// Time Complexity: O(N) | Space Complexity: O(N)
// ============================================================================

int missingNumberHashing(const vector<int> &arr) {
    int n = arr.size() + 1;
    vector<int> hash(n + 1, 0);

    for (int num : arr) {
        hash[num]++;
    }

    for (int i = 1; i <= n; i++) {
        if (hash[i] == 0) return i;
    }
    return -1;
}

// ============================================================================
// 3. MATHEMATICAL SUMMATION APPROACH
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

int missingNumberSum(const vector<int> &arr) {
    long long n = arr.size() + 1;
    long long expectedSum = (n * (n + 1)) / 2;
    long long actualSum = 0;

    for (int num : arr) {
        actualSum += num;
    }
    return (int)(expectedSum - actualSum);
}

// ============================================================================
// 4. OPTIMAL APPROACH: Bitwise XOR (Overflow-Safe)
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

int missingNumberXOR(const vector<int> &arr) {
    int n = arr.size() + 1;
    int xor1 = 0; // XOR of 1..N
    int xor2 = 0; // XOR of array elements

    for (int i = 0; i < (int)arr.size(); i++) {
        xor2 ^= arr[i];
        xor1 ^= (i + 1);
    }
    xor1 ^= n; // Include N in range

    return xor1 ^ xor2;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {8, 2, 4, 5, 3, 7, 1}; // Missing is 6 from range 1..8

    cout << "Array elements: ";
    for (int x : arr) cout << x << " ";
    cout << "\nRange: 1 to " << arr.size() + 1 << endl;

    cout << "Missing Number (Brute Force): " << missingNumberBruteForce(arr) << endl;
    cout << "Missing Number (Hashing):     " << missingNumberHashing(arr) << endl;
    cout << "Missing Number (Sum Formula): " << missingNumberSum(arr) << endl;
    cout << "Missing Number (Bitwise XOR): " << missingNumberXOR(arr) << endl;

    return 0;
}