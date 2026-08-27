/**
 * ============================================================================
 * PROBLEM: Longest Consecutive Sequence in an Array
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an unsorted array of integers `a`, find the length of the longest 
 *    consecutive elements sequence (e.g. `[1, 2, 3, 4]`).
 *    The algorithm must run in O(N) time.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Hash Set - Only start from streak beginnings):
 *        • Time Complexity:  O(N) + O(2N) = O(3N) = O(N) average time with `unordered_set`
 *        • Space Complexity: O(N) - Storing unique elements in the hash set
 *    - Better Approach (Sorting):
 *        • Time Complexity:  O(N log N) - Sorting the array
 *        • Space Complexity: O(1) or O(N)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How does the Hash Set approach achieve strictly O(N) time despite nested loops?
 *    - We ONLY start counting a sequence if `(it - 1)` is NOT in the set!
 *    - This ensures that each number is visited as the start of a streak AT MOST ONCE.
 *      Across the entire array, each element is examined at most twice, yielding linear O(N) amortized time.
 * 
 * 2. Why does sorting take O(N log N) time?
 *    - Sorting easily aligns consecutive numbers, but violates the strict O(N) time 
 *      constraint demanded by LeetCode 128.
 * 
 * 3. What if there are duplicate numbers in the array?
 *    - An `unordered_set` automatically removes duplicates.
 *    - In the sorting approach, duplicates are skipped by checking `if (nums[i] == lastSmaller) continue;`.
 * 
 * 4. What are the edge cases?
 *    - Empty array `[]`: returns 0.
 *    - Array with negative numbers and large gaps: handled seamlessly by hash set.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 128: Longest Consecutive Sequence (Medium)
 * 2. GeeksforGeeks: Longest Consecutive Subsequence (Medium)
 * 3. Coding Ninjas: Longest Consecutive Sequence (Medium)
 * 4. LeetCode 298: Binary Tree Longest Consecutive Sequence (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>

using namespace std;

// ============================================================================
// 1. OPTIMAL APPROACH: Unordered Set (Strictly O(N) Time)
// Time Complexity: O(N) average | Space Complexity: O(N)
// ============================================================================

int longestSuccessiveElements(const vector<int> &a) {
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;

    // Step 1: Insert all elements into unordered_set
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    // Step 2: Find the longest sequence starting only from sequence heads
    for (auto it : st) {
        // If (it - 1) is NOT in set, 'it' is the start of a consecutive sequence
        if (st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;

            // Incrementally find following consecutive numbers
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

// ============================================================================
// 2. BETTER APPROACH: Sorting
// Time Complexity: O(N log N) | Space Complexity: O(1)
// ============================================================================

int longestSuccessiveElementSort(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return 0;

    sort(nums.begin(), nums.end());

    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    for (int i = 0; i < n; i++) {
        if (nums[i] - 1 == lastSmaller) {
            cnt += 1;
            lastSmaller = nums[i]; 
        }
        else if (lastSmaller != nums[i]) {
            cnt = 1;
            lastSmaller = nums[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> a = {100, 200, 1, 2, 3, 4};

    cout << "Array elements: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence length is: " << ans << endl;

    return 0;
}