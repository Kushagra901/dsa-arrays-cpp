/**
 * ============================================================================
 * PROBLEM: Count Subarrays with Given XOR K
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of integers `a` and an integer `k`, find the total number 
 *    of contiguous subarrays having bitwise XOR of their elements equal to `k`.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Prefix XOR + Hash Map Frequency Table):
 *        • Time Complexity:  O(N) average with `unordered_map` (or O(N log N) with `map`)
 *        • Space Complexity: O(N) auxiliary space for hash map
 *    - Brute Force Approach (All Subarrays):
 *        • Time Complexity:  O(N^2)
 *        • Space Complexity: O(1)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. What is the mathematical principle behind Prefix XOR?
 *    - Let XR be the prefix XOR from index 0 to i.
 *    - If a subarray from (j + 1) to i has XOR equal to k, then:
 *        X ^ k = XR  =>  X = XR ^ k
 *      where X is the prefix XOR from index 0 to j.
 *    - Therefore, searching for (XR ^ k) in the hash map gives the count of valid subarrays ending at i!
 * 
 * 2. Why do we initialize `mpp[0] = 1` (or `mpp[xr]++` at the start)?
 *    - If XR == k, then XR ^ k = 0. Having `mpp[0] = 1` accounts for the 
 *      entire prefix subarray from index 0 to i.
 * 
 * 3. How does this mirror "Subarray Sum Equals K"?
 *    - In sum: `sum - k` is looked up.
 *    - In XOR: `xr ^ k` is looked up (since XOR is its own inverse operation).
 * 
 * 4. What if the elements are non-negative and k == 0?
 *    - It counts all subarrays whose elements cancel each other out to 0.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. InterviewBit: Subarray with given XOR (Medium)
 * 2. GeeksforGeeks: Count Subarrays with given XOR (Medium)
 * 3. Coding Ninjas: Subarrays with XOR 'K' (Medium)
 * 4. LeetCode 560: Subarray Sum Equals K (Medium)
 * 5. LeetCode 1310: XOR Queries of a Subarray (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Prefix XOR + Hash Map Frequency
// Time Complexity: O(N) average | Space Complexity: O(N)
// ============================================================================

int subarrayWithSumK(const vector<int> &a, int k) {
    int xr = 0;
    unordered_map<int, int> mpp; // {prefixXOR -> frequency}
    mpp[0] = 1;                  // Base case: prefix XOR of 0 occurs once initially
    int cnt = 0;

    for (int i = 0; i < (int)a.size(); i++) {
        // Step 1: Accumulate current element into running prefix XOR
        xr = xr ^ a[i];

        // Step 2: Compute prefix XOR needed (x = xr ^ k)
        int x = xr ^ k;

        // Step 3: Add frequency of x from map
        cnt += mpp[x];

        // Step 4: Record current prefix XOR in map
        mpp[xr]++;
    }

    return cnt;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;

    cout << "Array elements: ";
    for (int x : a) cout << x << " ";
    cout << "\nTarget XOR k: " << k << endl;

    int ans = subarrayWithSumK(a, k);

    cout << "The number of subarrays with XOR " << k << " is: " << ans << endl;

    return 0;
}