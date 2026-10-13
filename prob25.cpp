/**
 * ============================================================================
 * PROBLEM: Longest Consecutive Sequence in an Array
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an unsorted array of integers `nums`, return the length of the 
 *    longest consecutive elements sequence.
 *    You must write an algorithm that runs in O(N) time.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Brute Force Approach (Linear Search for Successors):
 *        • Time Complexity:  O(N^2) - For each element, search for x + 1, x + 2 linearly
 *        • Space Complexity: O(1)
 *    - 2. Better Approach (Sorting):
 *        • Time Complexity:  O(N log N) - Sorting takes O(N log N), followed by O(N) scan
 *        • Space Complexity: O(1) or O(N) depending on sorting implementation
 *    - 3. Optimal Approach (Unordered Set - Strict O(N) Time):
 *        • Time Complexity:  O(N) average - Each element is visited at most twice
 *        • Space Complexity: O(N) auxiliary space for the hash set
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why does the Unordered Set approach run in O(N) and not O(N^2)?
 *    - The inner `while` loop runs ONLY when `(it - 1)` is NOT in the set.
 *    - This guarantees that streak counting ONLY starts at the beginning of a sequence.
 *    - Each element in any sequence is visited at most twice across the entire algorithm.
 * 
 * 2. How are duplicate numbers handled?
 *    - In the sorting approach: adjacent identical numbers (`nums[i] == nums[i-1]`) are skipped.
 *    - In the set approach: `unordered_set` inherently eliminates duplicates.
 * 
 * 3. What if hash collisions occur in `unordered_set`?
 *    - In adversarial test cases, `unordered_set` can degrade to O(N^2) if anti-hash inputs
 *      cause O(N) bucket collisions. In competitive programming, a custom hash or `std::set`
 *      (O(N log N)) is used if collision attacks are expected.
 * 
 * 4. What if the array is empty?
 *    - If `nums.empty()`, return 0 immediately.
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
// 1. BRUTE FORCE APPROACH: Linear Search for Successors
// Time Complexity: O(N^2) | Space Complexity: O(1)
// ============================================================================

bool linearSearch(const vector<int> &arr, int num) {
    for (int x : arr) {
        if (x == num) return true;
    }
    return false;
}

int longestConsecutiveBrute(const vector<int> &arr) {
    int n = arr.size();
    if (n == 0) return 0;

    int longest = 1;
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        int cnt = 1;
        while (linearSearch(arr, x + 1)) {
            x++;
            cnt++;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

// ============================================================================
// 2. BETTER APPROACH: Sorting
// Time Complexity: O(N log N) | Space Complexity: O(1)
// ============================================================================

int longestConsecutiveSort(vector<int> nums) {
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
// 3. OPTIMAL APPROACH: Unordered Set (Strictly O(N) Time)
// Time Complexity: O(N) average | Space Complexity: O(N)
// ============================================================================

int longestSuccessiveElements(const vector<int> &a) {
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;

    // Step 1: Insert all elements into unordered_set
    for (int x : a) {
        st.insert(x);
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
// DRIVER CODE
// ============================================================================

int main() {
    vector<int> a = {100, 4, 200, 1, 3, 2};

    cout << "Array elements: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    cout << "Longest Consecutive Length (Brute Force): " << longestConsecutiveBrute(a) << endl;
    cout << "Longest Consecutive Length (Sorting):     " << longestConsecutiveSort(a) << endl;
    cout << "Longest Consecutive Length (Optimal Set): " << longestSuccessiveElements(a) << endl;

    return 0;
}