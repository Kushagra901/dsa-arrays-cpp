/**
 * ============================================================================
 * PROBLEM: Maximum Sum Circular Subarray (LeetCode 918)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given a circular integer array `nums` of length `n`, return the maximum 
 *    possible sum of a non-empty subarray of `nums`.
 *    A circular array means the end of the array connects to the beginning.
 *    Formally, the next element of `nums[i]` is `nums[(i + 1) % n]` and the 
 *    previous element of `nums[i]` is `nums[(i - 1 + n) % n]`.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Brute Force Approach:
 *        • Time Complexity:  O(N^2) - Checking all circular subarrays of length <= N
 *        • Space Complexity: O(1)
 *    - 2. Optimal Approach (Modified Kadane's Algorithm):
 *        • Time Complexity:  O(N) - Single pass computing total, min, and max subarray sums
 *        • Space Complexity: O(1) - Constant auxiliary variables
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How does `totalSum - minSubarray` compute the circular maximum?
 *    - A circular subarray wraps around the ends (prefix + suffix).
 *    - Removing the subarray in the middle from the entire array leaves the circular ends:
 *      `Circular Sum = Total Sum - Middle Subarray Sum`.
 *    - To maximize the circular sum, we must minimize the middle subarray sum!
 * 
 * 2. Why is the all-negative corner case critical?
 *    - If all numbers in `nums` are negative (e.g. `[-3, -2, -3]`), `totalSum` equals `minSum`.
 *    - `totalSum - minSum` would evaluate to `0`, which represents an empty subarray (forbidden).
 *    - Hence, if `maxSum < 0`, we must return `maxSum` directly (the maximum single element).
 * 
 * 3. Can a subarray wrap around more than once?
 *    - No, each element can only be included at most once in any subarray (length <= n).
 * 
 * 4. What is the relation to standard Kadane's (LeetCode 53)?
 *    - Standard Kadane finds the linear max subarray. This problem considers both
 *      linear max and circular max, returning `max(linearMax, circularMax)`.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 918: Maximum Sum Circular Subarray (Medium)
 * 2. LeetCode 53: Maximum Subarray (Easy)
 * 3. LeetCode 152: Maximum Product Subarray (Medium)
 * 4. LeetCode 1749: Maximum Absolute Sum of Any Subarray (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// ============================================================================
// 1. BRUTE FORCE APPROACH
// Time Complexity: O(N^2) | Space Complexity: O(1)
// ============================================================================

int maxSubarraySumCircularBrute(const vector<int> &nums) {
    int n = nums.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        int currSum = 0;
        for (int j = 0; j < n; j++) {
            int index = (i + j) % n;
            currSum += nums[index];
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}

// ============================================================================
// 2. OPTIMAL APPROACH: Kadane's Dual Min/Max Tracking
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

int maxSubarraySumCircular(const vector<int> &nums) {
    int totalSum = 0;
    int currMax = 0, maxSum = INT_MIN;
    int currMin = 0, minSum = INT_MAX;

    for (int num : nums) {
        totalSum += num;

        // Kadane's algorithm for maximum subarray sum (linear)
        currMax = max(currMax + num, num);
        maxSum = max(maxSum, currMax);

        // Kadane's algorithm for minimum subarray sum (middle)
        currMin = min(currMin + num, num);
        minSum = min(minSum, currMin);
    }

    // Corner Case: If all numbers are negative, maxSum is the greatest single negative element
    if (maxSum < 0) {
        return maxSum;
    }

    // Result is the maximum of the linear subarray and circular wrapped subarray
    return max(maxSum, totalSum - minSum);
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> nums1 = {1, -2, 3, -2};
    vector<int> nums2 = {5, -3, 5};
    vector<int> nums3 = {-3, -2, -3};

    cout << "Test 1: {1, -2, 3, -2} -> " 
         << maxSubarraySumCircular(nums1) << " (Expected: 3)" << endl;

    cout << "Test 2: {5, -3, 5} -> " 
         << maxSubarraySumCircular(nums2) << " (Expected: 10, [5, 5])" << endl;

    cout << "Test 3: {-3, -2, -3} -> " 
         << maxSubarraySumCircular(nums3) << " (Expected: -2)" << endl;

    return 0;
}