/**
 * ============================================================================
 * PROBLEM: Count Subarrays with Given Sum K (Subarray Sum Equals K)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of integers `arr` and an integer `k`, find the total number 
 *    of contiguous subarrays whose sum equals `k`.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Prefix Sum + Hash Map Frequency Table):
 *        • Time Complexity:  O(N) average with `unordered_map`
 *        • Space Complexity: O(N) to store prefix sum frequencies in map
 *    - Brute Force Approach (All Subarrays):
 *        • Time Complexity:  O(N^2)
 *        • Space Complexity: O(1)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why do we initialize `mpp[0] = 1` before starting the loop?
 *    - If a subarray starting at index 0 has prefix sum equal to `k`, then 
 *      `preSum - k = 0`. `mpp[0] = 1` ensures this entire prefix subarray is counted!
 * 
 * 2. Why does the Two-Pointer / Sliding Window method FAIL for this problem?
 *    - Sliding window requires monotonicity (expanding increases sum, shrinking decreases it).
 *      If the array contains negative numbers or zeroes, expanding/shrinking does not guarantee 
 *      monotonic sum changes. Hence, Prefix Sum + Hash Map is the only linear O(N) solution.
 * 
 * 3. What if the array elements are strictly positive?
 *    - If all numbers are positive, Sliding Window (Two Pointers) can achieve O(N) time with O(1) space.
 * 
 * 4. How does this compare with LeetCode 930 (Binary Subarrays With Sum) and LeetCode 1248 (Count Nice Subarrays)?
 *    - Both can be solved using this exact Prefix Sum HashMap template, or transformed into sliding window with exact `atMost(k) - atMost(k - 1)`.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 560: Subarray Sum Equals K (Medium)
 * 2. LeetCode 930: Binary Subarrays With Sum (Medium)
 * 3. LeetCode 1248: Count Number of Nice Subarrays (Medium)
 * 4. GeeksforGeeks: Subarrays with sum K (Medium)
 * 5. Coding Ninjas: Subarray Sum Equals K (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Prefix Sum + Hash Map Frequency Counting
// Time Complexity: O(N) | Space Complexity: O(N)
// ============================================================================

int findAllSubarraysWithGivenSum(const vector<int> &arr, int k) {
    int n = arr.size();
    unordered_map<int, int> mpp; // {prefixSum -> count of occurrences}
    int preSum = 0;
    int cnt = 0;

    mpp[0] = 1; // Base case: prefix sum of 0 has occurred once

    for (int i = 0; i < n; i++) {
        // Step 1: Add current element to running prefix sum
        preSum += arr[i];

        // Step 2: Determine how much prefix sum needs to be removed
        int remove = preSum - k;

        // Step 3: If (preSum - k) exists in map, add its frequency to total count
        if (mpp.find(remove) != mpp.end()) {
            cnt += mpp[remove];
        }

        // Step 4: Record/increment current prefix sum frequency
        mpp[preSum] += 1;
    }

    return cnt;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;

    cout << "Array elements: ";
    for (int x : arr) cout << x << " ";
    cout << "\nTarget sum k: " << k << endl;

    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays with sum " << k << " is: " << cnt << endl;

    return 0;
}