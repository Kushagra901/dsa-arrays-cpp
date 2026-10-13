/**
 * ============================================================================
 * PROBLEM: Merge Overlapping Subintervals
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Given an array of `intervals` where `intervals[i] = [start_i, end_i]`, 
 *    merge all overlapping intervals, and return an array of the 
 *    non-overlapping intervals that cover all the intervals in the input.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Brute Force Approach (Sorting + Nested Lookahead):
 *        • Time Complexity:  O(N log N) + O(N^2) = O(N^2)
 *        • Space Complexity: O(N) auxiliary space for result
 *    - 2. Optimal Approach (Sorting + Linear Greedy Merge):
 *        • Time Complexity:  O(N log N) - Sorting intervals + O(N) single pass merge
 *        • Space Complexity: O(N) - Storage for merged intervals list
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Why do we sort intervals by their start times?
 *    - Sorting guarantees that if an interval overlaps with any previous interval,
 *      it must overlap with the latest (most recently added) interval in our answer list.
 * 
 * 2. How do we determine if two intervals [s1, e1] and [s2, e2] overlap (assuming s1 <= s2)?
 *    - They overlap if and only if `s2 <= e1`.
 *    - The merged interval will have start `s1` and end `max(e1, e2)`.
 * 
 * 3. What if intervals are already sorted?
 *    - The algorithm becomes pure O(N) linear time.
 * 
 * 4. What is the follow-up: "Insert Interval" (LeetCode 57)?
 *    - Insert a new interval into an already sorted list of non-overlapping intervals
 *      and merge if necessary in O(N) time without full re-sorting.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 56: Merge Intervals (Medium)
 * 2. LeetCode 57: Insert Interval (Medium)
 * 3. LeetCode 435: Non-overlapping Intervals (Medium)
 * 4. GeeksforGeeks: Overlapping Intervals (Medium)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// 1. BRUTE FORCE APPROACH: Sorting + Nested Interval Search
// Time Complexity: O(N log N) + O(N^2) | Space Complexity: O(N)
// ============================================================================

vector<vector<int>> mergeOverlappingIntervalsBrute(vector<vector<int>> &arr) {
    int n = arr.size();
    if (n <= 1) return arr;

    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        int start = arr[i][0];
        int end = arr[i][1];

        // Skip if current interval is already covered by previous merged interval
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        // Check for subsequent overlapping intervals
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            } else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

// ============================================================================
// 2. OPTIMAL APPROACH: Sorting + Linear Greedy Merge
// Time Complexity: O(N log N) | Space Complexity: O(N)
// ============================================================================

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); 
    if (n <= 1) return arr;

    // Step 1: Sort all intervals based on their start times
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    // Step 2: Traverse through sorted intervals and merge in a single pass
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

    cout << "Merged Non-Overlapping Intervals (Optimal): ";
    for (const auto &it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    return 0;
}