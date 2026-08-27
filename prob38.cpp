/**
 * ============================================================================
 * PROBLEM: Largest Subarray with 0 Sum
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array `A` of `n` integers (containing both positive and negative values), 
 *    find the length of the longest contiguous subarray whose elements sum up to 0.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Prefix Sum + Hash Map):
 *        • Time Complexity:  O(N) average with `unordered_map` (or O(N log N) with `map`)
 *        • Space Complexity: O(N) auxiliary space to store prefix sums
 *    - Brute Force Approach (All Subarrays):
 *        • Time Complexity:  O(N^2)
 *        • Space Complexity: O(1)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why do we store only the FIRST occurrence of each prefix sum in the hash map?
 *    - To maximize subarray length `i - mpp[sum]`, we need the earliest possible index `mpp[sum]`.
 *      Overwriting `mpp[sum]` would shorten the calculated subarray length.
 * 
 * 2. Why is `sum == 0` handled specially?
 *    - If `sum == 0` at index `i`, the subarray from index 0 to `i` (length `i + 1`) 
 *      sums to 0. This is the entire prefix, which is always longer than any internal subarray ending at `i`.
 * 
 * 3. What is the relation to Contiguous Array (LeetCode 525 - Equal 0s and 1s)?
 *    - Convert all 0s in the binary array to -1s. The problem of finding the longest subarray 
 *      with equal 0s and 1s transforms directly into "Largest Subarray with 0 Sum"!
 * 
 * 4. How does this differ from "Subarray Sum Equals K"?
 *    - Sum = 0 checks for repeat prefix sums (`mpp.find(sum)`), whereas Sum = K checks for `sum - K`.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. GeeksforGeeks: Largest subarray with 0 sum (Medium)
 * 2. LeetCode 525: Contiguous Array (Medium)
 * 3. LeetCode 560: Subarray Sum Equals K (Medium)
 * 4. Coding Ninjas: Longest Subarray Zero Sum (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Prefix Sum + First Occurrence Hash Map
// Time Complexity: O(N) | Space Complexity: O(N)
// ============================================================================

int maxLen(int A[], int n) {
    unordered_map<int, int> mpp; // {prefixSum -> first occurrence index}
    int maxi = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += A[i];

        // Case 1: Entire prefix from index 0 to i sums to 0
        if (sum == 0) {
            maxi = i + 1;
        }
        // Case 2: Prefix sum has been seen before
        else {
            if (mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]);
            }
            else {
                // Store first occurrence only
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}

// ============================================================================
// COMPLEMENTARY HELPER: Power of Three Check (LeetCode 326)
// ============================================================================

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    int A[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Array elements: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;

    int result = maxLen(A, n);
    cout << "Length of the largest subarray with zero sum: " << result << endl;

    return 0;
}
