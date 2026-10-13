/**
 * ============================================================================
 * PROBLEM: Contiguous Array (Equal Number of 0s and 1s) (LeetCode 525)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given a binary array `nums`, return the maximum length of a contiguous 
 *    subarray with an equal number of `0` and `1`.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Brute Force Approach:
 *        • Time Complexity:  O(N^2) - Checking all pairs (i, j)
 *        • Space Complexity: O(1) - Constant auxiliary space
 *    - 2. Optimal Approach (Prefix Sum with 0 as -1 + Hash Map):
 *        • Time Complexity:  O(N) - Single pass through the array
 *        • Space Complexity: O(N) - Hash map storing earliest occurrence of each prefix sum
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How is this problem reduced to "Longest Subarray with Sum 0"?
 *    - By transforming all `0`s into `-1`s, an equal number of 0s and 1s sum to `0`.
 *    - Finding the longest subarray with equal 0s and 1s becomes identical to finding
 *      the longest subarray with sum equal to 0.
 * 
 * 2. Why do we initialize `mp[0] = -1`?
 *    - If the running sum becomes 0 at index `i`, the subarray from index 0 to `i`
 *      has equal 0s and 1s.
 *    - Its length is `i - (-1) = i + 1`. Initializing `mp[0] = -1` handles this base case cleanly.
 * 
 * 3. Why do we NOT update `mp[sum]` if `sum` has been seen before?
 *    - To maximize subarray length `i - mp[sum]`, we want the EARLIEST index where `sum` appeared.
 *      Overwriting with a later index would reduce the subarray length.
 * 
 * 4. What if the array contains only 0s or only 1s?
 *    - The sum will monotonically decrease or increase, never matching an earlier sum.
 *      The function correctly returns 0.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 525: Contiguous Array (Medium)
 * 2. LeetCode 560: Subarray Sum Equals K (Medium)
 * 3. LeetCode 523: Continuous Subarray Sum (Medium)
 * 4. GeeksforGeeks: Largest subarray of 0's and 1's (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ============================================================================
// 1. BRUTE FORCE APPROACH
// Time Complexity: O(N^2) | Space Complexity: O(1)
// ============================================================================

int findMaxLengthBrute(const vector<int> &nums) {
    int n = nums.size();
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += (nums[j] == 0) ? -1 : 1;
            if (sum == 0) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}

// ============================================================================
// 2. OPTIMAL APPROACH: Prefix Sum + Hash Map
// Time Complexity: O(N) | Space Complexity: O(N)
// ============================================================================

int findMaxLength(const vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> mp; // {prefixSum -> earliest index seen}
    mp[0] = -1;                 // Base case: handles subarray starting from index 0
    int sum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        // Treat 0 as -1 and 1 as +1
        sum += (nums[i] == 0) ? -1 : 1;

        // If prefix sum was observed before, subarray between those indices has sum 0
        if (mp.find(sum) != mp.end()) {
            maxLength = max(maxLength, i - mp[sum]);
        } else {
            // Record only the first occurrence of this prefix sum
            mp[sum] = i;
        }
    }

    return maxLength;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> nums1 = {0, 1};
    vector<int> nums2 = {0, 1, 0};
    vector<int> nums3 = {0, 0, 1, 0, 0, 0, 1, 1};

    cout << "Test 1: {0, 1} -> " << findMaxLength(nums1) << " (Expected: 2)" << endl;
    cout << "Test 2: {0, 1, 0} -> " << findMaxLength(nums2) << " (Expected: 2)" << endl;
    cout << "Test 3: {0, 0, 1, 0, 0, 0, 1, 1} -> " << findMaxLength(nums3) << " (Expected: 6)" << endl;

    return 0;
}