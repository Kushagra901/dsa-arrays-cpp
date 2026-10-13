/**
 * ============================================================================
 * PROBLEM: Continuous Subarray Sum (LeetCode 523)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an integer array `nums` and an integer `k`, return `true` if `nums` 
 *    has a continuous subarray of length AT LEAST TWO whose elements sum up 
 *    to a multiple of `k`, or `false` otherwise.
 *    An integer `x` is a multiple of `k` if there exists an integer `n` such that `x = n * k`.
 *    0 is always a multiple of `k`.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Brute Force Approach:
 *        • Time Complexity:  O(N^3) - Evaluating all subarray sums of length >= 2
 *        • Space Complexity: O(1)
 *    - 2. Better Approach (Running Sum in 2 Loops):
 *        • Time Complexity:  O(N^2) - Checking all pairs (i, j) with running sum
 *        • Space Complexity: O(1)
 *    - 3. Optimal Approach (Prefix Sum Modulo + Hash Map):
 *        • Time Complexity:  O(N) - Single pass through the array
 *        • Space Complexity: O(min(N, K)) - Hash map storing earliest indices for each remainder
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why does `(prefix[j] - prefix[i]) % k == 0` mean `prefix[j] % k == prefix[i] % k`?
 *    - By modular arithmetic, if two prefix sums leave the same remainder when divided by `k`,
 *      their difference must be an exact multiple of `k`:
 *      `(sum_j - sum_i) % k = (mod - mod) % k = 0`.
 * 
 * 2. Why do we initialize `modMap[0] = -1`?
 *    - If a subarray starting at index 0 up to index `i` is divisible by `k`,
 *      its length is `i - (-1) = i + 1`. This correctly allows validating subarrays
 *      starting from index 0 with length >= 2.
 * 
 * 3. Why do we NOT overwrite `modMap[mod]` if `mod` is already present?
 *    - To maximize the length of the subarray `i - modMap[mod]`, we want the EARLIEST index
 *      where remainder `mod` was observed. Updating it would decrease the chance of `length >= 2`.
 * 
 * 4. What about negative numbers?
 *    - C++ `%` operator can return negative remainders. Normalizing with `if (mod < 0) mod += k;`
 *      ensures correct mathematical congruence.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 523: Continuous Subarray Sum (Medium)
 * 2. LeetCode 974: Subarray Sums Divisible by K (Medium)
 * 3. LeetCode 560: Subarray Sum Equals K (Medium)
 * 4. LeetCode 525: Contiguous Array (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ============================================================================
// 1. BRUTE FORCE APPROACH
// Time Complexity: O(N^3) | Space Complexity: O(1)
// ============================================================================

bool checkSubarraySumBrute(const vector<int> &nums, int k) {
    int n = nums.size();
    if (n < 2) return false;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = 0;
            for (int l = i; l <= j; l++) {
                sum += nums[l];
            }
            if (sum % k == 0) return true;
        }
    }
    return false;
}

// ============================================================================
// 2. BETTER APPROACH: Running Sum in 2 Loops
// Time Complexity: O(N^2) | Space Complexity: O(1)
// ============================================================================

bool checkSubarraySumBetter(const vector<int> &nums, int k) {
    int n = nums.size();
    if (n < 2) return false;

    for (int i = 0; i < n - 1; i++) {
        int sum = nums[i];
        for (int j = i + 1; j < n; j++) {
            sum += nums[j];
            if (sum % k == 0) return true;
        }
    }
    return false;
}

// ============================================================================
// 3. OPTIMAL APPROACH: Prefix Sum Modulo + Hash Map
// Time Complexity: O(N) | Space Complexity: O(min(N, K))
// ============================================================================

bool checkSubarraySum(const vector<int> &nums, int k) {
    int n = nums.size();
    if (n < 2) return false;

    // Hash map stores {remainder -> earliest index seen}
    unordered_map<int, int> modMap;
    modMap[0] = -1; // Base case: enables subarrays starting at index 0
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        int mod = sum % k;

        // Normalize negative modulo for consistency
        if (mod < 0) mod += k; 

        // If this remainder was seen before, check if subarray length is at least 2
        if (modMap.find(mod) != modMap.end()) {
            if (i - modMap[mod] >= 2) {
                return true;
            }
        } else {
            // Store only the first occurrence of this remainder
            modMap[mod] = i; 
        }
    }
    return false;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> nums1 = {23, 2, 4, 6, 7};
    int k1 = 6;

    vector<int> nums2 = {23, 2, 6, 4, 7};
    int k2 = 6;

    vector<int> nums3 = {23, 2, 6, 4, 7};
    int k3 = 13;

    cout << "Test 1: {23, 2, 4, 6, 7}, k = 6 -> " 
         << (checkSubarraySum(nums1, k1) ? "true" : "false") << " (Expected: true, [2, 4] sum = 6)" << endl;

    cout << "Test 2: {23, 2, 6, 4, 7}, k = 6 -> " 
         << (checkSubarraySum(nums2, k2) ? "true" : "false") << " (Expected: true, [23, 2, 6, 4, 7] sum = 42)" << endl;

    cout << "Test 3: {23, 2, 6, 4, 7}, k = 13 -> " 
         << (checkSubarraySum(nums3, k3) ? "true" : "false") << " (Expected: false)" << endl;

    return 0;
}