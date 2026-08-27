/**
 * ============================================================================
 * PROBLEM: Longest Subarray with Sum K (Positives, Zeroes, and Negatives)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array `a` of `n` integers (which may contain positive, zero, 
 *    and negative numbers) and a target sum `k`, find the length of the longest 
 *    contiguous subarray that sums up to `k`.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal for Arrays with Positives, Zeroes & Negatives (Prefix Sum + Hash Map):
 *        • Time Complexity:  O(N * log N) with `std::map` or O(N) average with `std::unordered_map`
 *        • Space Complexity: O(N) for storing prefix sums in the map
 *    - Optimal for Arrays with ONLY Positives & Zeroes (Two Pointers / Sliding Window):
 *        • Time Complexity:  O(2N) = O(N)
 *        • Space Complexity: O(1)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why do we store only the FIRST occurrence of a prefix sum in `preSumMap`?
 *    - Because we want the LONGEST subarray! Storing an earlier index for a given
 *      prefix sum maximizes `(i - preSumMap[rem])`.
 * 
 * 2. Why does the Two-Pointer / Sliding Window approach fail with negative numbers?
 *    - With only positive numbers, shrinking the window monotonically decreases the sum,
 *      and expanding increases it. Negative numbers destroy monotonicity.
 * 
 * 3. How does `rem = sum - k` find the target subarray?
 *    - If prefixSum up to index `i` is `sum`, and there exists an earlier prefixSum equal
 *      to `sum - k` at index `j`, then the subarray from `j + 1` to `i` has sum `k`.
 * 
 * 4. What if the entire prefix from index 0 to i sums to k?
 *    - Directly update `maxLen = max(maxLen, i + 1)`.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 560: Subarray Sum Equals K (Medium)
 * 2. LeetCode 325: Maximum Size Subarray Sum Equals k (Medium)
 * 3. GeeksforGeeks: Longest Sub-Array with Sum K (Medium)
 * 4. Coding Ninjas: Longest Subarray With Sum K (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Prefix Sum + Hash Map (Handles Positives, Negatives & Zeroes)
// Time Complexity: O(N) average with unordered_map | Space Complexity: O(N)
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
// TWO POINTER APPROACH: (Optimal for Strictly Positives & Zeroes)
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
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    long long k = 3;

    cout << "Array elements: ";
    for (int x : arr) cout << x << " ";
    cout << "\nTarget sum k = " << k << endl;

    int result = longestSubarrayWithSumK(arr, k);

    cout << "Longest Subarray Length with Sum " << k << " is: " << result << endl;

    return 0;
}