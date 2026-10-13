/**
 * ============================================================================
 * PROBLEM: Longest Subarray with Sum K
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of integers `a` and an integer `k`, find the length of the 
 *    longest contiguous subarray whose elements sum up to `k`.
 *    The array can contain positive numbers, zeroes, and negative numbers.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Brute Force Approach (All Subarrays):
 *        • Time Complexity:  O(N^2) - Nested loops checking all subarray sums
 *        • Space Complexity: O(1) - Constant auxiliary space
 *    - 2. Prefix Sum + Hash Map (Handles Positives, Negatives & Zeroes):
 *        • Time Complexity:  O(N) average with unordered_map
 *        • Space Complexity: O(N) auxiliary space for prefix sum map
 *    - 3. Two Pointers / Sliding Window (Optimal for Strictly Positives & Zeroes):
 *        • Time Complexity:  O(2N) = O(N) - Left and right pointers traverse at most N steps
 *        • Space Complexity: O(1) - Constant space
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why does the Two-Pointer approach fail when negative numbers are present?
 *    - Two Pointers assumes that expanding the right pointer monotonically increases
 *      the window sum, and shrinking the left pointer monotonically decreases it.
 *      Negative numbers break this monotonic property, so Hash Map is required.
 * 
 * 2. Why do we only update the hash map when `sum` is NOT already present?
 *    - If `preSumMap.find(sum) == preSumMap.end()`, store `preSumMap[sum] = i`.
 *    - Keeping the EARLIEST index produces the MAXIMUM length `(i - preSumMap[sum - k])`.
 *      Overwriting with a later index would minimize the subarray length.
 * 
 * 3. What if the entire prefix from 0 to i sums to k?
 *    - Condition `if (sum == k) maxLen = max(maxLen, i + 1);` directly handles this.
 * 
 * 4. What is the relation to LeetCode 560: Subarray Sum Equals K?
 *    - LeetCode 560 asks for the COUNT of subarrays instead of maximum length,
 *      requiring storing frequencies in the map rather than first-seen indices.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. GeeksforGeeks: Longest Sub-Array with Sum K (Medium)
 * 2. Coding Ninjas: Longest Subarray With Sum K (Medium)
 * 3. LeetCode 560: Subarray Sum Equals K (Medium)
 * 4. LeetCode 525: Contiguous Array (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ============================================================================
// 1. BRUTE FORCE APPROACH: Nested Iteration
// Time Complexity: O(N^2) | Space Complexity: O(1)
// ============================================================================

int longestSubarrayBruteForce(const vector<int> &arr, long long k) {
    int n = arr.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == k) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

// ============================================================================
// 2. OPTIMAL APPROACH (ALL INTEGERS): Prefix Sum + Hash Map
// Time Complexity: O(N) average | Space Complexity: O(N)
// ============================================================================

int longestSubarrayWithSumK(const vector<int> &a, long long k) {
    unordered_map<long long, int> preSumMap; // {prefixSum -> first seen index}
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < (int)a.size(); i++) {
        sum += a[i];

        // Case 1: Subarray starting from index 0 to i has sum equal to k
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // Case 2: Check if prefix sum (sum - k) exists in the map
        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // Store prefix sum only if it hasn't been seen before (to preserve leftmost index)
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

// ============================================================================
// 3. TWO POINTER APPROACH: (Optimal for Strictly Positives & Zeroes)
// Time Complexity: O(2N) = O(N) | Space Complexity: O(1)
// ============================================================================

int longestSubarrayPositivesOnly(const vector<int> &a, long long k) {
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
    int n = a.size();

    while (right < n) {
        // Shrink window if sum exceeds k
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n) sum += a[right];
    }
    return maxLen;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    long long k = 15;

    cout << "Array elements: ";
    for (int x : arr) cout << x << " ";
    cout << "\nTarget sum k = " << k << endl;

    cout << "Longest Subarray (Brute Force): " << longestSubarrayBruteForce(arr, k) << endl;
    cout << "Longest Subarray (Hash Map):     " << longestSubarrayWithSumK(arr, k) << endl;
    cout << "Longest Subarray (Two Pointers): " << longestSubarrayPositivesOnly(arr, k) << endl;

    return 0;
}