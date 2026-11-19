"""
============================================================================
PROBLEM: Merge Overlapping Subintervals
============================================================================

📌 PROBLEM DESCRIPTION:
   Given an array of intervals where `intervals[i] = [start_i, end_i]`, merge 
   all overlapping intervals, and return an array of the non-overlapping 
   intervals that cover all the intervals in the input.

💡 COMPLEXITY ANALYSIS:
   - 1. Optimal Approach (Sorting + Greedy Single Pass):
       • Time Complexity:  O(N log N) - Sorting intervals by start time + O(N) linear scan
       • Space Complexity: O(N) to store merged intervals
   - 2. Brute Force Approach (Sorting + Nested Interval Search):
       • Time Complexity:  O(N log N) + O(N^2)
       • Space Complexity: O(N)

----------------------------------------------------------------------------
🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
----------------------------------------------------------------------------
1. Why does sorting by `start` time make the greedy merge optimal?
   - Sorting guarantees that if interval `B` starts after interval `A`, 
     `B` can only overlap with `A` if `B.start <= A.end`.
     We never have to look back further than the most recently merged interval!

----------------------------------------------------------------------------
🔗 SIMILAR PROBLEMS FOR PRACTICE:
----------------------------------------------------------------------------
1. LeetCode 56: Merge Intervals (Medium)
2. LeetCode 57: Insert Interval (Medium)
3. GeeksforGeeks: Overlapping Intervals (Medium)
============================================================================
"""

from typing import List


# ============================================================================
# 1. OPTIMAL APPROACH: Sort by Start Time + Greedy Merge
# Time Complexity: O(N log N) | Space Complexity: O(N)
# ============================================================================

def merge_overlapping_intervals(arr: List[List[int]]) -> List[List[int]]:
    """Merges all overlapping intervals in O(N log N) time."""
    n = len(arr)
    if n <= 1:
        return arr[:]

    # Step 1: Sort intervals by start time
    intervals = sorted(arr, key=lambda x: x[0])
    ans: List[List[int]] = []

    # Step 2: Iterate and merge greedily
    for interval in intervals:
        if not ans or interval[0] > ans[-1][1]:
            ans.append(interval[:])
        else:
            ans[-1][1] = max(ans[-1][1], interval[1])

    return ans


# ============================================================================
# 2. BRUTE FORCE APPROACH: Sorting + Nested Interval Search
# Time Complexity: O(N log N) + O(N^2) | Space Complexity: O(N)
# ============================================================================

def merge_overlapping_intervals_brute(arr: List[List[int]]) -> List[List[int]]:
    """Brute force approach checking nested intervals."""
    n = len(arr)
    if n <= 1:
        return arr[:]

    intervals = sorted(arr, key=lambda x: x[0])
    ans: List[List[int]] = []

    for i in range(n):
        start = intervals[i][0]
        end = intervals[i][1]

        if ans and end <= ans[-1][1]:
            continue

        for j in range(i + 1, n):
            if intervals[j][0] <= end:
                end = max(end, intervals[j][1])
            else:
                break

        ans.append([start, end])

    return ans


# C++ Aliases
mergeOverlappingIntervals = merge_overlapping_intervals
mergeOverlappingIntervalsBrute = merge_overlapping_intervals_brute


# ============================================================================
# DRIVER CODE
# ============================================================================

if __name__ == "__main__":
    intervals = [
        [1, 3],
        [2, 6],
        [8, 10],
        [15, 18]
    ]

    print("Original Intervals:")
    for interval in intervals:
        print(f"[{interval[0]}, {interval[1]}]", end=" ")
    print()

    merged = merge_overlapping_intervals(intervals)

    print("\nMerged Overlapping Intervals:")
    for interval in merged:
        print(f"[{interval[0]}, {interval[1]}]", end=" ")
    print()
