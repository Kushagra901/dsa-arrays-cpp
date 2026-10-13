/**
 * ============================================================================
 * PROBLEM: Subarray Product Less Than K (LeetCode 713)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of positive integers `nums` and an integer `k`, return the 
 *    number of contiguous subarrays where the product of all the elements 
 *    in the subarray is strictly less than `k`.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Brute Force Approach:
 *        • Time Complexity:  O(N^2) - Checking all subarrays until product >= k
 *        • Space Complexity: O(1)
 *    - 2. Optimal Approach (Sliding Window / Two Pointers):
 *        • Time Complexity:  O(N) - Each element is added once and divided at most once
 *        • Space Complexity: O(1) - Constant auxiliary space
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why does `k <= 1` return 0 immediately?
 *    - All numbers in `nums` are positive integers (`nums[i] >= 1`).
 *    - The product of any non-empty subarray is at least 1.
 *    - A product can never be strictly less than 1 (or 0). Hence, if `k <= 1`, return 0.
 * 
 * 2. Why does each valid window `[left, right]` add `right - left + 1` subarrays?
 *    - If the product of `nums[left ... right]` is `< k`, then every contiguous
 *      subarray ending at `right` (namely `nums[right]`, `nums[right-1 ... right]`, ...,
 *      `nums[left ... right]`) also has product `< k` because elements are positive integers >= 1.
 *    - The count of such subarrays is exactly `right - left + 1`.
 * 
 * 3. Why are elements guaranteed to be strictly positive?
 *    - The problem constraint specifies `nums[i] >= 1`.
 *    - If zeroes or negative numbers were allowed, products would not be monotonic,
 *      and standard sliding window would fail.
 * 
 * 4. Could `prod` overflow?
 *    - Use `long long` for `prod` to prevent intermediate multiplication overflow before division.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 713: Subarray Product Less Than K (Medium)
 * 2. LeetCode 209: Minimum Size Subarray Sum (Medium)
 * 3. LeetCode 560: Subarray Sum Equals K (Medium)
 * 4. LeetCode 904: Fruit Into Baskets (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// 1. BRUTE FORCE APPROACH
// Time Complexity: O(N^2) | Space Complexity: O(1)
// ============================================================================

int numSubarrayProductLessThanKBrute(const vector<int> &nums, int k) {
    if (k <= 1) return 0;
    int n = nums.size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        long long prod = 1;
        for (int j = i; j < n; j++) {
            prod *= nums[j];
            if (prod < k) {
                cnt++;
            } else {
                break; // Product only increases because nums[j] >= 1
            }
        }
    }
    return cnt;
}

// ============================================================================
// 2. OPTIMAL APPROACH: Sliding Window / Two Pointers
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

int numSubarrayProductLessThanK(const vector<int> &nums, int k) {
    // Edge case: all nums[i] >= 1, so minimum product is 1
    if (k <= 1) return 0;

    int n = nums.size();
    long long prod = 1;
    int left = 0;
    int cnt = 0;

    // Expand window by moving right pointer
    for (int right = 0; right < n; right++) {
        prod *= nums[right];

        // Shrink window from left until product is strictly less than k
        while (prod >= k && left <= right) {
            prod /= nums[left];
            left++;
        }

        // Add all subarrays ending at 'right' within the valid window
        cnt += (right - left + 1);
    }

    return cnt;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> nums1 = {10, 5, 2, 6};
    int k1 = 100;

    vector<int> nums2 = {1, 2, 3};
    int k2 = 0;

    cout << "Test 1: {10, 5, 2, 6}, k = 100 -> " 
         << numSubarrayProductLessThanK(nums1, k1) << " (Expected: 8)" << endl;

    cout << "Test 2: {1, 2, 3}, k = 0 -> " 
         << numSubarrayProductLessThanK(nums2, k2) << " (Expected: 0)" << endl;

    return 0;
}