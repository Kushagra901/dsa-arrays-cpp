/**
 * ============================================================================
 * PROBLEM: Maximum Subarray Sum with One Deletion (LeetCode 1186)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of integers, you are allowed to delete at most one element 
 *    from a non-empty contiguous subarray. Return the maximum sum of such a subarray.
 *    The resulting subarray must be non-empty.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Better Approach (Prefix & Suffix Kadane's Arrays):
 *        • Time Complexity:  O(N) - 3 passes (left-to-right, right-to-left, combine)
 *        • Space Complexity: O(N) - Two auxiliary DP arrays of size N
 *    - 2. Optimal Approach (Space-Optimized Dynamic Programming):
 *        • Time Complexity:  O(N) - Single pass through the array
 *        • Space Complexity: O(1) - Constant auxiliary space (tracking noDelete and oneDelete)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How is this derived from Kadane's Algorithm?
 *    - Standard Kadane maintains `noDelete = max(arr[i], noDelete + arr[i])`.
 *    - With one deletion allowed, at element `i`:
 *        • We can delete `arr[i]`: sum becomes previous `noDelete`.
 *        • Or keep `arr[i]` after an earlier deletion: sum becomes `oneDelete + arr[i]`.
 *      Thus: `nextOneDelete = max(noDelete, oneDelete + arr[i])`.
 * 
 * 2. Why must the subarray be non-empty?
 *    - If all numbers are negative (e.g. `[-1, -2, -3]`), we cannot delete all elements
 *      to get 0. The answer is the single largest negative number (`-1`).
 * 
 * 3. What if no element is deleted?
 *    - The result is initialized with standard Kadane max (`arr[0]`), so 0 deletions
 *      is automatically considered as a valid option.
 * 
 * 4. Can we generalize to K deletions?
 *    - For K deletions, maintain DP states `dp[k]` for `0 <= k <= K` in O(N * K) time
 *      and O(K) space.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 1186: Maximum Subarray Sum with One Deletion (Medium)
 * 2. LeetCode 53: Maximum Subarray (Easy)
 * 3. LeetCode 918: Maximum Sum Circular Subarray (Medium)
 * 4. LeetCode 152: Maximum Product Subarray (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// ============================================================================
// 1. BETTER APPROACH: Prefix and Suffix Kadane Arrays
// Time Complexity: O(N) | Space Complexity: O(N)
// ============================================================================

int maximumSumPrefixSuffix(const vector<int> &arr) {
    int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return arr[0];

    // maxEndHere[i] stores max subarray sum ending at i
    vector<int> maxEndHere(n);
    maxEndHere[0] = arr[0];
    int maxSoFar = arr[0];

    for (int i = 1; i < n; i++) {
        maxEndHere[i] = max(arr[i], maxEndHere[i - 1] + arr[i]);
        maxSoFar = max(maxSoFar, maxEndHere[i]);
    }

    // maxStartHere[i] stores max subarray sum starting at i
    vector<int> maxStartHere(n);
    maxStartHere[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        maxStartHere[i] = max(arr[i], maxStartHere[i + 1] + arr[i]);
    }

    // Deleting element at index i merges maxEndHere[i-1] and maxStartHere[i+1]
    int result = maxSoFar; // Option with 0 deletions
    for (int i = 1; i < n - 1; i++) {
        result = max(result, maxEndHere[i - 1] + maxStartHere[i + 1]);
    }

    return result;
}

// ============================================================================
// 2. OPTIMAL APPROACH: Space-Optimized Dynamic Programming
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

int maximumSumOptimal(const vector<int> &arr) {
    int n = arr.size();
    if (n == 0) return 0;

    int noDelete = arr[0];        // Max subarray sum ending at current index with 0 deletions
    int oneDelete = INT_MIN;      // Max subarray sum ending at current index with 1 deletion
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        // Option 1 for oneDelete: delete current arr[i] (takes previous noDelete)
        // Option 2 for oneDelete: keep current arr[i] having already deleted an earlier element
        int nextOneDelete = noDelete;
        if (oneDelete != INT_MIN) {
            nextOneDelete = max(nextOneDelete, oneDelete + arr[i]);
        }

        // Standard Kadane update for 0 deletions
        noDelete = max(arr[i], noDelete + arr[i]);
        oneDelete = nextOneDelete;

        // Global best
        result = max(result, max(noDelete, oneDelete));
    }

    return result;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr1 = {1, -2, 0, 3};
    vector<int> arr2 = {1, -2, -2, 3};
    vector<int> arr3 = {-1, -1, -1, -1};

    cout << "Test 1: {1, -2, 0, 3} (Delete -2 -> sum 4):" << endl;
    cout << "  Prefix-Suffix DP: " << maximumSumPrefixSuffix(arr1) << endl;
    cout << "  Optimal DP O(1):  " << maximumSumOptimal(arr1) << endl;

    cout << "\nTest 2: {1, -2, -2, 3} (Delete one -2 -> sum 3):" << endl;
    cout << "  Optimal DP O(1):  " << maximumSumOptimal(arr2) << endl;

    cout << "\nTest 3: {-1, -1, -1, -1} (All negative -> max is -1):" << endl;
    cout << "  Optimal DP O(1):  " << maximumSumOptimal(arr3) << endl;

    return 0;
}