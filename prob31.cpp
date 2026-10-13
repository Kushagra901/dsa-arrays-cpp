/**
 * ============================================================================
 * PROBLEM: Majority Element II (> N/3 Times) - Extended Boyer-Moore Voting
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an integer array `v` of size `n`, find all elements that appear 
 *    strictly more than `⌊n / 3⌋` times.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Extended Boyer-Moore Voting Algorithm):
 *        • Time Complexity:  O(N) + O(N) = O(2N) = O(N) (Pass 1 find up to 2 candidates, Pass 2 verify)
 *        • Space Complexity: O(1) auxiliary space (returns at most 2 elements)
 *    - Hash Map Approach:
 *        • Time Complexity:  O(N)
 *        • Space Complexity: O(N) auxiliary space
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why can there be AT MOST 2 majority elements appearing strictly > N/3 times?
 *    - If there were 3 elements each appearing > N/3 times, their combined count 
 *      would be > 3 * (N / 3) = N, which exceeds the total array size N!
 *      In general, for > N / k, there can be at most (k - 1) candidates.
 * 
 * 2. Why must we check `el2 != v[i]` when assigning `el1`, and `el1 != v[i]` when assigning `el2`?
 *    - If both candidates were set to the same value, they would compete against each other
 *      and miscount identical elements.
 * 
 * 3. Why is the second verification pass strictly mandatory here?
 *    - The voting algorithm provides candidate elements, but cannot guarantee whether they 
 *      actually appear > floor(N / 3) times. We must count their exact occurrences in Pass 2.
 * 
 * 4. What if no element appears > N/3 times?
 *    - The function returns an empty list `[]`.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 229: Majority Element II (Medium)
 * 2. LeetCode 169: Majority Element (Easy)
 * 3. GeeksforGeeks: Majority Vote (> n/3) (Medium)
 * 4. Coding Ninjas: Majority Element - II (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Extended Boyer-Moore Voting Algorithm
// Time Complexity: O(N) | Space Complexity: O(1) auxiliary
// ============================================================================

vector<int> majorityElement(const vector<int> &v) {
    int n = v.size();

    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;

    // Step 1: Extended Boyer-Moore Voting to find up to 2 candidates
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i]) {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1) {
            cnt1++;
        }
        else if (v[i] == el2) {
            cnt2++;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }

    // Step 2: Verification pass to confirm counts > n / 3
    vector<int> ls;
    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }

    int threshold = (n / 3);
    if (cnt1 > threshold) ls.push_back(el1);
    if (cnt2 > threshold) ls.push_back(el2);
    sort(ls.begin(), ls.end()); 
    return ls;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> arr = {11, 33, 33, 11, 33, 11};

    cout << "Array elements: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    vector<int> ans = majorityElement(arr);

    cout << "Majority elements (> n/3): ";
    for (int it : ans) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}