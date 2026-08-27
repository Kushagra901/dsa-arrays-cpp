/**
 * ============================================================================
 * PROBLEM: Merge Overlapping Subintervals
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of intervals where `intervals[i] = [start_i, end_i]`, 
 *    merge all overlapping intervals, and return an array of the non-overlapping 
 *    intervals that cover all the intervals in the input.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Optimal Approach (Sort by Start Time + Single Linear Pass):
 *        • Time Complexity:  O(N log N) for sorting + O(N) for merging = O(N log N)
 *        • Space Complexity: O(N) to store merged intervals (or O(1) auxiliary)
 *    - Brute Force Approach (Check all interval overlaps with nested loop):
 *        • Time Complexity:  O(N^2)
 *        • Space Complexity: O(N)
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why is sorting by start time `intervals[i][0]` essential?
 *    - Sorting guarantees that if an interval overlaps with any previous interval, 
 *      it MUST overlap with the most recently added interval in the merged list (`ans.back()`).
 *      This reduces the search space from O(N) to O(1)!
 * 
 * 2. How do you merge intervals in a single pass?
 *    - If `ans.empty() || arr[i][0] > ans.back()[1]`: No overlap, push as a new interval.
 *    - Else: Overlap detected! Extend the end time: `ans.back()[1] = max(ans.back()[1], arr[i][1])`.
 * 
 * 3. What is the Insert Interval problem (LeetCode 57)?
 *    - Insert a new interval into an already sorted list of non-overlapping intervals 
 *      in O(N) time without re-sorting.
 * 
 * 4. What is the Meeting Rooms II problem (LeetCode 253 / Minimum Platforms)?
 *    - Find the minimum number of conference rooms required for overlapping meeting intervals 
 *      using a Min-Heap (or sorting start/end times separately).
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 56: Merge Intervals (Medium)
 * 2. LeetCode 57: Insert Interval (Medium)
 * 3. LeetCode 252: Meeting Rooms (Easy)
 * 4. LeetCode 253: Meeting Rooms II (Medium)
 * 5. GeeksforGeeks: Overlapping Intervals (Medium)
 * 6. Coding Ninjas: Merge Overlapping Subintervals (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// OPTIMAL APPROACH: Sorting + Linear Greedy Merge
// Time Complexity: O(N log N) | Space Complexity: O(N)
// ============================================================================

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); 
    if (n <= 1) return arr;

    // Step 1: Sort all intervals based on their start times
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    // Step 2: Traverse through sorted intervals and merge
    for (int i = 0; i < n; i++) {
        // If ans is empty or current interval does not overlap with previous interval
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // If current interval overlaps with previous interval, extend the end time
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};

    cout << "Original Intervals: ";
    for (const auto &it : arr) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> ans = mergeOverlappingIntervals(arr);

    cout << "Merged Non-Overlapping Intervals: ";
    for (const auto &it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    return 0;
}
