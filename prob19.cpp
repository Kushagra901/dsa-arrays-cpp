/**
 * ============================================================================
 * PROBLEM: Majority Element (> N/2 Times) - Moore's Voting Algorithm
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array `v` of size `n`, find the majority element that appears 
 *    strictly more than `⌊n / 2⌋` times.
 *    If no such element exists, return `-1`.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Moore's Voting Algorithm):
 *        • Time Complexity:  O(N) + O(N) = O(2N) = O(N) (Pass 1 find candidate, Pass 2 verify)
 *        • Space Complexity: O(1) - Constant auxiliary space
 *    - Hash Map Approach:
 *        • Time Complexity:  O(N)
 *        • Space Complexity: O(N) - Extra space for frequency map
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why does Moore's Voting Algorithm work?
 *    - The majority element occurs > N/2 times. If we pair every occurrence of the
 *      majority element with a different non-majority element, the majority element
 *      will STILL have at least one unmatched element remaining at the end!
 * 
 * 2. Why is the second verification pass mandatory in general?
 *    - If the problem statement DOES NOT GUARANTEE that a majority element exists,
 *      Moore's voting algorithm will still output a candidate. The second pass 
 *      verifies if `count(candidate) > n / 2`.
 *    - If the problem guarantees a majority element (like LeetCode 169), the second pass can be omitted.
 * 
 * 3. How does this generalize to finding elements appearing > N/k times?
 *    - For `> N/k`, there can be at most `(k - 1)` majority candidates.
 *    - Maintain `(k - 1)` candidate variables and counters (e.g. Majority Element II for > N/3 uses 2 candidates).
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 169: Majority Element (Easy)
 * 2. LeetCode 229: Majority Element II (> N/3 times) (Medium)
 * 3. GeeksforGeeks: Majority Element (Medium)
 * 4. Coding Ninjas: Majority Element (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Boyer-Moore Voting Algorithm
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================

int majorityElement(const vector<int> &v) {
    int cnt = 0;
    int el = -1; // Candidate element

    // Step 1: Apply Moore's Voting Algorithm to find candidate
    for (int i = 0; i < (int)v.size(); i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i]; // Choose current element as new candidate
        }
        else if (v[i] == el) {
            cnt++; // Vote for candidate
        }
        else {
            cnt--; // Vote against candidate
        }
    }

    // Step 2: Verification pass (check if candidate occurs > n/2 times)
    int cnt1 = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > ((int)v.size() / 2)) {
        return el;
    }
    return -1; // No majority element found
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4, 1, 1, 1, 1, 1};

    cout << "Array elements: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    int result = majorityElement(v);

    if (result != -1) {
        cout << "Majority element (> n/2): " << result << endl;
    } else {
        cout << "No majority element exists" << endl;
    }

    return 0;
}