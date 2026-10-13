/**
 * ============================================================================
 * PROBLEM: Longest Continuous Increasing Subsequence (LeetCode 674)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an unsorted array of integers `nums`, return the length of the 
 *    longest continuous increasing subsequence (i.e. subarray). The subsequence 
 *    must be strictly increasing.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Brute Force Approach:
 *        • Time Complexity:  O(N^2) - Checking increasing streak starting from each index
 *        • Space Complexity: O(1)
 *    - 2. Optimal Approach (Single-Pass Greedy Streak / Sliding Window):
 *        • Time Complexity:  O(N) - Single linear traversal comparing adjacent elements
 *        • Space Complexity: O(1) - Constant auxiliary space
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. What is the difference between Subsequence and Continuous Subsequence (Subarray)?
 *    - A general subsequence (LeetCode 300) does NOT require elements to be adjacent;
 *      solved using Dynamic Programming or Binary Search (Patience Sorting) in O(N log N).
 *    - A continuous increasing subsequence requires elements to be contiguous;
 *      solved greedily in O(N) single pass.
 * 
 * 2. Does non-decreasing count as increasing?
 *    - The problem requires strictly increasing (`nums[i] > nums[i - 1]`).
 *      If equal (`nums[i] == nums[i - 1]`), streak resets to 1.
 * 
 * 3. What are the base edge cases?
 *    - Empty array (`n == 0`): returns 0.
 *    - Single element array (`n == 1`): returns 1.
 * 
 * 4. Can two pointers (sliding window) be used?
 *    - Yes, an anchor pointer marks the start of the current increasing window.
 *      When `nums[i] <= nums[i - 1]`, anchor moves to `i`. Length is `i - anchor + 1`.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 674: Longest Continuous Increasing Subsequence (Easy)
 * 2. LeetCode 300: Longest Increasing Subsequence (Medium)
 * 3. LeetCode 128: Longest Consecutive Sequence (Medium)
 * 4. LeetCode 228: Summary Ranges (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// 1. BRUTE FORCE APPROACH
// Time Complexity: O(N^2) | Space Complexity: O(1)
// ============================================================================

int findLengthOfLCISBrute(const vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return 0;

    int maxLength = 1;
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] > nums[j - 1]) {
                count++;
            } else {
                break;
            }
        }
        maxLength = max(maxLength, count);
    }
    return maxLength;
}

// ============================================================================
// 2. OPTIMAL APPROACH: Single-Pass Greedy Streak
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

int findLengthOfLCIS(const vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return 0;

    int maxLength = 1;
    int cnt = 1;

    for (int i = 1; i < n; i++) {
        // If strictly increasing, extend current streak
        if (nums[i] > nums[i - 1]) {
            cnt++;
        } else {
            // Reset streak to 1 at current element
            cnt = 1;
        }
        maxLength = max(maxLength, cnt);
    }

    return maxLength;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> nums1 = {1, 3, 5, 4, 7};
    vector<int> nums2 = {2, 2, 2, 2, 2};

    cout << "Test 1: {1, 3, 5, 4, 7} -> " 
         << findLengthOfLCIS(nums1) << " (Expected: 3, [1, 3, 5])" << endl;

    cout << "Test 2: {2, 2, 2, 2, 2} -> " 
         << findLengthOfLCIS(nums2) << " (Expected: 1, [2])" << endl;

    return 0;
}