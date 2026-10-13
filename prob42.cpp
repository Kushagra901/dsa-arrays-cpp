/**
 * ============================================================================
 * PROBLEM: Count Subarrays with Given XOR K (Multi-Approach Deep Dive)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of integers `arr` and an integer `k`, find the total number 
 *    of contiguous subarrays having bitwise XOR of their elements equal to `k`.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Brute Force Approach (All Subarrays with Inner XOR Loop):
 *        • Time Complexity:  O(N^3) - 3 nested loops computing XOR for all pairs
 *        • Space Complexity: O(1)
 *    - 2. Better Approach (Running XOR in 2 Nested Loops):
 *        • Time Complexity:  O(N^2) - 2 nested loops accumulating XOR
 *        • Space Complexity: O(1)
 *    - 3. Optimal Approach (Prefix XOR + Hash Map):
 *        • Time Complexity:  O(N) average with unordered_map
 *        • Space Complexity: O(N) auxiliary space for frequency hash map
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. What is the mathematical principle behind Prefix XOR?
 *    - If prefix XOR up to index `i` is `xr`, and we want a subarray with XOR `k`,
 *      we need an earlier prefix XOR `x` such that `x ^ k = xr`.
 *    - By XORing both sides by `k`: `x = xr ^ k`.
 *    - Thus, looking up `xr ^ k` in the frequency map gives all valid subarrays ending at `i`.
 * 
 * 2. Why is `mp[0] = 1` initialized before traversing?
 *    - If a subarray starting from index 0 itself has XOR equal to `k`, then `xr ^ k = 0`.
 *      Having `mp[0] = 1` counts this entire prefix subarray properly.
 * 
 * 3. Can this handle k = 0?
 *    - Yes, finding subarrays where elements cancel each other out to 0 (neutral identity).
 * 
 * 4. What is the difference between this and "Subarray Sum Equals K"?
 *    - In sum: `sum - k` is looked up. In XOR: `xr ^ k` is looked up because XOR is
 *      its own self-inverse (`a ^ b = c <=> a = c ^ b`).
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. InterviewBit: Subarray with given XOR (Medium)
 * 2. LeetCode 560: Subarray Sum Equals K (Medium)
 * 3. LeetCode 1310: XOR Queries of a Subarray (Medium)
 * 4. GeeksforGeeks: Count Subarrays with given XOR (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ============================================================================
// 1. BRUTE FORCE APPROACH: 3 Nested Loops
// Time Complexity: O(N^3) | Space Complexity: O(1)
// ============================================================================

int subarrayWithXorBrute(const vector<int> &arr, int k) {
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int xr = 0;
            for (int K = i; K <= j; K++) {
                xr ^= arr[K];
            }
            if (xr == k) cnt++;
        }
    }
    return cnt;
}

// ============================================================================
// 2. BETTER APPROACH: Running XOR in 2 Nested Loops
// Time Complexity: O(N^2) | Space Complexity: O(1)
// ============================================================================

int subarrayWithXorBetter(const vector<int> &arr, int k) {
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int xr = 0;
        for (int j = i; j < n; j++) {
            xr ^= arr[j];
            if (xr == k) cnt++;
        }
    }
    return cnt;
}

// ============================================================================
// 3. OPTIMAL APPROACH: Prefix XOR + Hash Map
// Time Complexity: O(N) average | Space Complexity: O(N)
// ============================================================================

int subarrayWithXorOptimal(const vector<int> &arr, int k) {
    int n = arr.size();
    int xr = 0;
    unordered_map<int, int> mp;
    mp[0] = 1; // Base condition: prefix XOR of 0 has frequency 1
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        xr = xr ^ arr[i];        // Running prefix XOR
        int x = xr ^ k;          // Target prefix XOR needed
        cnt += mp[x];            // Add count of matching prefix XORs
        mp[xr]++;                // Store current prefix XOR frequency
    }
    return cnt;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;

    cout << "Array elements: ";
    for (int x : arr) cout << x << " ";
    cout << "\nTarget XOR k: " << k << endl;

    cout << "Subarrays with XOR " << k << " (Brute Force): " << subarrayWithXorBrute(arr, k) << endl;
    cout << "Subarrays with XOR " << k << " (Better):      " << subarrayWithXorBetter(arr, k) << endl;
    cout << "Subarrays with XOR " << k << " (Optimal):     " << subarrayWithXorOptimal(arr, k) << endl;

    return 0;
}