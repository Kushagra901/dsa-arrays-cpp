/**
 * ============================================================================
 * PROBLEM: Maximum Absolute Sum of Any Subarray (LeetCode 1749)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    You are given an integer array `nums`. The absolute sum of a subarray 
 *    `[nums[l], nums[l+1], ..., nums[r-1], nums[r]]` is `abs(nums[l] + ... + nums[r])`.
 *    Return the maximum absolute sum of any (possibly empty) subarray of `nums`.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Brute Force Approach (All Subarrays):
 *        • Time Complexity:  O(N^2) - Checking all subarray sums
 *        • Space Complexity: O(1)
 *    - 2. Dual Kadane's Algorithm:
 *        • Time Complexity:  O(N) - Track running max subarray and min subarray
 *        • Space Complexity: O(1) - Constant auxiliary space
 *    - 3. Prefix Sum Range Method (Ultra-Optimal Insight):
 *        • Time Complexity:  O(N) - Single pass tracking min & max prefix sum
 *        • Space Complexity: O(1) - Result is simply `maxPrefix - minPrefix`!
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why does `abs(subarray_sum)` equal `max(maxSubarray, abs(minSubarray))`?
 *    - The absolute value `|x|` is maximized when `x` is either maximally positive
 *      or minimally negative (most negative).
 *    - Running standard Kadane gives the maximally positive subarray sum.
 *    - Running inverted Kadane gives the most negative subarray sum.
 * 
 * 2. Why does the Prefix Sum insight `max(prefix) - min(prefix)` work?
 *    - Any subarray sum is the difference between two prefix sums: `prefix[j] - prefix[i]`.
 *    - To maximize `|prefix[j] - prefix[i]|`, we pick the maximum prefix sum seen
 *      and subtract the minimum prefix sum seen (with `prefix[0] = 0` included for empty prefix).
 * 
 * 3. Does this handle empty subarrays?
 *    - Since the absolute sum of an empty subarray is 0, the answer is always `>= 0`.
 * 
 * 4. Can this overflow standard 32-bit integer?
 *    - Check problem constraints: if `nums.length <= 10^5` and `nums[i] <= 10^4`,
 *      max sum is `10^9`, which fits comfortably within a standard 32-bit signed integer.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 1749: Maximum Absolute Sum of Any Subarray (Medium)
 * 2. LeetCode 53: Maximum Subarray (Easy)
 * 3. LeetCode 918: Maximum Sum Circular Subarray (Medium)
 * 4. LeetCode 152: Maximum Product Subarray (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// ============================================================================
// 1. DUAL KADANE'S ALGORITHM
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

int maxAbsoluteSumKadane(const vector<int> &nums) {
    int maxSum = 0;       // Max positive subarray sum
    int minSum = 0;       // Min negative subarray sum
    int currentMax = 0;
    int currentMin = 0;

    for (int num : nums) {
        currentMax = max(num, currentMax + num);
        maxSum = max(maxSum, currentMax);

        currentMin = min(num, currentMin + num);
        minSum = min(minSum, currentMin);
    }

    return max(maxSum, abs(minSum));
}

// ============================================================================
// 2. OPTIMAL PREFIX SUM RANGE METHOD
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

int maxAbsoluteSumPrefix(const vector<int> &nums) {
    int prefix = 0;
    int minPrefix = 0; // Includes prefix sum before array starts (sum = 0)
    int maxPrefix = 0;

    for (int num : nums) {
        prefix += num;
        minPrefix = min(minPrefix, prefix);
        maxPrefix = max(maxPrefix, prefix);
    }

    // Maximum distance between any two prefix sums
    return maxPrefix - minPrefix;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> nums1 = {1, -3, 2, 3, -4};
    vector<int> nums2 = {2, -5, 1, -4, 3, -2};

    cout << "Test 1: {1, -3, 2, 3, -4}" << endl;
    cout << "  Dual Kadane:    " << maxAbsoluteSumKadane(nums1) << endl;
    cout << "  Prefix Range:   " << maxAbsoluteSumPrefix(nums1) << endl;

    cout << "\nTest 2: {2, -5, 1, -4, 3, -2}" << endl;
    cout << "  Dual Kadane:    " << maxAbsoluteSumKadane(nums2) << endl;
    cout << "  Prefix Range:   " << maxAbsoluteSumPrefix(nums2) << endl;

    return 0;
}